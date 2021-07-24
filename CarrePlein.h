#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>


using namespace std;

#include "Carre.h"


#ifndef CARRES_H
#define CARRES_H

class CarrePlein : public Carre{
    private:
        string m_Couleur_Fond;
        string m_Couleur_Contour;
        int m_transparence;
        int r1,g1,b1,r2,g2,b2;
        int m_a,m_x,m_y;
        int m_echelle;

    public:
         CarrePlein(int x1, int y1,int a, string couleur_Fond, string couleur_Contour,int transparence);
         ~CarrePlein();
         CImage* remplissage(CImage *img);
         CImage* dessiner_Contour(CImage *img);
         void Control_Transparency(int i,int j,CImage *img);
};
#endif //CARRES_H
