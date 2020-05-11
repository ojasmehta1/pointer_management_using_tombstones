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
    Pointer<int> a(new int(12));
    Pointer<int> temp((int*)NULL);
    Pointer<int> b = temp;

    if (a == 0)
	error("a should not be null!");
    if (b != 0)
	error("b should be null!");
    b = new int(12);
    if (a == b)
	error("a and b are different pointers!");
    if (*a != *b)
	error("a and b have the same value here!");

    free(a);
    free(b);
    cout << "test1: OK" << endl;
    return 0;
}
