#include "Rectangle.h"

Rectangle::Rectangle(int myX, int myY, int myLongueur, int myHauteur, string myCouleur, int myTransparence, int planZ){
    X = myX;
    Y = myY;
    couleur = myCouleur;
    transparence = myTransparence;

    longueur = myLongueur;
    hauteur = myHauteur;
}

Rectangle::Rectangle(){
    X = 0;
    Y = 0;
    couleur = "blanc";
    transparence = 0;

    longueur = 1;
    hauteur = 1;
}

Rectangle::~Rectangle(){

}

void Rectangle::Draw(CImage *img){
    int longTemp = longueur - 1; // logique -> pour un carré 1x1 on va de (0,0) à (0,0) pas (0,1) etc
    int hautTemp = hauteur  - 1; // idem
    Ligne L1(X,Y,X,Y+hautTemp,couleur,transparence,planZ);
    Ligne L2(X,Y,X+longTemp,Y,couleur,transparence,planZ);
    Ligne L3(X,Y+hautTemp,X+longTemp,Y+hautTemp,couleur,transparence,planZ);
    Ligne L4(X+longTemp,Y,X+longTemp,Y+hautTemp,couleur,transparence,planZ);
    L1.Draw(img);
    L2.Draw(img);
    L3.Draw(img);
    L4.Draw(img);
}

