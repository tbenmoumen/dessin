#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include<vector>
using namespace std;

#include "CPixel.h"
#include "CImage.h"
#include "Cercle.h"
#include "Ligne.h"
#include "Carre.h"
#include "Rectangle.h"
#include "Point.h"
#include "CarrePlein.h"
#include "RectanglePlein.h"
#include "CerclePlein.h"

#ifndef DESSIN_H
#define DESSIN_H

class Dessin
{
private:
    vector <Cercle> Cercles;
    vector <CerclePlein> CerclesPleins;
    vector <Rectangle> Rectangles;
    vector <RectanglePlein> RectanglesPleins;
    vector <Carre> Carres;
    vector <CarrePlein> CarresPleins;
    vector <Ligne> Lignes;
    vector <Point> Points;
    int m_echelle;
public:
    Dessin(const char* filename,int echelle);
    ~Dessin();
    CImage* Taille_Control();
    bool LoadFromFile(const char* filename);
    CImage* Draw(CImage *img);
};

#endif // DESSIN_H
