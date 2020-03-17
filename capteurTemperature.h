#ifndef CAPTEURTEMPERATURE_H_INCLUDED
#define CAPTEURTEMPERATURE_H_INCLUDED
#include <exception>
#include "etatValide.h"

extern "C" int thermometre(int num, int code);
class capteurTemperature
{
public: // pour besoin didactique
    string *nom = nullptr;
    int num;
    float min;
    float max;
    bool controle = false;
public:
    capteurTemperature(string nom, int num) : capteurTemperature(nom, num,0, 0)
    {
        controle = false;
    }
    capteurTemperature(string nom, int num, float min, float max) : num(num), min(min), max(max),controle(true)
    {
        if (nom.size() < 3)
        {
            throw invalid_argument("le nom doit contenir au moins 3 caracteres");
        }
        this->nom = new string(nom);
        if (thermometre(num,0) < 0)
        {
            throw runtime_error("echec initialisation du thermometre");
        }
    }
    ~capteurTemperature()
    {
        if (nom != nullptr)
        {
            delete nom;
        }
        thermometre(num,1);
    }
    float getValeur() {
        int val;
        if ((val=thermometre(num,2)) < 0)
        {
            throw runtime_error("echec lecture du thermometre");
        }
        else {
            return static_cast<float>(val);
        }
    }
    etatValide estValide() {
        if (!controle) return etatValide::valide;
        float v = getValeur();
        if (v < min) return etatValide::infMinimum;
        if (v > max) return etatValide::supMaximum;
        return etatValide::valide;
    }
    bool operator==(const capteurTemperature & ct) {
        if (this == &ct) return true;
        return (*nom == *(ct.nom) && num==ct.num);
    }
    string getNom() const { return *nom;}
    friend ostream & operator<<(ostream & out, const capteurTemperature& c);
};


#endif // CAPTEURTEMPERATURE_H_INCLUDED
