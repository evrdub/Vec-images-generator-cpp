#include "CercleS.h"

CercleS::CercleS(int myX, int myY, int myR, string myCouleur, int myTransparence, int myPlanZ, int myFacteurEchelle){
    X = myX;
    Y = myY;
    couleur = myCouleur;
    transparence = myTransparence;
    planZ = myPlanZ;
    R = myR;
    FacteurEchelle = myFacteurEchelle;
}

CercleS::CercleS(){
    X = 0;
    Y = 0;
    couleur = "blanc";
    transparence = 0;
    planZ = 1;
    R = 1;
    FacteurEchelle = 1;
}

CercleS::~CercleS(){
}

void CercleS::Draw(CImage *img){
    int X_depart = X-R;
    int Y_depart = Y-R;
    for(int i=X_depart; i < 2*R+X_depart; i++){
        for(int j=Y_depart; j< 2*R+Y_depart; j++){
            float calc = (i-X)*(i-X)+(j-Y)*(j-Y);
            if( calc <= R*R ){
                Point P(i,j,couleur,transparence,planZ,FacteurEchelle);
                P.Draw(img);
            }
        }
    }
}

int CercleS::getXmax(){ 
    return X + R;
}

int CercleS::getYmax(){
    return Y + R;
}
