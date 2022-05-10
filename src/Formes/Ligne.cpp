#include "Ligne.h"

Ligne::Ligne(int myX, int myY, int myX2, int myY2, string myCouleur, int myTransparence, int myPlanZ, int myFacteurEchelle){
    X = myX;
    Y = myY;
    X2 = myX2;
    Y2 = myY2;
    couleur = myCouleur;
    transparence = myTransparence;
    planZ = myPlanZ;
    FacteurEchelle = myFacteurEchelle;
}

Ligne::Ligne(){
    X = 0;
    Y = 0;
    X2 = 0;
    Y2 = 0;
    couleur = "blanc";
    transparence = 0;
    planZ = 1;
    FacteurEchelle = 1;
}

Ligne::~Ligne(){
    
}

void Ligne::Draw(CImage *img){
    int dir,i,X_temp,Y_temp,n, delta;

    // définition de la direction du tracé
    if( (X == X2) && (Y == Y2) ){
        dir = -1;
    }
    else if (abs(X-X2) >= abs(Y-Y2)){
        dir = 0; // tracé horizontal
        delta = X<X2 ? 1 : -1;
        n = abs(X-X2);
    }
    else{
        dir =1; // tracé vertical
        delta = Y<Y2 ? 1 : -1;
        n = abs(Y-Y2);
    }

    // tracé en fonction de la direction
    if (dir == 0){
        X_temp = X;
        for (i=0; i<=n; i++, X_temp += delta){
            Y_temp = (Y2-Y)*(X_temp-X)/(X2-X)+Y;
            Point P(X_temp,Y_temp,couleur,transparence,planZ,FacteurEchelle);
            P.Draw(img);
        }
    }
    else if(dir == -1){
        Point P(X,Y,couleur,transparence,planZ,FacteurEchelle);
        P.Draw(img);
    }
    else{
        Y_temp = Y;
        for (i=0; i<=n; i++, Y_temp += delta){
            X_temp = (X2-X)*(Y_temp-Y)/(Y2-Y)+X;
            Point P(X_temp,Y_temp,couleur,transparence,planZ,FacteurEchelle);
            P.Draw(img);
	    }
    }
}

int Ligne::getXmax(){
    return ( (X>X2) ? X : X2 );
}

int Ligne::getYmax(){
    return ( (Y>Y2) ? Y : Y2 );
}
