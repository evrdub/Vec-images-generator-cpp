#include "Point.h"

Point::Point(int myX, int myY, string myCouleur, int myTransparence, int myPlanZ){
    X = myX;
    Y = myY;
    couleur = myCouleur;
    transparence = myTransparence;
    planZ = myPlanZ;
}

Point::~Point(){
    
}

void Point::Draw(CImage *img){
    /*
    printf("\033[0;32m");
    cout << "Xmax = " << getXmax(img) << " | Ymax = " << getYmax(img) << endl;
    cout << "Current X = " << X << " | Current Y = " << Y << endl;
    printf("\033[0;37m");
    */
    if( (X < getXmax(img)) && (Y < getYmax(img)) && (X >= 0) && (Y >= 1)){
        CPixel *p = img->getPixel(X, Y);
        Couleur col(couleur);
        // p->Red()     = couleur precedente pixel 
        // col.getRed() = couleur forme 
        int tempR = ( (100-transparence)*p->Red()   + transparence*col.getRed()   ) / 100;
        int tempG = ( (100-transparence)*p->Green() + transparence*col.getGreen() ) / 100;
        int tempB = ( (100-transparence)*p->Blue()  + transparence*col.getBlue()  ) / 100;
        p->RGB(tempR,tempG,tempB);
    }
}

int Point::getXmax(CImage *img){
    return img->getLargeur();
}

int Point::getYmax(CImage *img){
    return img->size();
}
