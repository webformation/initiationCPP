#ifndef CAPTEURPRESSION_H_INCLUDED
#define CAPTEURPRESSION_H_INCLUDED

#include "capteur.h"

class capteurPression: public capteur
{

public:
    capteurPression(string nom, int num) : capteur(nom,num)
    {
    }
    capteurPression(const capteurPression & cp) : capteur(cp)
    {
    }

    capteurPression & operator=(const capteurPression & cp) = delete;

    float getValeur()
    {
             return 1.f;
    }
    bool operator==(const capteurPression & cp)
    {
        if (this == &cp)
            return true;
        return (capteur::operator==(cp) );
    }
     string getNom() const noexcept {
        return capteur::getNom() + " (capteur pression)";
    }
};



#endif // CAPTEURPRESSION_H_INCLUDED
