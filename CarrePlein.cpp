#include <stdlib.h>
#include <iostream>
#include <string>
#include<math.h>
using namespace std;

#include "Carre.h"
#include "CarrePlein.h"


CarrePlein::CarrePlein(int x1, int y1, int a, string couleur_Fond, string couleur_Contour, int transparence)
{
            m_Couleur_Fond = couleur_Fond;
            m_Couleur_Contour = couleur_Contour;
            m_x = x1;
            m_y = y1;
            m_a  = a;
            r1 = 255;g1= 100;b1=50;
            r2 = 0;g2 = 0; b2=0;
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

CarrePlein::~CarrePlein()
{

}

void CarrePlein::Control_Transparency(int i,int j,CImage *img)
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


CImage* CarrePlein::remplissage(CImage *img)
{
      for( int i = m_x +1 ; i < m_x +m_a  ; i++ )
      {
          for ( int j= m_y + 1 ; j < m_y + m_a ; j++ )
          {
             Control_Transparency(i,j,img);
          }
      }
      return img;
}






CImage* CarrePlein::dessiner_Contour(CImage *img)
{
    Carre* R =new Carre(m_x,m_y,m_a,m_Couleur_Contour,m_transparence);
    R->dessiner_Carre(img);
    return img;
}

