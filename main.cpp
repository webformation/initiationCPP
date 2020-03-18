#include <iostream>

using namespace std;
#include "capteur.h"
#include "capteurTemperature.h"
#include "capteurPression.h"
#include "bloc.h"


int main() {
    capteurTemperature c1("essai",2);
    cout << c1.getNom() << endl;
    cout << boolalpha << c1.estValide() << endl;
    capteurTemperature c2("essai",2);
    cout << "c2 : " <<  c2.getNom() << endl;
    cout << (c1==c2) << endl;
    cout << c2 << endl;
    float mn =20.f,mx =60.f;
    capteurTemperature *pc1 = new capteurTemperature("suite",3,mn,mx);
    cout << *pc1 << endl;
    cout << "Nombre de capteurs : " << pc1->getNb() << endl;
    capteurTemperature c3(c2);
    cout << "Nombre de capteurs : " << capteurTemperature::getNb() << endl;
    c3 = *pc1;
    cout << c3 << endl;
    capteur *cap1 = &c3;
    //cout << *cap1 << endl;
    cout << cap1->getNom() << endl;
    cap1 = new capteurPression("pression1", 10);
    cout << cap1->getNom() << endl;
    bloc b("maison");
    cout << b.getInfo() << endl;
    cout << b.getNbCapteurs() << endl;
    b.addCapteur(cap1);
    b.addCapteur(&c1);
    cout << b.getInfo() << endl;
    cout << b.getNbCapteurs() << endl;
    b.delCapteur(cap1);
    cout << b.getInfo() << endl;
    cout << b.getNbCapteurs() << endl;
    try {
        capteurPression cp1("ab", 10);
    } catch(capteurParametreInvalide ex) {
        cout << ex.what() << endl;
    } catch(exceptionCapteur ex) {
        cout << "Probleme capteur (non gere)" << endl;
    }
    return 0;
}
