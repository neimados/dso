#include "ZFraction.h"

ZFraction::ZFraction(int nb, int diviseur)//constructeur
{
    m_nb = nb;
    m_diviseur = diviseur;
}

bool ZFraction::estEgal(ZFraction const& b) const
{
    if (b.m_nb == m_nb && b.m_diviseur == m_diviseur)
        return true;
    else
        return false;
}

bool ZFraction::estInferieur(ZFraction const& b) const
{
    if (((float)m_nb / (float)m_diviseur) < ((float)b.m_nb / (float)b.m_diviseur))
        return true;
    else
        return false;
}

bool ZFraction::estSuperieur(ZFraction const& b) const
{
    if (((float)m_nb / (float)m_diviseur) > ((float)b.m_nb / (float)b.m_diviseur))
        return true;
    else
        return false;
}

int ZFraction::getDiviseur() const// pas utile ici. Pour access attribut
{
    return this-> m_diviseur;
}

void ZFraction::addition(ZFraction copieB)
{
    int tmp(0);
    if (m_diviseur == copieB.m_diviseur)
    {
        m_nb += copieB.m_nb;
    }
    else
    {
        tmp = m_diviseur;// tmp pour pas perdre le diviseur de A
        m_nb *= copieB.m_diviseur;
        m_diviseur *= copieB.m_diviseur;
        copieB.m_nb *= tmp;
        copieB.m_diviseur *= tmp;// on multiplit A par diviseur B puis B par diviseur A
        m_nb += copieB.m_nb;// quand ils ont le meme diviseur, reste plus qu'à ajouter le haut.
    }
    int m_pgcd(0);//fn plus grand denominateur commun pour reduire les fractions
    m_pgcd = pgcd(m_nb, m_diviseur);
    if (m_pgcd > 0)
    {
        m_nb /= m_pgcd;
        m_diviseur /= m_pgcd;
    }
}

ZFraction operator+(ZFraction const&a, ZFraction const &b)
{
    ZFraction copieA(a);//on cree des copies pour ne pas modifier l'orig
    ZFraction copieB(b);
    copieA.addition(copieB);//appel de la fn pour additionner
    return copieA;
}

void ZFraction::multi(ZFraction const &b)
{
    m_nb *= b.m_nb;
    m_diviseur *= b.m_diviseur;
    int m_pgcd(0);//fn plus grand denominateur commun pour reduire les fractions
    m_pgcd = pgcd(m_nb, m_diviseur);
    if (m_pgcd > 0)
    {
        m_nb /= m_pgcd;
        m_diviseur /= m_pgcd;
    }
}

ZFraction operator*(ZFraction const&a, ZFraction const &b)
{
    ZFraction copieA(a);
    copieA.multi(b);
    return copieA;
}

bool operator==(ZFraction const& a, ZFraction const& b)
{
    return a.estEgal(b);
}

bool operator<(ZFraction const& a, ZFraction const& b)
{
    return a.estInferieur(b);
}

bool operator>(ZFraction const& a, ZFraction const& b)
{
    return a.estSuperieur(b);
}

std::ostream& operator<<(std::ostream &flux, ZFraction const& a )
{
    a.afficher(flux);
    return flux;
}

void ZFraction::afficher(std::ostream &flux) const//fn d'affichage
{
    if (m_diviseur == 1)
        flux << m_nb;
    else
        flux << m_nb << "/" << m_diviseur;
}

int pgcd(int a, int b)
{
    while (b != 0)
    {
        const int t = b;
        b = a%b;
        a=t;
    }
    return a;
}