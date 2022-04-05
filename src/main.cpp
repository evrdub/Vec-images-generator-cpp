#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>

using namespace std;

#include "./Format/CBitmap.h"
#include "./Formes/Forme.h"
#include "./Formes/Point.h"
#include "./Formes/Ligne.h"
#include "./Formes/Carre.h"
#include "./Formes/Rectangle.h"
#include "./Formes/RectangleS.h"
#include "./Formes/CarreS.h"
#include "./Formes/Cercle.h"
#include "./Formes/CercleS.h"

#define XMAX 500
#define YMAX 500

int main(int argc, char * argv[]){
    cout << "(II) P_Bitmap exection start (" << __DATE__ << " - " << __TIME__ << ")" << endl;
    cout << "(II) + Number of arguments = " << argc << endl;
    cout << "(II) CBitmap object creation" << endl;
    CBitmap *image = new CBitmap();
    string filename2 = "Sortie.bmp";
    cout << "(II) CImage pointer extraction" << endl;
    CImage   *img = new CImage(XMAX, YMAX);

    vector<shared_ptr<Forme>> Formes;
    
    // test de Point (ici une diagonale)
    for(int i; i<XMAX; i++){
        Point P(i,i,"blanc",100,0);
        Formes.push_back(make_shared<Point>(P));
    }
    
    // test de Ligne
    Ligne L1(0,0,0,60,"bleu",100,0);
    Formes.push_back(make_shared<Ligne>(L1));
    Ligne L2(0,0,60,23,"vert",100,0);
    Formes.push_back(make_shared<Ligne>(L2));
    
    // test de Rectangle
    Rectangle R1(15,15,30,123,"blanc",100,0);
    Formes.push_back(make_shared<Rectangle>(R1));
    Rectangle R2(119,119,1,1,"bleu",30,0);
    Formes.push_back(make_shared<Rectangle>(R2));
    
    // test de Carre
    Carre C1(19,28,40,"vert",70,0);
    Formes.push_back(make_shared<Carre>(C1));
    
    // test de CarreS
    CarreS CS1(19,28,40,"vert",70,0);
    Formes.push_back(make_shared<CarreS>(CS1));

    // test de RectangleS
    RectangleS RS1(19,28,60,13,"rouge",30,0);
    Formes.push_back(make_shared<RectangleS>(RS1));
    

    // test de CercleS
    CercleS CeS1(250,250,10,"rouge",100,0);
    Formes.push_back(make_shared<CercleS>(CeS1));

    CercleS CeS2(250,250,9,"noir",100,0);
    Formes.push_back(make_shared<CercleS>(CeS2));

    // test de Cercle
    Cercle Ce1(250,250,50,"rouge",100,0);
    Formes.push_back(make_shared<Cercle>(Ce1));

    Cercle Ce2(12,12,5,"rouge",100,0);
    Formes.push_back(make_shared<Cercle>(Ce2));    

    
    printf("\033[0;32m");
    cout << "Number of  'Formes' = " << Formes.size() << endl;
    cout << "Is vector 'Formes' empty : " << Formes.empty() << " (1 is true and 0 is false)" << endl;
    printf("\033[0;37m");
    
    for (auto figure : Formes){
        figure->Draw(img);
    }
    
    image->setImage( img );
    cout << "(II) CBitmap image saving" << endl;
    image->SaveBMP(filename2);
    return 1;
}
