#include "Forme.h"

Forme::Forme(int myX, int myY, string myCouleur, int myTransparence, string myType, int myPlanZ){
    X = myX;
    Y = myY;
    couleur = myCouleur;
    transparence = myTransparence;
    planZ = myPlanZ;

    type = myType;
}

Forme::Forme(){
    X = 0;
    Y = 0;
    couleur = "blanc";
    transparence = 0;
    type = "point";
}

Forme::~Forme(){}

int Forme::getPlan(){
    return planZ;
}

