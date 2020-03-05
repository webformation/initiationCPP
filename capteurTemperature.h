#ifndef CAPTEURTEMPERATURE_H_INCLUDED
#define CAPTEURTEMPERATURE_H_INCLUDED
#include <exception>
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

    }
    ~capteurTemperature()
    {
        if (nom != nullptr)
            delete nom;
    }
};


#endif // CAPTEURTEMPERATURE_H_INCLUDED
