#include "CarreS.h"

CarreS::CarreS(int myX, int myY, int myLongueur, string myCouleur, int myTransparence, int myplanZ, int myFacteurEchelle){
    X = myX;
    Y = myY;
    couleur = myCouleur;
    transparence = myTransparence;

    longueur = myLongueur;
    planZ= myplanZ;
    FacteurEchelle = myFacteurEchelle;
}

CarreS::~CarreS(){

}

void CarreS::Draw(CImage *img){
    for(int i=0; i<longueur; i++){
        Ligne L(X,Y+i,X+longueur-1,Y+i,couleur,transparence,planZ,FacteurEchelle);
        L.Draw(img);
    }
}

