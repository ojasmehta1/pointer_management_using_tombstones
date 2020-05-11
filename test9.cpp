#include <iostream>
#include <stdlib.h>
#include "tombstones.h"
using namespace std;

void error(const char *data)
{
    cout << "ERROR: " << data << endl;
    exit(-1);
}

void declare()
{
    Pointer<int> a(new int(12));
}

int main(int argc, char **argv)
{
    declare();
    error("Didn't blow up when leaking memory!");

    return 0;
}
