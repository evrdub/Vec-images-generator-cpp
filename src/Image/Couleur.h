#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

#ifndef COULEUR_H_
#define COULEUR_H_

class Couleur{
private:
    int R;
    int G;
    int B;

public:
    Couleur(int myR, int myG, int myB);
    Couleur(string nomCouleur);
    ~Couleur();

    int getRed();
    int getGreen();
    int getBlue();

};

#endif  /*COULEUR_H_*/
