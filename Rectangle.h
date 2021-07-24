#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

#include "CPixel.h"
#include "CImage.h"

#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle{
         private :
            int m_xr1;
            int m_yr1;
            int m_H;
            int m_L;
            int r1,g1,b1;
            string m_couleur;
            int m_transparence;
        public:
            Rectangle();
            Rectangle(int x1, int y1, int H, int L, string couleur, int transparence);
            ~Rectangle();
            int get_coordonnes();
            int get_dimensions();
            void set_coordonnees(int x1,int y1);
            void Control_Transparency(int i,int j,CImage *img);
            void set_dimensions(int H,int L);
            CImage* dessiner_Rect(CImage *img);
                };
#endif // RECTANGLE_H
