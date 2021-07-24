#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<math.h>
#include <algorithm>


using namespace std;

#include "CPixel.h"
#include "CImage.h"
#include "Cercle.h"
#include "Ligne.h"
#include "Carre.h"
#include "Rectangle.h"
#include "Point.h"
#include "CarrePlein.h"
#include "RectanglePlein.h"
#include "CerclePlein.h"
#include "Dessin.h"


int i=0;
int c =0;
int cS = 0;
int r = 0;
int rS =0;
int ca =0;
int caS =0;
int li =0;
int w =0;
int t;
vector <int> Z;
vector <int> Ordre;
vector <string> Forme;
vector <string> tab;
vector <int> largeurmax;
vector <int> hauteurmax;
Dessin::Dessin(const char* filename,int echelle)
{
    m_echelle = echelle;
    LoadFromFile(filename);

}

CImage* Dessin::Taille_Control()
{
    auto LargeurImg = max_element(largeurmax.begin(),largeurmax.end());
    auto HauteurImg =max_element(hauteurmax.begin(),hauteurmax.end());
    CImage   *img = new CImage((*HauteurImg*m_echelle)+1,(*LargeurImg*m_echelle)+1);
    return img;
}
/*
bool Dessin::Tab_forme(const char* filename)
{
    string STRING;
    ifstream infile ;
    int transparence ;
    infile.open(filename) ;
    while ( !infile.eof() )
    {
        getline(infile,STRING,' ');
        tab[i] = STRING;
        getline(infile,STRING,' ');
        std::cout<<STRING<<endl;
        getline(infile,STRING,' ');
        std::cout<<STRING<<endl;
        getline(infile,STRING,',');
        std::cout<<STRING<<endl;
        int xc = stoi(STRING)*m_echelle;
        getline(infile,STRING,' ');
        std::cout<<STRING<<endl;
        getline(infile,STRING,',');
        std::cout<<STRING<<endl;
        int yc = stoi(STRING)*m_echelle;
        getline(infile,STRING,' ');
        std::cout<<STRING<<endl;
        getline(infile,STRING,',');
        std::cout<<STRING<<endl;
        int rayonc = stoi(STRING)*m_echelle;
        largeurmax.push_back(rayonc +xc);
        hauteurmax.push_back(rayonc +yc);
        getline(infile,STRING,' ');
        std::cout<<STRING<<endl;
        getline(infile,STRING,',');
        std::cout<<STRING<<endl;
        string couleurc = STRING;
        getline(infile,STRING,' ');
        std::cout<<STRING<<endl;
        getline(infile,STRING,';');

    while(STRIN != ';'){
    while(STRING == ' ' || STRING == ',' || STRING == ';')
    {


    }
    }





}

*/







bool Dessin::LoadFromFile(const char* filename)
{
    string STRING;
    ifstream infile ;
    int transparence ;
    infile.open(filename) ;
    while ( !infile.eof() )
    {
        getline(infile,STRING,' ');

    if ( STRING  == "CERCLE")
    {
        Forme.push_back(STRING);
        std::cout<<STRING<<endl;
        getline(infile,STRING,' ');
        std::cout<<STRING<<endl;
        getline(infile,STRING,',');
        std::cout<<STRING<<endl;
        int xc = stoi(STRING)*m_echelle;
        getline(infile,STRING,' ');
        std::cout<<STRING<<endl;
        getline(infile,STRING,',');
        std::cout<<STRING<<endl;
        int yc = stoi(STRING)*m_echelle;
        getline(infile,STRING,' ');
        std::cout<<STRING<<endl;
        getline(infile,STRING,',');
        std::cout<<STRING<<endl;
        int rayonc = stoi(STRING)*m_echelle;
        largeurmax.push_back(rayonc +xc);
        hauteurmax.push_back(rayonc +yc);
        getline(infile,STRING,' ');
        std::cout<<STRING<<endl;
        getline(infile,STRING,',');
        std::cout<<STRING<<endl;
        string couleurc = STRING;
        getline(infile,STRING,' ');
        std::cout<<STRING<<endl;
        getline(infile,STRING,';');
        std::cout<<STRING.length()<<endl;
        if (STRING.length() <= 3)
        {
            int pos = STRING.find(';');
            string a = STRING.substr(0,pos);
            transparence = stoi(a);
            Z.push_back(0);
            Ordre.push_back(c);
            w++;
            getline(infile,STRING);
            c++;
            std::cout<<a<<endl;
        }
        else
        {
            int pos = STRING.find(',');
            string a = STRING.substr(0,pos);
            transparence = stoi(a);
            std::cout<< a << endl;
            int pos1 = STRING.find(' ');
            a = STRING.substr(pos1+1,STRING.length());
            std::cout<< a <<endl;
            Z.push_back(stoi(a));
            Ordre.push_back(c);
            w++;
            getline(infile,STRING);
            c++;
         }
        Cercles.push_back(Cercle(xc,yc,rayonc,couleurc,transparence));
    }
    if ( STRING  == "CERCLEPLEIN")
    {
        Forme.push_back(STRING);
        std::cout<<STRING<<endl;
        getline(infile,STRING,' ');
        std::cout<<STRING<<endl;
        getline(infile,STRING,',');
        int xCp = stoi(STRING)*m_echelle;
        std::cout<<STRING<<endl;
        getline(infile,STRING,' ');
        std::cout<<STRING<<endl;
        getline(infile,STRING,',');
        int yCp = stoi(STRING)*m_echelle;
        std::cout<<STRING<<endl;
        getline(infile,STRING,' ');
        std::cout<<STRING<<endl;
        getline(infile,STRING,',');
        int rayonCp = stoi(STRING)*m_echelle;
        largeurmax.push_back(rayonCp +xCp);
        hauteurmax.push_back(rayonCp +yCp);
        std::cout<<rayonCp<<endl;
        getline(infile,STRING,' ');
        std::cout<<STRING<<endl;
        getline(infile,STRING,',');
        string couleurFondCp = STRING;
        std::cout<<couleurFondCp<<endl;
        getline(infile,STRING,' ');
        std::cout<<STRING<<endl;
        getline(infile,STRING,',');
        std::cout<<STRING<<endl;
        string couleurContourCp = STRING;
        getline(infile,STRING,' ');
        std::cout<<STRING<<endl;
        getline(infile,STRING,';');
        std::cout<<STRING.length()<<endl;
        if (STRING.length() <= 3)
        {
            int pos = STRING.find(';');
            string a = STRING.substr(0,pos);
            transparence = stoi(a);
            Z.push_back(0);
            Ordre.push_back(cS);
            w++;
            getline(infile,STRING);
            cS++;
            std::cout<<a<<endl;
        }
        else
        {
            int pos = STRING.find(',');
            string a = STRING.substr(0,pos);
            transparence = stoi(a);
            std::cout<< a << endl;
            int pos1 = STRING.find(' ');
            a = STRING.substr(pos1+1,STRING.length());
            std::cout<< a <<endl;
            Z.push_back(stoi(a));
            Ordre.push_back(cS);
            w++;
            getline(infile,STRING);
            cS++;
         }
        CerclesPleins.push_back(CerclePlein(xCp,yCp,rayonCp,couleurFondCp,couleurContourCp,transparence));
    }
    if ( STRING  == "RECTANGLE")
    {
        Forme.push_back(STRING);
        std::cout<<STRING<<endl;
        getline(infile,STRING,' ');
        std::cout<<STRING<<endl;
        getline(infile,STRING,',');
        int xR = stoi(STRING)*m_echelle;
        std::cout<<STRING<<endl;
        getline(infile,STRING,' ');
        std::cout<<STRING<<endl;
        getline(infile,STRING,',');
        int yR = stoi(STRING)*m_echelle;
        std::cout<<STRING<<endl;
        getline(infile,STRING,' ');
        std::cout<<STRING<<endl;
        getline(infile,STRING,',');
        int hR = stoi(STRING)*m_echelle;
        std::cout<<STRING<<endl;
        getline(infile,STRING,' ');
        std::cout<<STRING<<endl;
        getline(infile,STRING,',');
        int lR = stoi(STRING)*m_echelle;
        largeurmax.push_back(lR+xR);
        hauteurmax.push_back(hR+yR);
        std::cout<<STRING<<endl;
        getline(infile,STRING,' ');
        std::cout<<STRING<<endl;
        getline(infile,STRING,',');
        std::cout<<STRING<<endl;
        getline(infile,STRING,' ');
        std::cout<<STRING<<endl;
        string couleurR = STRING;
        getline(infile,STRING,';');
        std::cout<<STRING<<endl;
        if (STRING.length() <= 3)
        {
            int pos = STRING.find(';');
            string a = STRING.substr(0,pos);
            transparence = stoi(a);
            Z.push_back(0);
            Ordre.push_back(r);
            w++;
            getline(infile,STRING);
            r++;
            std::cout<<a<<endl;
        }
        else
        {
            int pos = STRING.find(',');
            string a = STRING.substr(0,pos);
            transparence = stoi(a);
            std::cout<< a << endl;
            int pos1 = STRING.find(' ');
            a = STRING.substr(pos1+1,STRING.length());
            std::cout<< a <<endl;
            Z.push_back(stoi(a));
            Ordre.push_back(r);
            w++;
            getline(infile,STRING);
            r++;
         }
        Rectangles.push_back(Rectangle(xR,yR,hR,lR,couleurR,transparence));
    }
    if ( STRING  == "RECTANGLEPLEIN")
    {
        Forme.push_back(STRING);
        std::cout<<STRING<<endl;
        getline(infile,STRING,' ');
        std::cout<<STRING<<endl;
        getline(infile,STRING,',');
        int xRp = stoi(STRING)*m_echelle;
        std::cout<<xRp<<endl;
        getline(infile,STRING,' ');
        std::cout<<STRING<<endl;
        getline(infile,STRING,',');
        int yRp = stoi(STRING)*m_echelle;
        std::cout<<yRp<<endl;
        getline(infile,STRING,' ');
        std::cout<<STRING<<endl;
        getline(infile,STRING,',');
        int hRp = stoi(STRING)*m_echelle;
        std::cout<<hRp<<endl;
        getline(infile,STRING,' ');
        std::cout<<STRING<<endl;
        getline(infile,STRING,',');
        int lRp = stoi(STRING)*m_echelle;
        largeurmax.push_back(lRp+xRp);
        hauteurmax.push_back(hRp+yRp);
        std::cout<<lRp<<endl;
        getline(infile,STRING,' ');
        std::cout<<STRING<<endl;
        getline(infile,STRING,',');
        string couleurFondRp = STRING;
        std::cout<<couleurFondRp<<endl;
        getline(infile,STRING,' ');
        std::cout<<STRING<<endl;
        getline(infile,STRING,',');
        string couleurContourRp = STRING;
        std::cout<<couleurContourRp<<endl;
        getline(infile,STRING,' ');
        std::cout<<STRING<<endl;
        getline(infile,STRING,';');
        if (STRING.length() <= 3)
        {
            int pos = STRING.find(';');
            string a = STRING.substr(0,pos);
            transparence = stoi(a);
            Z.push_back(0);
            Ordre.push_back(rS);
            w++;
            getline(infile,STRING);
            rS++;
        }
        else
        {
            int pos = STRING.find(',');
            string a = STRING.substr(0,pos);
            transparence = stoi(a);
            std::cout<< a << endl;
            int pos1 = STRING.find(' ');
            a = STRING.substr(pos1+1,STRING.length());
            std::cout<< a <<endl;
            Z.push_back(stoi(a));
            Ordre.push_back(rS);
            w++;
            getline(infile,STRING);
            rS++;
         }
        RectanglesPleins.push_back(RectanglePlein(xRp,yRp,hRp,lRp,couleurFondRp,couleurContourRp,transparence));
     }

     if ( STRING  == "CARRE")
    {
         Forme.push_back(STRING);
        std::cout<<STRING<<endl;
        getline(infile,STRING,' ');
        std::cout<<STRING<<endl;
        getline(infile,STRING,',');
        int xCa = stoi(STRING)*m_echelle;
        std::cout<<STRING<<endl;
        getline(infile,STRING,' ');
        std::cout<<STRING<<endl;
        getline(infile,STRING,',');
        int yCa = stoi(STRING)*m_echelle;
        std::cout<<STRING<<endl;
        getline(infile,STRING,' ');
        std::cout<<STRING<<endl;
        getline(infile,STRING,',');
        int a = stoi(STRING)*m_echelle;
        largeurmax.push_back(a+xCa);
        hauteurmax.push_back(a+yCa);
        std::cout<<STRING<<endl;
        getline(infile,STRING,' ');
        std::cout<<STRING<<endl;
        getline(infile,STRING,',');
        string couleurCa = STRING;
        std::cout<<STRING<<endl;
        getline(infile,STRING,' ');
        std::cout<<STRING<<endl;
        getline(infile,STRING,';');
        std::cout<<STRING.length()<<endl;
        if (STRING.length() <= 3)
        {
            int pos = STRING.find(';');
            string a = STRING.substr(0,pos);
            transparence = stoi(a);
            Z.push_back(0);
            Ordre.push_back(ca);
            w++;
            getline(infile,STRING);
            ca++;
            std::cout<<a<<endl;
        }
        else
        {
            int pos = STRING.find(',');
            string a = STRING.substr(0,pos);
            transparence = stoi(a);
            std::cout<< a << endl;
            int pos1 = STRING.find(' ');
            a = STRING.substr(pos1+1,STRING.length());
            std::cout<< a <<endl;
            Z.push_back(stoi(a));
            Ordre.push_back(ca);
            w++;
            getline(infile,STRING);
            ca++;
         }
        Carres.push_back(Carre(xCa,yCa,a,couleurCa,transparence));
    }
    if ( STRING  == "CARREPLEIN")
    {
        Forme.push_back(STRING);
        getline(infile,STRING,' ');
        getline(infile,STRING,',');
        int xCap = stoi(STRING)*m_echelle;
        getline(infile,STRING,' ');
        getline(infile,STRING,',');
        int yCap = stoi(STRING)*m_echelle;
        getline(infile,STRING,' ');
        getline(infile,STRING,',');
        int aP = stoi(STRING)*m_echelle;
        largeurmax.push_back(aP+xCap);
        hauteurmax.push_back(aP+yCap);
        getline(infile,STRING,' ');
        getline(infile,STRING,',');
        string couleurFondCap = STRING;
        getline(infile,STRING,' ');
        getline(infile,STRING,',');
        string couleurContourCap = STRING;
        getline(infile,STRING,' ');
        getline(infile,STRING,';');
        std::cout<<STRING.length()<<endl;
        if (STRING.length() <= 3)
        {
            int pos = STRING.find(';');
            string a = STRING.substr(0,pos);
            transparence = stoi(a);
            Z.push_back(0);
            Ordre.push_back(caS);
            w++;
            getline(infile,STRING);
            caS++;
            std::cout<<a<<endl;
        }
        else
        {
            int pos = STRING.find(',');
            string a = STRING.substr(0,pos);
            transparence = stoi(a);
            std::cout<< a << endl;
            int pos1 = STRING.find(' ');
            a = STRING.substr(pos1+1,STRING.length());
            std::cout<< a <<endl;
            Z.push_back(stoi(a));
            Ordre.push_back(caS);
            w++;
            getline(infile,STRING);
            caS++;
         }
        CarresPleins.push_back(CarrePlein(xCap,yCap,aP,couleurFondCap,couleurContourCap,transparence));
    }
   if ( STRING  == "LIGNE")
    {
        Forme.push_back(STRING);
        std::cout<<STRING<<endl;
        std::cout<<"BOOF2"<<endl;
        getline(infile,STRING,' ');
        std::cout<<STRING<<endl;
        getline(infile,STRING,',');
        std::cout<<STRING<<endl;
        int xl1 = stoi(STRING)*m_echelle;
        getline(infile,STRING,' ');
        std::cout<<STRING<<endl;
        getline(infile,STRING,',');
        std::cout<<STRING<<endl;
        int yl1 = stoi(STRING)*m_echelle;
        getline(infile,STRING,' ');
        std::cout<<STRING<<endl;
        getline(infile,STRING,',');
        std::cout<<STRING<<endl;
        int xl2 = stoi(STRING)*m_echelle;
        getline(infile,STRING,' ');
        std::cout<<STRING<<endl;
        getline(infile,STRING,',');
        std::cout<<STRING<<endl;
        int yl2 = stoi(STRING)*m_echelle;
        getline(infile,STRING,' ');
        largeurmax.push_back(max(xl1,xl2));
        hauteurmax.push_back(max(yl1,yl2));
        std::cout<<STRING<<endl;
        getline(infile,STRING,',');
        string couleurl = STRING;
        std::cout<<STRING<<endl;
        getline(infile,STRING,' ');
        std::cout<<STRING<<endl;
        getline(infile,STRING,';');
        std::cout<<STRING.length()<<endl;
        if (STRING.length() <= 3)
        {
            int pos = STRING.find(';');
            string a = STRING.substr(0,pos);
            transparence = stoi(a);
            Z.push_back(0);
            Ordre.push_back(li);
            w++;
            getline(infile,STRING);
            li++;
            std::cout<<a<<endl;
        }
        else
        {
            int pos = STRING.find(',');
            string a = STRING.substr(0,pos);
            transparence = stoi(a);
            std::cout<< a << endl;
            int pos1 = STRING.find(' ');
            a = STRING.substr(pos1+1,STRING.length());
            std::cout<< a <<endl;
            Z.push_back(stoi(a));
            Ordre.push_back(li);
            w++;
            getline(infile,STRING);
            li++;
         }
        Lignes.push_back(Ligne(xl1,yl1,xl2,yl2,couleurl,transparence));
    }



 }

 infile.close();
 return true;
}

Dessin::~Dessin()
{
}

CImage* Dessin::Draw(CImage *img)
{
    int t=0;
    for( int i=0;i < Z.size();i++){
        for( int j=0;j<Z.size();j++)
        {
            if (Z[j]==t){
                if(Forme[j]=="CERCLE"){
                    Cercles[Ordre[j]].dessiner_Cercle(img);
                }
                if(Forme[j]=="CERCLEPLEIN"){
                    CerclesPleins[Ordre[j]].dessiner_CerclePlein(img);
                }
                if(Forme[j]=="RECTANGLE"){
                    Rectangles[Ordre[j]].dessiner_Rect(img);
                }
                if(Forme[j]=="RECTANGLEPLEIN"){
                    RectanglesPleins[Ordre[j]].dessiner_Contour(img);
                    RectanglesPleins[Ordre[j]].remplissage(img);
                }
                if(Forme[j]=="CARRE"){
                    Carres[Ordre[j]].dessiner_Carre(img);
                }
                if(Forme[j]=="CARREPLEIN"){
                    CarresPleins[Ordre[j]].dessiner_Contour(img);
                    CarresPleins[Ordre[j]].remplissage(img);
                }
                if(Forme[j]=="LIGNE"){
                    Lignes[Ordre[j]].dessiner_Ligne(img);
                }

            }
        }
        t++;
    }
    return img;
}
