#include <iostream>
#include <stdlib.h>
#include "tombstones.h"
using namespace std;

void error(const char *data)
{
    cout << "ERROR: " << data << endl;
    exit(-1);
}

Pointer<int> &rec(int n, Pointer<int> a)
{
    static Pointer<int> result(new int(*a));
    if (0 == n)
	return result;
    result = (Pointer<int>&)(rec(n-1, a));
    *result += 1;
    return result;
}

Pointer<int> &recref(int n, Pointer<int> &a)
{
    if (0 == n)
	return a;
    *a += 1;
    return rec(n-1, a);
}

void proc()
{
    Pointer<int> a(new int(0));
    Pointer<int> b(rec(100, a));

    if (*b != 100 || *a != 0)
	error("a or b incorrect after rec()!");

    a = recref(100, b);
    if (*a != 200)
	error("b incorrect after recref()!");
    if (a != b)
	error("a not an alias for b after recref()!");
    free(a);
}

int main(int argc, char **argv)
{
    proc();
    error("Didn't blow up when leaking memory!");

    return 0;
}