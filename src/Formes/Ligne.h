#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#include "Point.h"

using namespace std;

#ifndef LIGNE_H_
#define LIGNE_H_

class Ligne : public Forme{
private:
    int X2;
    int Y2;
public:
    Ligne(int myX, int myY, int myX2, int myY2, string myCouleur, int myTransparence, int myPlanZ, int myFacteurEchelle);
    ~Ligne();

    void Draw(CImage *img);
    int getXmax();
    int getYmax();
};

#endif  /*LIGNE_H_*/
