#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#include "Cercle.h"

using namespace std;

#ifndef CERCLES_H_
#define CERCLES_H_

class CercleS : public Cercle{
private:
    int R;
public:
    CercleS(int myX, int myY, int myR, string myCouleur, int myTransparence, int myPlanZ, int myFacteurEchelle);
    ~CercleS();

    void Draw(CImage *img);

};

#endif  /*CERCLES_H_*/
