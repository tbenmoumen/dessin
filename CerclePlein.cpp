#include <stdlib.h>
#include <iostream>
#include <string>
#include<math.h>
using namespace std;

#include "CerclePlein.h"



CerclePlein::CerclePlein(int x1, int y1, int rayon, string couleur_Fond, string couleur_Contour, int transparence)
{
    m_x = x1;
    m_y = y1;
    m_rayon  =  rayon ;
    m_Couleur_Fond = couleur_Fond;
    m_Couleur_Contour = couleur_Contour;
    m_transparence = transparence;
    if ( couleur_Fond == "ROUGE")
    {
        r1 = 255;g1= 0;b1=50;
    }
    if ( couleur_Fond == "BLANC")
    {
        r1 = 255;g1= 255;b1=255;
    }
    if ( couleur_Fond == "NOIR")
    {
        r1 = 0;g1= 0;b1=0;
    }
    if ( couleur_Fond == "VERT")
    {
        r1 = 0;g1= 128;b1=0;
    }
    if ( couleur_Fond == "BLEU")
    {
        r1 = 0;g1= 0;b1=255;
    }
    if ( couleur_Fond == "JAUNE")
    {
        r1 = 255;g1= 255;b1=50;
    }
    if ( couleur_Fond == "GRIS")
    {
        r1 = 128;g1= 128;b1=128;
    }
    if ( couleur_Fond == "MARRON")
    {
        r1 = 139;g1= 69;b1=19;
    }
    if ( couleur_Fond == "BLEU MARINE")
    {
        r1 = 0;g1= 0;b1=128;
    }
    if ( couleur_Contour == "ROUGE")
    {
        r2 = 255;g2= 0;b2=50;
    }
    if ( couleur_Contour == "BLANC")
    {
        r2 = 255;g2= 255;b2=255;
    }
    if ( couleur_Contour == "NOIR")
    {
        r2 = 0;g2= 0;b2=0;
    }
    if ( couleur_Contour == "VERT")
    {
        r2 = 0;g2= 128;b2=0;
    }
    if ( couleur_Contour == "BLEU")
    {
        r2 = 0;g2= 0;b2=255;
    }
    if ( couleur_Contour == "JAUNE")
    {
        r2 = 255;g2= 255;b2=50;
    }
    if ( couleur_Contour == "GRIS")
    {
        r2 = 128;g2= 128;b2=128;
    }
    if ( couleur_Contour == "MARRON")
    {
        r2 = 139;g2= 69;b2=19;
    }
    if ( couleur_Contour == "BLEU MARINE")
    {
        r2=0;g2=0;b2=128;
    }
}

CerclePlein::~CerclePlein()
{

}

string CerclePlein::get_Fond(){

    return m_Couleur_Fond;
}

string CerclePlein::get_Contour()
{
    return m_Couleur_Contour;
}

void CerclePlein::set_Fond(string couleur_Fond)
{

    m_Couleur_Fond=couleur_Fond;
}

void CerclePlein::set_Contour(string couleur_Contour)
{
   m_Couleur_Contour = couleur_Contour;
}
void CerclePlein::Control_Transparency(int i,int j,CImage *img)
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


CImage* CerclePlein::dessiner_CerclePlein(CImage *img)
{
    Cercle *C =new Cercle(m_x,m_y,m_rayon,m_Couleur_Contour,m_transparence);
    C->dessiner_Cercle(img);
    for(int i = 0 ; i<5000 ; i++)
    {
        for(int j=0;j <5000 ;j++)
        {
            if ( pow((i - m_x),2)+pow((j-m_y),2) <= pow(m_rayon-1,2) )
              {
                Control_Transparency(i,j,img);
              }

        }

    }
 return img;
}



