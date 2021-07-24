#include <stdlib.h>
#include <iostream>
#include <string>
#include<math.h>
using namespace std;

#include "Rectangle.h"

Rectangle::Rectangle()
{

}


Rectangle::Rectangle(int x1, int y1, int H, int L, string couleur, int transparence)
{
        m_xr1 = x1;
        m_yr1 = y1;
        m_H   = H;
        m_L   = L;
        m_couleur =couleur ;
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


Rectangle::~Rectangle()
{
}

int Rectangle::get_coordonnes(){

    return m_xr1,m_yr1;
}
int Rectangle::get_dimensions()
{
    return m_H,m_L;
}

void Rectangle::set_coordonnees(int x1, int y1)
{
        m_xr1 = x1;
        m_yr1 = y1;
}


void Rectangle::set_dimensions(int H, int L)
{
    m_H = H;
    m_L = L;
}
void Rectangle::Control_Transparency(int i,int j,CImage *img)
{
    CPixel *p = img ->getPixel(i,j);
    int bp=p->Blue();
    int gp=p->Green();
    int rp=p->Red();
    int rs=floor(((100-m_transparence)*rp+m_transparence*r1)/100);
    int bs=floor(((100-m_transparence)*bp+m_transparence*b1)/100);
    int gs=floor(((100-m_transparence)*gp+m_transparence*g1)/100);
    p->RGB(rs,gs,bs);
  }
CImage* Rectangle::dessiner_Rect(CImage *img)
{
    for(int r = m_xr1 ; r <= m_xr1 + m_L ; r++ )
    {
        Control_Transparency(r,m_yr1,img);
    }
    for(int j = m_xr1 ; j <= m_xr1 + m_L ; j++ )
    {
        Control_Transparency(j,m_yr1+m_H,img);
    }
    for(int k =m_yr1 ; k <= m_yr1 + m_H ; k++ )
    {
        Control_Transparency(m_xr1,k,img);    }
    for(int l = m_yr1 ; l <= m_yr1 + m_H ; l++ )
    {
        Control_Transparency(m_xr1+m_L,l,img);
    }

return img;

}
