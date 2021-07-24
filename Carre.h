#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;


#include "CPixel.h"
#include "CImage.h"
#include "Rectangle.h"


#ifndef CARRE_H
#define CARRE_H

class Carre : public Rectangle
            {
       private:
        int m_a,m_x,m_y;
        string m_couleur;
        int m_transparence;
        int m_echelle;
        int r1,g1,b1;
       public:
        Carre();
        Carre(int a,int x, int y,string couleur,int transparence);
        ~Carre();
        int get_arrete();
        int get_coordonnees();
        void set_arrete( int a);
        void set_coordonnees(int x, int y);
        CImage* dessiner_Carre(CImage *img);
            };
#endif // CARRÉ_H
