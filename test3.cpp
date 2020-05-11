#include <iostream>
#include <stdlib.h>
#include "tombstones.h"
using namespace std;

void error(const char *data)
{
    cout << "ERROR: " << data << endl;
    exit(-1);
}

typedef struct combine
{
    int a;
    int b;
    combine(int x, int y) : a(x), b(y) {}
}
twoints;

int main(int argc, char **argv)
{
    Pointer<int> x(new int(12));
    Pointer<twoints> y(new twoints(12,12));

    if (*x != y->a || *x != y->b)
	error("x, y->a, and y->b should all be 12");
    free(x);
    free(y);
    cout << "test3: OK" << endl;
    return 0;
}
