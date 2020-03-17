#ifndef ETATVALIDE_H_INCLUDED
#define ETATVALIDE_H_INCLUDED

enum class etatValide {
    infMinimum, valide, supMaximum
};

ostream & operator<<(ostream & o, etatValide e);
#endif // ETATVALIDE_H_INCLUDED
