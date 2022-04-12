#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#include "Point.h"

using namespace std;

#ifndef CERCLE_H_
#define CERCLE_H_

class Cercle : public Forme{
private:
    int epaisseur;
    int R;
public:
    Cercle(int myX, int myY, int myEpaisseur, int myR, string myCouleur, int myTransparence, int myPlanZ, int myFacteurEchelle);
    Cercle();
    ~Cercle();

    void Draw(CImage *img);

};

#endif  /*CERCLE_H_*/
