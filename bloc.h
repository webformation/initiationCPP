#ifndef BLOC_H_INCLUDED
#define BLOC_H_INCLUDED
#include "capteur.h"
#include <vector>
#include <sstream>
#include <algorithm>
class bloc {
    string nom;
    vector<capteur *> capteurs;
public:
    bloc(string nom) : nom(nom) {}
    void addCapteur(capteur *c) {
        capteurs.push_back(c);
    }
    void delCapteur(capteur *c) {
        auto it = find(capteurs.begin(), capteurs.end(), c);
        if (it != capteurs.end()) {
            capteurs.erase(it);
        }

    }
    int getNbCapteurs() {
        return capteurs.size();
    }
    string getInfo() {
        string txt = nom + "\n";
        for (auto &x : capteurs) {
            stringstream s;
            s << x->getNom() << " ";
            txt += s.str() + "; ";
        }
        return txt;
    }
};


#endif // BLOC_H_INCLUDED
