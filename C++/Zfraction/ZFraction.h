#include <iostream>

#ifndef DEF_ZFRACTION
#define DEF_ZFRACTION

class ZFraction
{
public:
    ZFraction(int nb = 1, int diviseur = 1);
    bool estEgal(ZFraction const &b) const;
    bool estInferieur(ZFraction const& b) const;
    bool estSuperieur(ZFraction const& b) const;
    void addition(ZFraction copieB);
    void multi(ZFraction const &b);
    void afficher(std::ostream &flux) const;
    int getDiviseur() const;

private:
    int m_nb;
    int m_diviseur;
};


bool operator==(ZFraction const& a, ZFraction const& b);
bool operator<(ZFraction const& a, ZFraction const& b);
bool operator>(ZFraction const& a, ZFraction const& b);
ZFraction operator+(ZFraction const&a, ZFraction const &b);
ZFraction operator*(ZFraction const&a, ZFraction const &b);
std::ostream& operator<<(std::ostream &flux, ZFraction const& a);
int pgcd(int a, int b);

#endif