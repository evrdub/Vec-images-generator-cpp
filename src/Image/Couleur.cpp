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
    else if(nomCouleur == "rose"){
        R = 219;
        G = 112;
        B = 147;
    }
    else if(nomCouleur == "gris"){
        R = 69;
        G = 69;
        B = 69;
    }
    else if(nomCouleur == "azur"){
        R = 0;
        G = 127;
        B = 255;
    }
    else if(nomCouleur == "orange"){
        R = 255;
        G = 127;
        B = 0;
    }
    else if(nomCouleur == "indigo"){
        R = 75;
        G = 0;
        B = 130;
    }
    else if(nomCouleur == "canard"){
        R = 4;
        G = 139;
        B = 154;
    }
    else if(nomCouleur == "vert_pomme"){
        R = 52;
        G = 201;
        B = 36;
    }
    else if(nomCouleur == "bordeaux"){
        R = 109;
        G = 7;
        B = 26;
    }
    else if(nomCouleur == "sang_de_boeuf"){
        R = 115;
        G = 8;
        B = 0;
    }
    else if(nomCouleur == "violet"){
        R = 114;
        G = 49;
        B = 137;
    }
    else if(nomCouleur == "jaune"){
        R = 255;
        G = 255;
        B = 0;
    }
    else if(nomCouleur == "aigue-marine"){
        R = 121;
        G = 248;
        B = 248;
    }
    else if(nomCouleur == "pastaga"){
        R = 224;
        G = 222;
        B = 140;
    }
    else if(nomCouleur == "jaune_pale"){
        R = 253;
        G = 253;
        B = 150;
    }
    else if(nomCouleur == "gris_clair"){
        R = 112;
        G = 114;
        B = 110;
    }
    else if(nomCouleur == "argent"){
        R = 192;
        G = 192;
        B = 192;
    }
    else if(nomCouleur == "bleu_fonce"){
        R = 15;
        G = 5;
        B = 107;
    }
    else if(nomCouleur == "sable"){
        R = 224;
        G = 205;
        B = 169;
    }
    else if(nomCouleur == "mer"){
        R = 127;
        G = 255;
        B = 212;
    }
    else if(nomCouleur == "ciel"){
        R = 135;
        G = 206;
        B = 235;
    }
    else if(nomCouleur == "peche"){
        R = 236;
        G = 189;
        B = 144;
    }
    else if(nomCouleur == "soleil"){
        R = 231;
        G = 240;
        B = 13;
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