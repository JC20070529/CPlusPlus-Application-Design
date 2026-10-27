#include <iostream>
#include "recordtools.h"

using namespace std;

int main()
{
    addRecord();

    displayRecord();

    cout << "Calculated Result: "
        << calculateResult() << endl;

    return 0;
}


