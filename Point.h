#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;



#ifndef POINT_H
#define POINT_H

#include "CPixel.h"
#include "CImage.h"

class Point
        {
        private:
            int m_x,m_y,r1,g1,b1;
            string m_couleur;
            int m_transparence;
        public:
            Point();
            Point(int x,int y,string couleur,int transparence);
            ~Point();
            double Distance(Point* P);
            int get_coordonnees();
            void set_coordonnees(int x,int y);
            void set_couleur(string couleur);
            CImage* dessiner_Point(CImage* img);
        };
#endif // POINT_H
