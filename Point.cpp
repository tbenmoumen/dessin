#include <stdlib.h>
#include <iostream>
#include <string>
#include<math.h>
using namespace std;

#include "Point.h"

Point::Point()
{

}


Point::Point(int x, int y, string couleur, int transparence)
{
    m_x = x ;
    m_y = y ;
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

Point::~Point()
{
}

double Point::Distance(Point* P)
{
return sqrt( pow((m_x - P->m_x),2) + pow((m_y - P->m_y),2));
}

int Point::get_coordonnees()
{
    return m_x,m_y;
}
void Point::set_coordonnees(int x,int y)
{
    m_x = x;
    m_y = y;
}

void Point::set_couleur(string couleur)
{
    m_couleur = couleur;
}

CImage* Point::dessiner_Point(CImage* img)
{
    CPixel *p = img->getPixel(m_x,m_y);
    int bp=p->Blue();
    int gp=p->Green();
    int rp=p->Red();
    int rs=floor(((100-m_transparence)*rp+m_transparence*r1)/100);
    int bs=floor(((100-m_transparence)*bp+m_transparence*b1)/100);
    int gs=floor(((100-m_transparence)*gp+m_transparence*g1)/100);
    p->RGB(rs,gs,bs);
    return img;
}
