#include "Cercle.h"

#define ERROR_PERCT 1

Cercle::Cercle(int myX, int myY, int myR, string myCouleur, int myTransparence, int myPlanZ){
    X = myX;
    Y = myY;
    couleur = myCouleur;
    transparence = myTransparence;
    planZ = myPlanZ;

    R = myR;
}

Cercle::Cercle(){
    X = 0;
    Y = 0;
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
    //cout << " X = " << X << " | Y = " << Y << " | R = " << R << endl;
    //cout << " X_depart = " << X_depart << " | Y_depart = " << Y_depart << endl;
    for(int i=X_depart; i < 2*R+X_depart; i++){
        for(int j=Y_depart; j< 2*R+Y_depart; j++){
            //cout << " i = " << i << " | j = " << j << endl;
            float calc = (i-X)*(i-X)+(j-Y)*(j-Y);
            //cout << " (i-X)*(i-X)+(j-Y)*(j-Y) = " << calc << " | R*R = " << R*R << endl;
            //if( (calc <= R*R*(100+ERROR_PERCT)/100) && (calc >= R*R*(100-ERROR_PERCT)/100) ){
            //if(calc == R*R){
            if( calc <= R*R && calc >(R-1)*(R-1)){
                Point P(i,j,couleur,transparence,planZ);
                P.Draw(img);
            }
        }
    }
}
