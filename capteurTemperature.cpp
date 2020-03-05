#include <iostream>

using namespace std;
#include "capteurTemperature.h"

ostream & operator<<(ostream & out, const capteurTemperature& c) {
    out << c.getNom() << ", num = " << c.num;
    if (c.controle) {
        out << ", min = " << c.min << ", max = " << c.max ;
    }
return out;}
