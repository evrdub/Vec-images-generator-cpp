#include "CarreS.h"

CarreS::CarreS(int myX, int myY, int myLongueur, string myCouleur, int myTransparence, int myplanZ, int myFacteurEchelle){
    X = myX;
    Y = myY;
    couleur = myCouleur;
    transparence = myTransparence;
    longueur = myLongueur;
    hauteur = myLongueur;
    planZ = myplanZ;
    FacteurEchelle = myFacteurEchelle;
}

CarreS::CarreS(){
    X = 0;
    Y = 0;
    couleur = "blanc";
    transparence = 0;
    longueur = 1;
    hauteur = 1;
    planZ = 1;
    FacteurEchelle = 1;
}

CarreS::~CarreS(){

}