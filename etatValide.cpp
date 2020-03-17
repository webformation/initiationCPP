#include <iostream>

using namespace std;
#include "etatValide.h"

ostream & operator<<(ostream & o, etatValide e) {
    switch(e) {
    case etatValide::infMinimum:
        o << "Sous le minimum ";
    case etatValide::supMaximum:
        o << "Au dessus du maximum ";
    case etatValide::valide:
            o << "valide ";
        return o;
    }
}
