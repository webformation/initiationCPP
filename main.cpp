#include <iostream>

using namespace std;
#include "capteurTemperature.h"


int main()
{
    capteurTemperature c1("essai",2);
    cout << *(c1.nom) << endl;
    cout << boolalpha << c1.estValide() << endl;
    capteurTemperature c2("essai",2);
    cout << "c2 : " <<  *(c2.nom) << endl;
    cout << (c1==c2) << endl;
    cout << c2 << endl;
    capteurTemperature *pc1 = new capteurTemperature("suite",3,20,60);
    cout << *pc1 << endl;
    cout << "Nombre de capteurs : " << pc1->getNb() << endl;
    capteurTemperature c3(c2);
    cout << "Nombre de capteurs : " << capteurTemperature::getNb() << endl;
    return 0;
}
