#include "RectangleS.h"

RectangleS::RectangleS(int myX, int myY, int myLongueur, int myHauteur, string myCouleur, int myTransparence, int planZ){
    X = myX;
    Y = myY;
    couleur = myCouleur;
    transparence = myTransparence;

    longueur = myLongueur;
    hauteur = myHauteur;
}

RectangleS::~RectangleS(){

}

void RectangleS::Draw(CImage *img){
    for(int i=0; i<hauteur; i++){
        Ligne L(X,Y+i,X+longueur-1,Y+i,couleur,transparence,planZ);
        L.Draw(img);
    }
}
