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
    int R;
public:
    Cercle(int myX, int myY, int myR, string myCouleur, int myTransparence, int myPlanZ);
    Cercle();
    ~Cercle();

    void Draw(CImage *img);

};

#endif  /*CERCLE_H_*/
