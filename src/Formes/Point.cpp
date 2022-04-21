#include "Point.h"

Point::Point(int myX, int myY, string myCouleur, int myTransparence, int myPlanZ, int myFacteurEchelle){
    X = myX;
    Y = myY;
    couleur = myCouleur;
    transparence = myTransparence;
    planZ = myPlanZ;

    FacteurEchelle = myFacteurEchelle;
}

Point::~Point(){
    
}

void Point::Draw(CImage *img){
    int Xt,Yt;
    for(int i=0; i<FacteurEchelle; i++){
        for(int j=0; j<FacteurEchelle; j++){
            Xt = X*FacteurEchelle + i;
            Yt = Y*FacteurEchelle + j;
            if( (Xt < getXmaxIm(img)) && (Yt < getYmaxIm(img)) && (Xt >= 0) && (Yt >= 0)){
            CPixel *p = img->getPixel(Xt, Yt);
            Couleur col(couleur);
            // p->Red()     = couleur precedente pixel 
            // col.getRed() = couleur forme 
            int tempR = ( (100-transparence)*p->Red()   + transparence*col.getRed()   ) / 100;
            int tempG = ( (100-transparence)*p->Green() + transparence*col.getGreen() ) / 100;
            int tempB = ( (100-transparence)*p->Blue()  + transparence*col.getBlue()  ) / 100;
            p->RGB(tempR,tempG,tempB);
            }
        }
    }
}

int Point::getXmaxIm(CImage *img){
    return img->getLargeur();
}

int Point::getYmaxIm(CImage *img){
    return img->size();
}

int Point::getXmax(){
    return X;
}

int Point::getYmax(){
    return Y;
}
