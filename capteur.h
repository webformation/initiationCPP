#ifndef CAPTEUR_H_INCLUDED
#define CAPTEUR_H_INCLUDED

class capteur
{
protected:
    string *nom = nullptr;
    int num;
public:
    capteur(string nom, int num) : num(num)
    {
        if (nom.size() < 3)
        {
            throw invalid_argument("le nom doit contenir au moins 3 caracteres");
        }
        this->nom = new string(nom);
    }
    capteur(const capteur & ct)
    {
        nom = new string(*(ct.nom));
        num = ct.num;
    }
    capteur & operator=(const capteur & ct)
    {
        if (this == &ct) return *this;
        if (nom!=nullptr)
            delete nom;
        nom = new string(*(ct.nom));
        num = ct.num;
        return *this;
    }
    virtual ~capteur()
    {
        if (nom != nullptr)
        {
            delete nom;
        }
    }
    bool operator==(const capteur & ct)
    {
        if (this == &ct)
            return true;
        return (*nom == *(ct.nom) && num==ct.num);
    }
    virtual string getNom() const
    {
        return *nom;
    }
    virtual float getValeur() = 0;

};

#endif // CAPTEUR_H_INCLUDED
