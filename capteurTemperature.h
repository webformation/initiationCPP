#ifndef CAPTEURTEMPERATURE_H_INCLUDED
#define CAPTEURTEMPERATURE_H_INCLUDED
#include <exception>
#include "capteur.h"

extern "C" int thermometre(int num, int code);
class capteurTemperature : public capteur {
private:

public: // pour besoin didactique
    float min;
    float max;
    bool controle = false;
public:
    capteurTemperature(string nom, int num) : capteurTemperature(nom, num,0, 0) {
        controle = false;
    }
    capteurTemperature(string nom, int num, float  min, float  max) : capteur(nom,num+2), min(min), max(max),controle(true) {
        if (thermometre(num,0) < 0) {
            throw capteurErreurInitialisation("echec initialisation du thermometre");
        }

    }
    capteurTemperature(const capteurTemperature & ct) : capteur(ct) {
        controle = ct.controle;

    }
    capteurTemperature & operator=(const capteurTemperature & ct) {
        if (this == &ct)
            return *this;
        if (nom!=nullptr)
            delete nom;
        nom = new string(*(ct.nom));
        num = ct.num;
        min = ct.min;
        max = ct.max;
        controle = ct.controle;
        return *this;
    }
    ~capteurTemperature() {

        thermometre(num,1);

    }
    float getValeur  () override {
        int val;
        if ((val=thermometre(num,2)) < 0) {
            throw capteurErreurLecture("echec lecture du thermometre");
        } else {
            return static_cast<float>(val);
        }
    }
    bool estValide() {
        if (!controle)
            return true;
        float v = getValeur();
        return (v>= min && v <= max);
    }
    bool operator==(const capteurTemperature & ct) noexcept {
        if (this == &ct)
            return true;
        return (capteur::operator==(ct) && controle == ct.controle && min == ct.min && max == ct.max);
    }

    virtual string getNom()  const noexcept override;
    friend ostream & operator<<(ostream & out, const capteurTemperature& c);
};


#endif // CAPTEURTEMPERATURE_H_INCLUDED
