#include "Forme.h"

Forme::Forme(int myX, int myY, string myCouleur, int myTransparence, int myPlanZ, int myFacteurEchelle){
    X = myX;
    Y = myY;
    couleur = myCouleur;
    transparence = myTransparence;
    planZ = myPlanZ;
    FacteurEchelle = myFacteurEchelle;
}

Forme::Forme(){
    X = 0;
    Y = 0;
    couleur = "blanc";
    transparence = 0;
    planZ = 1;
    FacteurEchelle = 1;
}

Forme::~Forme(){}

int Forme::getPlan(){
    return planZ;
}

int Forme::getXmax(){ 
    return X;
}

int Forme::getYmax(){
    return Y;
}

