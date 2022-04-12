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

CercleS::~CercleS(){

}

void CercleS::Draw(CImage *img){
    int X_depart = X-R;
    int Y_depart = Y-R;
    //cout << " X = " << X << " | Y = " << Y << " | R = " << R << endl;
    //cout << " X_depart = " << X_depart << " | Y_depart = " << Y_depart << endl;
    for(int i=X_depart; i < 2*R+X_depart; i++){
        for(int j=Y_depart; j< 2*R+Y_depart; j++){
            //cout << " i = " << i << " | j = " << j << endl;
            float calc = (i-X)*(i-X)+(j-Y)*(j-Y);
            //cout << " (i-X)*(i-X)+(j-Y)*(j-Y) = " << calc << " | R*R = " << R*R << endl;
            if( calc <= R*R ){
                Point P(i,j,couleur,transparence,planZ,FacteurEchelle);
                P.Draw(img);
            }
        }
    }
}
