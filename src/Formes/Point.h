#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#include "../Image/CImage.h"
#include "Forme.h"
#include "../Image/Couleur.h"

using namespace std;

#ifndef POINT_H_
#define POINT_H_

class Point : public Forme{
public:
    Point(int myX, int myY, string myCouleur, int myTransparence, int myPlanZ, int myFacteurEchelle);
    ~Point();

    void Draw(CImage *img);
    int getXmax(CImage *img);
    int getYmax(CImage *img);

};

#endif  /*POINT_H_*/
