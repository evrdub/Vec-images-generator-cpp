#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#include "../Image/CImage.h"

using namespace std;

#ifndef FORME_H_
#define FORME_H_

class Forme{
private:
    string type;

protected:
    int X;
    int Y;
    string couleur;
    int transparence;
    int planZ;
    int FacteurEchelle;

public:
    Forme(int myX, int myY, string myCouleur, int myTransparence, int myPlanZ, int myFacteurEchelle);
    Forme();
    ~Forme();

    int getPlan();
    virtual int getXmax();
    virtual int getYmax();
    virtual void Draw(CImage *img) = 0;
};

#endif  /*FORME_H_*/
