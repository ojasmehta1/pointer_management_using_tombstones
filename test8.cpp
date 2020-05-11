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
    free(a);
    error("Didn't blow up when releasing uninitialized pointer!");

    return 0;
}
