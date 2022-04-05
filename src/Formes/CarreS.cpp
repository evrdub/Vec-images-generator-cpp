#include "CarreS.h"

CarreS::CarreS(int myX, int myY, int myLongueur, string myCouleur, int myTransparence, int planZ){
    X = myX;
    Y = myY;
    couleur = myCouleur;
    transparence = myTransparence;

    longueur = myLongueur;
}

CarreS::~CarreS(){

}

void CarreS::Draw(CImage *img){
    for(int i=0; i<longueur; i++){
        Ligne L(X,Y+i,X+longueur-1,Y+i,couleur,transparence,planZ);
        L.Draw(img);
    }
}

