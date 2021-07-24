#include <stdlib.h>
#include <iostream>
#include <string>
#include<math.h>
using namespace std;

#include "Ligne.h"

Ligne::Ligne()
{

}


Ligne::Ligne(int x1, int y1, int x2, int y2, string couleur, int transparence)
{
        m_x1 = x1;
        m_x2 = x2;
        m_y1 = y1;
        m_y2 = y2;
        m_couleur = couleur;
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

Ligne::~Ligne()
{

}

int Ligne::get_coordonnes()
{

    return m_x1,m_y1,m_x2,m_y2;
}

float Ligne::get_longueur()
{
    return sqrt(pow((m_x1 - m_x2),2) + pow((m_y1-m_y2),2));
}

void Ligne::set_coordonnes(int x1, int x2, int y1, int y2)
{
        m_x1 = x1;
        m_x2 = x2;
        m_y1 = y1;
        m_y2 = y2;
}


void Ligne::Control_Transparency(int i,int j,CImage *img)
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
CImage* Ligne::dessiner_Ligne(CImage *img)
{
        int x1,x2,y1,y2;
        int x,y,dx,dy,dx1,dy1,px,py,xe,ye,i;
        x1=m_x1;
        x2=m_x2;
        y1=m_y1;
        y2=m_y2;
        dx=x2-x1;
        dy=y2-y1;
        dx1=fabs(dx);
        dy1=fabs(dy);
        px=2*dy1-dx1;
        py=2*dx1-dy1;
        if(dy1<=dx1)
        {
                if(dx>=0)
                {
                        x=x1;
                        y=y1;
                        xe=x2;
                }
         else
         {
                x=x2;
                y=y2;
                xe=x1;
        }
Control_Transparency(x,y,img);
         for(i=0;x<xe;i++)
     {
                 x=x+1;
                 if(px<0)
                 {
                px=px+2*dy1;
                 }
                 else
                 {
                if((dx<0 && dy<0) || (dx>0 && dy>0))
                {
                        y=y+1;
                }
                        else
                {
                y=y-1;
                }
                px=px+2*(dy1-dx1);
                 }
                 Control_Transparency(x,y,img);

     }
     }
     else
         {
  if(dy>=0)
  {
   x=x1;
   y=y1;
   ye=y2;
  }
  else
  {
   x=x2;
   y=y2;
   ye=y1;
  }
  Control_Transparency(x,y,img);

  for(i=0;y<ye;i++)
  {
   y=y+1;
   if(py<=0)
   {
    py=py+2*dx1;
   }
   else
   {
    if((dx<0 && dy<0) || (dx>0 && dy>0))
    {
     x=x+1;
    }
    else
    {
     x=x-1;
    }
    py=py+2*(dx1-dy1);
   }
   Control_Transparency(x,y,img);

  }
 }
    return img;
}
