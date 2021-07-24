#include <stdlib.h>
#include <iostream>
#include <string>
#include<math.h>
using namespace std;

#include "Rectangle.h"
#include "Carre.h"

Carre::Carre()
{

}


Carre::Carre(int x, int y, int a, string couleur, int transparence)

{
     m_a = a;
     m_x = x;
     m_y = y;
     m_transparence = transparence;
     if ( couleur == "ROUGE")
     {
         r1 = 255;g1= 0;b1=50;
     }
     if ( couleur == "BLANC")
     {
         r1 = 255;g1= 255;b1=255;
     }
     if ( couleur == "NOIR")
     {
         r1 = 0;g1= 0;b1=0;
     }
     if ( couleur == "VERT")
     {
         r1 = 0;g1= 128;b1=0;
     }
     if ( couleur == "BLEU")
     {
         r1 = 0;g1= 0;b1=255;
     }
     if ( couleur == "JAUNE")
     {
         r1 = 255;g1= 255;b1=50;
     }
     if ( couleur == "GRIS")
     {
         r1 = 128;g1= 128;b1=128;
     }
     if ( couleur == "MARRON")
     {
         r1 = 139;g1= 69;b1=19;
     }
     if ( couleur == "BLEU MARINE")
     {
         r1 = 0;g1= 0;b1=128;
     }
}


Carre::~Carre()
{

}

int Carre::get_coordonnees(){

    return m_x,m_y;
}
int Carre::get_arrete()
{
    return m_a;
}

void Carre::set_coordonnees(int x, int y)
{
        m_x = x;
        m_y = y;
}


void Carre::set_arrete(int a)
{
    m_a = a ;
}


CImage* Carre::dessiner_Carre(CImage *img)
{
    Rectangle* R =new Rectangle(m_x,m_y,m_a,m_a,m_couleur,m_transparence);
    R->dessiner_Rect(img);
    return img;
}
