#include "Carre.h"

Carre::Carre(int myX, int myY, int myLongueur, string myCouleur, int myTransparence, int myplanZ, int myFacteurEchelle){
    X = myX;
    Y = myY;
    couleur = myCouleur;
    transparence = myTransparence;

    longueur = myLongueur;
    planZ = myplanZ;
    FacteurEchelle = myFacteurEchelle; 
}

Carre::Carre(){
    X = 0;
    Y = 0;
    couleur = "blanc";
    transparence = 0;

    longueur = 1;
    FacteurEchelle = 1;
}

Carre::~Carre(){

}

void Carre::Draw(CImage *img){
    int longTemp = longueur - 1; // logique -> pour un carré 1x1 on va de (0,0) à (0,0) pas (0,1) etc
    Ligne L1(X,Y,X,Y+longTemp,couleur,transparence,planZ,FacteurEchelle);
    Ligne L2(X+1,Y,X+longTemp-1,Y,couleur,transparence,planZ,FacteurEchelle);
    Ligne L3(X+1,Y+longTemp,X+longTemp-1,Y+longTemp,couleur,transparence,planZ,FacteurEchelle);
    Ligne L4(X+longTemp,Y,X+longTemp,Y+longTemp,couleur,transparence,planZ,FacteurEchelle);
    L1.Draw(img);
    L2.Draw(img);
    L3.Draw(img);
    L4.Draw(img);
}

int Carre::getXmax(){ 
    return X + longueur;
}

int Carre::getYmax(){
    return Y + longueur;
}
