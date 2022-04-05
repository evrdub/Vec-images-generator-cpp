#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#include "Carre.h"

using namespace std;

#ifndef CARRES_H_
#define CARRES_H_

class CarreS : public Carre{
public:
    CarreS(int myX, int myY, int myLongueur, string myCouleur, int myTransparence, int planZ);
    ~CarreS();

    void Draw(CImage *img);
    
};

#endif /*CARRES_H_*/
