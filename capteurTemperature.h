#ifndef CAPTEURTEMPERATURE_H_INCLUDED
#define CAPTEURTEMPERATURE_H_INCLUDED
#include <exception>
#include "capteur.h"

extern "C" int thermometre(int num, int code);
template <typename R> class capteurTemperature : public capteur<R> {
private:

public: // pour besoin didactique
    R min;
    R max;
    bool controle = false;
public:
    capteurTemperature(string nom, int num) : capteurTemperature(nom, num,0, 0) {
        controle = false;
    }
    capteurTemperature(string nom, int num, R  min, R  max) : capteur<R>(nom,num+2), min(min), max(max),controle(true) {
        if (thermometre(num,0) < 0) {
            throw capteurErreurInitialisation("echec initialisation du thermometre");
        }

    }
    capteurTemperature(const capteurTemperature & ct) : capteur<R>(ct) {
        controle = ct.controle;

    }
    capteurTemperature<R> & operator=(const capteurTemperature<R> & ct) {
        if (this == &ct)
            return *this;
        if (this->nom!=nullptr)
            delete this->nom;
        this->nom = new string(*(ct.nom));
        this->num = ct.num;
        min = ct.min;
        max = ct.max;
        controle = ct.controle;
        return *this;
    }
    ~capteurTemperature() {

        thermometre(this->num,1);

    }
    R getValeur  () override {
        int val;
        if ((val=thermometre(this->num,2)) < 0) {
            throw capteurErreurLecture("echec lecture du thermometre");
        } else {
            return static_cast<R>(val);
        }
    }
    bool estValide() {
        if (!controle)
            return true;
        auto v = getValeur();
        return (v>= min && v <= max);
    }
    bool operator==(const capteurTemperature<R> & ct) noexcept {
        if (this == &ct)
            return true;
        return (capteur<R>::operator==(ct) && controle == ct.controle && min == ct.min && max == ct.max);
    }

    virtual string getNom()  const noexcept override {
     return capteur<R>::getNom() + " (capteur temperature)";
     }
     template <typename T> friend ostream & operator<<(ostream & out, const capteurTemperature<T>& c);
};

template <typename R> ostream & operator<<(ostream & out, const capteurTemperature<R> & c) {
    out << c.getNom() << ", num = " << c.num;
    if (c.controle) {
        out << ", min = " << c.min << ", max = " << c.max ;
    }
return out;}

#endif // CAPTEURTEMPERATURE_H_INCLUDED
