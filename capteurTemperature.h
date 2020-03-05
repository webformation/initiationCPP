#ifndef CAPTEURTEMPERATURE_H_INCLUDED
#define CAPTEURTEMPERATURE_H_INCLUDED
#include <exception>
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
};


#endif // CAPTEURTEMPERATURE_H_INCLUDED
