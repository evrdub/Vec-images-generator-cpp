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

string ProgressBar = "                                                  ";

void updateProgressBar(int pourcentage){
    for(int i=0; i<pourcentage/2; i++){
        ProgressBar[i] = '#';
    }
}

int main(int argc, char * argv[]){
    printf("\033[0;32m");
    cout << "Start (" << __DATE__ << " - " << __TIME__ << ")" << endl;

    int FacteurEchelle;
    string fileIn = argv[1];
    string fileOut = argv[2];
    if(argc == 3){              // pas de facteur d'echelle => par defaut 1
        FacteurEchelle = 1; 
        cout << "FacteurEchelle = " << FacteurEchelle << endl;
    }
    if(argc == 4){
        FacteurEchelle = atoi(argv[3]); 
        cout << "FacteurEchelle = " << FacteurEchelle << endl;
    }

    vector< Forme * > Formes;

    printf("\033[0;36m");
    cout << "--- READFILE ---" << endl;
    Formes = readFile(fileIn,FacteurEchelle);
    cout << "--- PLAN SORTING ---" << endl;
    Formes = sortFormes(Formes, getPlanMax(Formes));
    cout << "--- GETTING MAX X Y ---" << endl;
    int Xmax = getXmax(Formes);
    int Ymax = getYmax(Formes);
    cout << "Xmax = " << Xmax << " | Ymax = " << Ymax << endl;
    cout << "--- CREATING IMAGE ---" << endl;
    CBitmap *image = new CBitmap();
    CImage   *img = new CImage(Ymax*FacteurEchelle, Xmax*FacteurEchelle);

    cout << "Number of  shapes = " << Formes.size() << endl;
    cout << "--- DRAWING SHAPES ---" << endl;
    for(int i = 0; i<Formes.size(); i++){
        updateProgressBar(i*100/Formes.size());
        cout << "\r[" << ProgressBar << "] - " << i*100/Formes.size() << "% - " << i << " / " << Formes.size();
        Forme * F = Formes[i];
        F->Draw(img);
        cout.flush();
    }
    // pour avoir une barre à 100%, sinon reste bloqué un peu avant (ex 98%)
    updateProgressBar(100);
    cout << "\r[" << ProgressBar << "] - " << 100 << "% - " << Formes.size() << " / " << Formes.size() << endl;
    
    cout << "--- IMAGE SAVING ---" << endl;
    image->setImage( img );
    image->SaveBMP(fileOut);
    return 1;
}
