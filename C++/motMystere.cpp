#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cctype>
#include <algorithm>

bool checkMot (std::string mot);
std::string motMixed (std::string mot);

int main()
{
    bool motValide {false};
    std::string motChoisi;
    srand(time(0));

    while (motValide != true)
    {
        std::cout << "Joueur 1, choisissez un mot : ";
        std::cin >> motChoisi;
        std::transform(motChoisi.begin(), motChoisi.end(), motChoisi.begin(), ::toupper);//met tout le mot en majuscule
        if (checkMot(motChoisi) != true)
            std::cout << "MOT INCORRECT" << std::endl;
        else
        {
            std::cout << "\n\n\n\n\n" << std::endl;
            motValide = true;
        }
    }

    std::string motJoueur;
    std::string motMystere;
    motMystere = motMixed(motChoisi);
    while (motChoisi != motJoueur)
    {
        std::cout << "Joueur 2, devinez : " << motMystere << std::endl;
        std::cin >> motJoueur;
        std::transform(motJoueur.begin(), motJoueur.end(), motJoueur.begin(), ::toupper);
        if (motJoueur != motChoisi)
            std::cout << "NON C\'EST FAUX !" << std::endl;
    }

    std::cout << "BRAVO ! Le mot choisi etait bien : " << motChoisi << std::endl;

    return 0;
}

std::string motMixed (std::string mot)//copie le mot dans un new string en le mixant aleatoirement
{
    int letter{0};
    int length{0};
    int i{0};
    std::string tmp;
    std::string newMot;
    tmp = mot;
    length = mot.size();
    while (i < length)
    {
        letter = rand() % (length - i);
        newMot += tmp[letter];
        tmp.erase(letter, 1);
        i++;
    }
    return newMot;
}

bool checkMot (std::string mot) // check si c'est bien un mot normal
{
    int i {0};
    while (mot[i])
    {
        if (mot[i] < 'A' || mot[i] > 'Z')
            return false;
        i++;
    }
    return true;
}