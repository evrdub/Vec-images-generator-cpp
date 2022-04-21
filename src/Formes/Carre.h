#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#include "Rectangle.h"

using namespace std;

#ifndef CARRE_H_
#define CARRE_H_

class Carre : public Rectangle{
public:
    Carre(int myX, int myY, int myLongueur, string myCouleur, int myTransparence, int planZ, int myFacteurEchelle);
    Carre();
    ~Carre();

    void Draw(CImage *img);
    int getXmax();
    int getYmax();
};

#endif /*CARRE_H_*/
