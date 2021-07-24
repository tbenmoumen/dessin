#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>



using namespace std;
#include "Cercle.h"
#include "CImage.h"



#ifndef CERCLES_H
#define CERCLES_H


class CerclePlein : public Cercle
{
    private:
        string m_Couleur_Fond;
        string m_Couleur_Contour;
        int m_transparence;
        int r1,b1,g1,r2,b2,g2;
        int m_x,m_y;
        int m_rayon;
    public:
        CerclePlein(int x1, int y1, int rayon, string couleur_Fond, string couleur_Contour, int transparence);
        ~CerclePlein();
        CImage* dessiner_CerclePlein(CImage *img);
        string get_Fond();
        string get_Contour();
        void Control_Transparency(int i,int j,CImage *img);
        void set_Fond(string couleur_Fond);
        void set_Contour(string couleur_Contour);
};





#endif // CERCLES_H
