#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#include "Rectangle.h"

using namespace std;

#ifndef RECTANGLES_H_
#define RECTANGLES_H_

class RectangleS : public Rectangle{
public:
    RectangleS(int myX, int myY, int myLongueur, int myHauteur, string myCouleur, int myTransparence, int planZ, int myFacteurEchelle);
    ~RectangleS();

    void Draw(CImage *img);
    int getXmax();
    int getYmax();
};

#endif /*RECTANGLES_H_*/
