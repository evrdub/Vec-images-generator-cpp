#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#include "RectangleS.h"

using namespace std;

#ifndef CARRES_H_
#define CARRES_H_

class CarreS : public RectangleS{
public:
    CarreS(int myX, int myY, int myLongueur, string myCouleur, int myTransparence, int planZ, int myFacteurEchelle);
    CarreS();
    ~CarreS();
};

#endif /*CARRES_H_*/
