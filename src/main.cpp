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
#include "./File/FileLib.h"

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

    vector< Forme * > Formes;

    cout<<""<<endl;
    printf("\033[0;36m");
    cout << "--- HERE STARTS READFILE ---" << endl;
    Formes = readFile("test.vec");
    cout << "--- HERE STOPS  READFILE ---" << endl;
    printf("\033[0;37m");
    cout<<""<<endl;
    printf("\033[0;33m");
    /*
    cout << "--- HERE STARTS TESTING ---" << endl;
    string tempString = "[LIGNE : 0, 0, 0, 200, bleu, 100, 4;]";
    string delim = "[]:,;";
    string ignoreList = " ";
    vector<string> strVec = split(tempString,delim,ignoreList);
    for (auto tempString2 : strVec){
        cout << tempString2 << endl;
    }
    
    //cout << strVec[0] << endl;
    cout << "--- HERE STOPS  TESTING ---" << endl;
    printf("\033[0;37m");
    cout<<""<<endl;
    */
    /*
    // test de Point (ici une diagonale)
    for(int i; i<XMAX; i++){
        Point * P = new Point(i,i,"blanc",100,0);
        Formes.push_back(P);
    }
    
    // test de Ligne
    Ligne * L1 = new Ligne(0,0,0,60,"bleu",100,0);
    Formes.push_back(L1);
    Ligne * L2 = new Ligne(0,0,60,23,"vert",100,0);
    Formes.push_back(L2);
    
    // test de Rectangle
    Rectangle * R1 = new Rectangle(15,15,30,123,"blanc",100,0);
    Formes.push_back(R1);
    Rectangle * R2 = new Rectangle(119,119,1,1,"bleu",30,0);
    Formes.push_back(R2);
    
    // test de Carre
    Carre * C1 = new Carre(19,28,40,"vert",70,0);
    Formes.push_back(C1);
    
    // test de CarreS
    CarreS * CS1 = new CarreS(19,28,40,"vert",70,0);
    Formes.push_back(CS1);

    // test de RectangleS
    RectangleS * RS1 = new RectangleS(19,28,60,13,"rouge",30,0);
    Formes.push_back(RS1);
    

    // test de CercleS
    CercleS * CeS1 = new CercleS(250,250,10,"rouge",100,0);
    Formes.push_back(CeS1);

    CercleS * CeS2 = new CercleS(250,250,9,"noir",100,0);
    Formes.push_back(CeS2);

    // test de Cercle
    Cercle * Ce1 = new Cercle(250,250,3,50,"rouge",100,0);
    Formes.push_back(Ce1);

    Cercle * Ce2 = new Cercle(250,250,1,50,"bleu",100,0);
    Formes.push_back(Ce2);

    Cercle * Ce3 = new Cercle(12,12,1,5,"rouge",100,0);
    Formes.push_back(Ce3);
    */

    printf("\033[0;32m");
    cout << "Number of  'Formes' = " << Formes.size() << endl;
    cout << "Is vector 'Formes' empty : " << Formes.empty() << " (1 is true and 0 is false)" << endl;
    printf("\033[0;37m");
    
    //for(int i = 0; i)

    for (auto figure : Formes){
        figure->Draw(img);
    }
    
    image->setImage( img );
    cout << "(II) CBitmap image saving" << endl;
    image->SaveBMP(filename2);
    return 1;
}
