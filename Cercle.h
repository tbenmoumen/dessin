#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>


using namespace std;


#include "CPixel.h"
#include "CImage.h"


#ifndef CERCLE_H
#define CERCLE_H


class Cercle
           {
      private:
        int m_x,m_y;
        int m_rayon;
        int r1,g1,b1;
        int m_transparence;
        int m_echelle;
      public:
        Cercle();
        Cercle(int x,int y,int rayon,string couleur,int transparence);
        ~Cercle();
        int get_coordonneeX();
        int get_coordonneeY();
        int get_rayon();
        void set_coordonnees(int x,int y);
        void set_rayon(int rayon);
        CImage* dessiner_Cercle(CImage *img);
        void Control_Transparency(int i,int j,CImage *img);
            };
#endif //CERCLE_H
