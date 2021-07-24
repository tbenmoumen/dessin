#include <stdlib.h>
#include <iostream>
#include <string>
#include<math.h>
using namespace std;

#include "Rectangle.h"
#include "RectanglePlein.h"


RectanglePlein::RectanglePlein(int x1, int y1, int H, int L, string couleur_Fond, string couleur_Contour, int transparence)
{
            m_Couleur_Fond = couleur_Fond;
            m_Couleur_Contour = couleur_Contour;
            r1 = 255;g1= 100;b1=50;
            r2 = 0;g2 = 0; b2=0;
            m_transparence = transparence ;
            m_xr1 = x1;
            m_yr1 = y1;
            m_H   = H;
            m_L   = L;
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


}

CImage* RectanglePlein::remplissage(CImage *img)
{
      for( int i = m_xr1+1 ; i < m_xr1 +m_L  ; i++ )
      {
          for ( int j= m_yr1+1 ; j < m_yr1 + m_H; j++ )
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
          }

      return img;
}







CImage* RectanglePlein::dessiner_Contour(CImage *img)
{
        Rectangle* R =new Rectangle(m_xr1,m_yr1,m_H,m_L,m_Couleur_Contour,m_transparence);
        R->dessiner_Rect(img);
        return img;
}

