#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void tableMulti(int nb)
{
    int i {0};
    while (i <= 10)
    {
        cout << i << " * " << nb << " = " << i * nb << endl;
        i++;
    }
}

void dessinForme(int ligne, int colonne, char c)
{
    int x{0};
    int y{0};
    while (x < ligne)
    {
        while (y < colonne)
        {
            cout << c;
            y++;
        }
        cout << endl;
        x++;
        y = 0;
    }
}

int main()
{
    /*double a{0}, b{0};
    cout << "que veux tu additionner : "; 
    cin >> a;
    cout << "avec : ";
    cin >> b;
    cout << a << " + " << b << " fait donc " << a + b << endl; 
    double result{a + b};
    cout << "la valeur au carre est de " << sqrt(result) << endl;
    cout << "la puissance est de " << pow(a,b) << endl;
    cout << "on ajoute 2 : " << addTwo(result) << endl;*/

    /*int nombre{0};
    cout << "choisir un chiffre : ";
    cin >> nombre;
    tableMulti(nombre);*/

    int colonne{0};
    int ligne{0};
    char c;
    cout << "quel caractere voulez vous : ";
    cin >> c;
    while (colonne <= 0 || ligne <= 0)
    {
        cout << "nombre de colonnes : ";
        cin >> colonne;
        cout << "nombre de lignes : ";
        cin >> ligne;
        if (colonne <= 0 || ligne <= 0)
            cout << "SAISI ERREUR" << endl;
    }
    dessinForme(ligne, colonne, c);

    return 0;
}