#include <iostream>
#include <stdlib.h>
#include "tombstones.h"
using namespace std;

void error(const char *data)
{
    cout << "ERROR: " << data << endl;
    exit(-1);
}

int main(int argc, char **argv)
{
    Pointer<int> a;
    a = new int(12);
    Pointer<int> b(a);

    if (b == 0)
	error("b should not be null!");
    if (*b != 12)
	error("b got the wrong value!");
    if (a != b)
	error("a and b are NOT different pointers!");
    if (*a != *b)
	error("a and b should have the same value here!");
    *a = 15;
    if (*b != 15)
	error("b should still match a!");

    free(a);
    free(b);
    error("Attempt to double-delete pointer not flagged!");

    return 0;
}
