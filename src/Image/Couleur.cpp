#include "Couleur.h"

Couleur::Couleur(int myR, int myG, int myB){
    R = myR;
    G = myG;
    B = myB;
}

Couleur::Couleur(string nomCouleur){
    if(nomCouleur == "blanc"){
        R = 255;
        G = 255;
        B = 255;
    }
    else if(nomCouleur == "noir"){
        R = 0;
        G = 0;
        B = 0;
    }
    else if(nomCouleur == "rouge"){
        R = 255;
        G = 0;
        B = 0;
    }
    else if(nomCouleur == "bleu"){
        R = 0;
        G = 0;
        B = 255;
    }
    else if(nomCouleur == "vert"){
        R = 0;
        G = 255;
        B = 0;
    }
    else{
        R = 0;
        G = 0;
        B = 0;
        cout << "--- Couleur inconnue -> par defaut noir ---" << endl;
    }
}

Couleur::~Couleur(){

}

int Couleur::getRed(){
    return R;
}

int Couleur::getGreen(){
    return G;
}

int Couleur::getBlue(){
    return B;
}