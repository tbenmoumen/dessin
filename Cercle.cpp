#include <stdlib.h>
#include <iostream>
#include <string>
#include<math.h>
using namespace std;

#include "Cercle.h"

Cercle::Cercle()
{
}

Cercle::Cercle(int x, int y, int rayon, string couleur, int transparence)
{
    m_x = x;
    m_y = y;
    m_rayon = rayon;
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

Cercle::~Cercle()
{

}

int Cercle::get_coordonneeY(){

    return m_y;
}
int Cercle::get_coordonneeX()
{

    return m_x;
}
int Cercle::get_rayon()
{
    return m_rayon;
}

void Cercle::set_coordonnees(int x,int y)
{
        m_x = x;
        m_y = y;
}

void Cercle::set_rayon(int rayon)
{
    m_rayon=rayon;
}

void Cercle::Control_Transparency(int i,int j,CImage *img)
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
CImage* Cercle::dessiner_Cercle(CImage *img)
{
  for(int j=0;j<=5000;j++)
   {
     for(int i=0;i<=5000;i++)
      {
         if ( pow((i -m_x),2)+pow((j-m_y),2) <= pow(m_rayon,2) && pow(m_rayon-1,2) <= pow((i - m_x),2)+pow((j-m_y),2)   )
           {
                Control_Transparency(i,j,img);
           }


      }
     }

return img;

}
