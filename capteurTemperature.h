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
    capteurTemperature(string nom, int num, float min, float max)  : num(num), min(min), max(max),controle(true)
    {
        if (nom.size() < 3)
        {
            // éviter de créer une exception avec new, car cela oblige à penser au delete dans le catch
            //throw new invalid_argument("le nom doit contenir au moins 3 caracteres");
            throw invalid_argument("le nom doit contenir au moins 3 caracteres");

        }
        this->nom = new string(nom);
        //this->nom = &nom; // mauvaise idée car on ne connait pas la durée de vie de nom

    }
    ~capteurTemperature()
    {
        if (nom != nullptr)
            delete nom;
    }
};


#endif // CAPTEURTEMPERATURE_H_INCLUDED
