#ifndef CAPTEURTEMPERATURE_H_INCLUDED
#define CAPTEURTEMPERATURE_H_INCLUDED
#include <exception>
extern "C" int thermometre(int num, int code);
class capteurTemperature
{
private:
    static int nb;
public:
    int static getNb() { return nb;}
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
        ++nb;
    }
    capteurTemperature(const capteurTemperature & ct): min(ct.min),  max(ct.max)
    {
        nom = new string(*(ct.nom));
        num = ct.num;
        controle = ct.controle;
        ++nb;
    }
    capteurTemperature & operator=(const capteurTemperature & ct)
    {
        if (this == &ct) return *this;
        if (nom!=nullptr)
            delete nom;
        nom = new string(*(ct.nom));
        num = ct.num;
        min = ct.min;
        max = ct.max;
        controle = ct.controle;
        return *this;
    }
    ~capteurTemperature()
    {
        if (nom != nullptr)
        {
            delete nom;
        }
        thermometre(num,1);
        --nb;
    }
    float getValeur()
    {
        int val;
        if ((val=thermometre(num,2)) < 0)
        {
            throw runtime_error("echec lecture du thermometre");
        }
        else
        {
            return static_cast<float>(val);
        }
    }
    bool estValide()
    {
        if (!controle)
            return true;
        float v = getValeur();
        return (v>= min && v <= max);
    }
    bool operator==(const capteurTemperature & ct)
    {
        if (this == &ct)
            return true;
        return (*nom == *(ct.nom) && num==ct.num);
    }
    string getNom() const
    {
        return *nom;
    }
    friend ostream & operator<<(ostream & out, const capteurTemperature& c);
};


#endif // CAPTEURTEMPERATURE_H_INCLUDED
