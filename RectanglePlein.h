#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

#include "Rectangle.h"


#ifndef RECTANGLES_H
#define RECTANGLES_H

class RectanglePlein : public Rectangle
{
    private:
        string m_Couleur_Fond;
        string m_Couleur_Contour;
        int r1,g1,b1,r2,g2,b2;
        int m_transparence;
        int m_xr1;
        int m_yr1;
        int m_H;
        int m_L;
    public:
        RectanglePlein(int x1, int y1, int H, int L, string couleur_Fond, string couleur_Contour, int transparence);
        CImage* dessiner_Contour(CImage *img);
        CImage* remplissage(CImage *img);
        void Control_Transparency(int i,int j,CImage *img);

};
#endif // RECTANGLES_H
