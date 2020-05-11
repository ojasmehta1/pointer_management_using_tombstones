#include <iostream>
#include <stdlib.h>
#include "tombstones.h"
using namespace std;

void error(const char *data)
{
    cout << "ERROR: " << data << endl;
    exit(-1);
}

void func(Pointer<int> &a, int n)
{
    Pointer<int> b(a);
    if (n == 0)
	*b = 100;
    else
    {
	func(b, n-1);
	if (n == 10)
	{
	    if (*a != 100)
		error("Linking of pointers not correct!");
	    free(a);
	}
    }
}

int main(int argc, char **argv)
{
    Pointer<int> a(new int(0));
    func(a, 10);
    Pointer<int> b(a);
    error("Didn't complain about use of dangling pointer a!");

    return 0;
}
