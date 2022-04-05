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

public:
    Forme(int myX, int myY, string myCouleur, int myTransparence, string myType, int myPlanZ);
    Forme();
    ~Forme();

    virtual void Draw(CImage *img) = 0;
    //virtual int getXmax() = 0;
    //virtual int getYmax() = 0;

};

#endif  /*FORME_H_*/
