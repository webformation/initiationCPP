#include <iostream>

using namespace std;
#include "capteurTemperature.h"


int main()
{
    capteurTemperature c1("essai",2);
    cout << *(c1.nom) << endl;
    return 0;
}
