#include <iostream>
#include <stdlib.h>
#include "tombstones.h"

using namespace std;

void error(const char *data)
{
    cout << "ERROR: " << data << endl;
    exit(-1);
}

void sub(Pointer<int> &a)
{
    Pointer<int> b(a);
    Pointer<int> c(b);
    Pointer<int> d(c);
    Pointer<int> e(d);

    *e = 100;
    if (*a != 100)
	error("Linking of pointers not correct!");
    free(e);
}

int main(int argc, char **argv)
{
    Pointer<int> a(new int(0));
    sub(a);
    *a = 1000;
    error("Didn't complain about use of dangling pointer a!");

    return 0;
}
