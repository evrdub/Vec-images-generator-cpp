#include "FileLib.h"

vector<Forme * > readFile(string filename, int FacteurEchelle){
    vector<Forme * > result;

    string currentLine;
    vector<string> Par;
    string delim = "[]:,;";
    string ignoreList = " ";
    string shapeType;
    int x1,y1,x2,y2,plan,transparence,rayon,longueur,hauteur,epaisseur;
    string couleur;
    int line = 0;

    ifstream infile;
    infile.open(filename);
    if(infile.is_open()){
        while(getline(infile,currentLine)){
            if(currentLine[0] != '#' && !currentLine.empty()){
                Par = split(currentLine,delim,ignoreList);
                shapeType = Par[0];
                if(shapeType == "POINT"){
                    x1 = stoi(Par[1]);
                    y1 = stoi(Par[2]);
                    couleur = Par[3];
                    transparence = stoi(Par[4]);
                    plan = stoi(Par[5]);
                    Point * P = new Point(x1,y1,couleur,transparence,plan,FacteurEchelle);
                    result.push_back(P);
                }
                else if(shapeType == "LIGNE"){
                    x1 = stoi(Par[1]);
                    y1 = stoi(Par[2]);
                    x2 = stoi(Par[3]);
                    y2 = stoi(Par[4]);
                    couleur = Par[5];
                    transparence = stoi(Par[6]);
                    plan = stoi(Par[7]);
                    Ligne * L = new Ligne(x1,y1,x2,y2,couleur,transparence,plan,FacteurEchelle);
                    result.push_back(L);
                }
                else if(shapeType == "RECTANGLE"){
                    x1 = stoi(Par[1]);
                    y1 = stoi(Par[2]);
                    longueur = stoi(Par[3]);
                    hauteur = stoi(Par[4]);
                    couleur = Par[5];
                    transparence = stoi(Par[6]);
                    plan = stoi(Par[7]);
                    Rectangle * R = new Rectangle(x1,y1,longueur,hauteur,couleur,transparence,plan,FacteurEchelle);
                    result.push_back(R);
                }
                else if(shapeType == "RECTANGLES"){
                    x1 = stoi(Par[1]);
                    y1 = stoi(Par[2]);
                    longueur = stoi(Par[3]);
                    hauteur = stoi(Par[4]);
                    couleur = Par[5];
                    transparence = stoi(Par[6]);
                    plan = stoi(Par[7]);
                    RectangleS * R = new RectangleS(x1,y1,longueur,hauteur,couleur,transparence,plan,FacteurEchelle);
                    result.push_back(R);
                }
                else if(shapeType == "CERCLE"){
                    x1 = stoi(Par[1]);
                    y1 = stoi(Par[2]);
                    epaisseur = stoi(Par[3]);
                    rayon = stoi(Par[4]);
                    couleur = Par[5];
                    transparence = stoi(Par[6]);
                    plan = stoi(Par[7]);
                    Cercle * C = new Cercle(x1,y1,epaisseur,rayon,couleur,transparence,plan,FacteurEchelle);
                    result.push_back(C);
                }
                else if(shapeType == "CERCLES"){
                    x1 = stoi(Par[1]);
                    y1 = stoi(Par[2]);
                    rayon = stoi(Par[3]);
                    couleur = Par[4];
                    transparence = stoi(Par[5]);
                    plan = stoi(Par[6]);
                    CercleS * C = new CercleS(x1,y1,rayon,couleur,transparence,plan,FacteurEchelle);
                    result.push_back(C);
                }
                else if(shapeType == "CARRE"){
                    x1 = stoi(Par[1]);
                    y1 = stoi(Par[2]);
                    longueur = stoi(Par[3]);
                    couleur = Par[4];
                    transparence = stoi(Par[5]);
                    plan = stoi(Par[6]);
                    Carre * C = new Carre(x1,y1,longueur,couleur,transparence,plan,FacteurEchelle);
                    result.push_back(C);
                }
                else if(shapeType == "CARRES"){
                    x1 = stoi(Par[1]);
                    y1 = stoi(Par[2]);
                    longueur = stoi(Par[3]);
                    couleur = Par[4];
                    transparence = stoi(Par[5]);
                    plan = stoi(Par[6]);
                    CarreS * C = new CarreS(x1,y1,longueur,couleur,transparence,plan,FacteurEchelle);
                    result.push_back(C);
                }
            }
        }
        infile.close();
        return result;
    }
    else{
        return result;
    }
}

vector<Forme * > sortFormes(vector<Forme * > Formes, int plan_max){
    int plan;
    vector<Forme * > result;
    for(int i=1; i<=plan_max; i++){
        for(int j=0; j<Formes.size();j++){
            Forme * F = Formes[j];
            int plan = F->getPlan();
            if (plan == plan_max-i+1){
                result.push_back(F);
            }
        }
    }
    return result;
}

int getPlanMax(vector<Forme * > Formes){
    int PlanMax = 1;
    for(int i=0; i<Formes.size(); i++){
        Forme * F = Formes[i];
        int currentPlan = F->getPlan();
        if(currentPlan > PlanMax){
            PlanMax = currentPlan;
        }
    }
    return PlanMax;
}

int getXmax(vector<Forme * > Formes){
    int Xmax = 1;
    for(int i=0; i<Formes.size(); i++){
        Forme * F = Formes[i];
        int currentX = F->getXmax();
        if(currentX > Xmax){
            Xmax = currentX;
        }
    }
    return Xmax;
}

int getYmax(vector<Forme * > Formes){
    int Ymax = 1;
    for(int i=0; i<Formes.size(); i++){
        Forme * F = Formes[i];
        int currentY = F->getYmax();
        if(currentY > Ymax){
            Ymax = currentY;
        }
    }
    return Ymax;
}

vector<string> split (string s, string delim, string ignoreList) {
    vector<string> result;
    string tmpStr;
    char currentChar;
    int push = 0;
    int charEqu = 0;
    int ignore = 0;
    for(int i=0; i<s.length(); i++){
        currentChar = s[i];
        for(int j=0; j<delim.length(); j++){
            if(currentChar == delim[j]){
                charEqu = 1;
            }    
        }
        for(int j=0; j<ignoreList.length(); j++){
            if(currentChar == ignoreList[j]){
                ignore = 1;
            }    
        }
        if(ignore == 0){
            if(charEqu){
                push = 1;
            }
            else{
                tmpStr+=currentChar;
            }
        }
        charEqu = 0;
        ignore = 0;
        if(push == 1 and tmpStr != ""){
            result.push_back (tmpStr);
            tmpStr = "";
        }
        push = 0;
    }
    return result;
}
