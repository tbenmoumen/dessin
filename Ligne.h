#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;



#ifndef LIGNE_H
#define LIGNE_H

#include "CPixel.h"
#include "CImage.h"

class Ligne{
private:
     int m_x1,m_x2;
     int m_y1,m_y2;
     int r1,g1,b1;
     string m_couleur;
     int m_transparence;
public:
     Ligne();
     Ligne(int x1, int y1, int x2, int y2, string couleur,int transparence);
     ~Ligne();
     int get_coordonnes();
     float get_longueur();
     void Control_Transparency(int i,int j,CImage *img);
     void set_coordonnes(int x1, int x2, int y1, int y2);
     CImage* dessiner_Ligne(CImage *img);
};

#endif // LIGNE_H
