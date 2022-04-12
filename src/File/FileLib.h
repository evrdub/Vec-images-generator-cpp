#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
#include <fstream>
#include <ctime>
#include <sstream>


#include "../Format/CBitmap.h"
#include "../Formes/Forme.h"
#include "../Formes/Point.h"
#include "../Formes/Ligne.h"
#include "../Formes/Carre.h"
#include "../Formes/Rectangle.h"
#include "../Formes/RectangleS.h"
#include "../Formes/CarreS.h"
#include "../Formes/Cercle.h"
#include "../Formes/CercleS.h"
#include "../Formes/Forme.h"

using namespace std;

#ifndef FILELIB_H_
#define FILELIB_H_

vector<Forme * > readFile(string filename);
//vector<vector<Forme * >> readFile(string filename);
vector<string> split (string s, string delim, string ignoreList);

#endif /*FILELIB_H_*/