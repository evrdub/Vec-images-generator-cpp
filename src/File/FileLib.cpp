#include "FileLib.h"

bool readFile(string filename){
    string currentLine;
    ifstream infile;
    infile.open(filename);
    if(infile.is_open()){
        getline(infile,currentLine);

        if(currentLine[0] != '#'){
            
        }

        infile.close();
        return true;
    }
    else{
        return false;
    }
}

