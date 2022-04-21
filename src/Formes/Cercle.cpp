#include "Cercle.h"

Cercle::Cercle(int myX, int myY, int myEpaisseur, int myR, string myCouleur, int myTransparence, int myPlanZ, int myFacteurEchelle){
    X = myX;
    Y = myY;
    couleur = myCouleur;
    transparence = myTransparence;
    planZ = myPlanZ;

    epaisseur = myEpaisseur;
    R = myR;
    FacteurEchelle = myFacteurEchelle;
}

Cercle::Cercle(){
    X = 0;
    Y = 0;
    epaisseur = 1;
    couleur = "blanc";
    transparence = 0;
    planZ = 0;

    R = 1;
}

Cercle::~Cercle(){

}

void Cercle::Draw(CImage *img){
    int X_depart = X-R;
    int Y_depart = Y-R;
    for(int i=X_depart; i < 2*R+X_depart; i++){
        for(int j=Y_depart; j< 2*R+Y_depart; j++){
            float calc = (i-X)*(i-X)+(j-Y)*(j-Y);
            float Rplus = R+epaisseur/2;
            int Rmoins = R-epaisseur/2-1;
            if( calc <= (Rplus)*(Rplus) && calc >(Rmoins)*(Rmoins) ){
                Point P(i,j,couleur,transparence,planZ,FacteurEchelle);
                P.Draw(img);
            }
        }
    }
}

int Cercle::getXmax(){ 
    return X + R;
}

int Cercle::getYmax(){
    return Y + R;
}
