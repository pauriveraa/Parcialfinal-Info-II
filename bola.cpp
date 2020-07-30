#include "bola.h"
#include <QDebug>
#include <fstream>
#include <iostream>
#include <QGraphicsTextItem>
#include <QFont>
#include <QPainter>
using namespace std;


Bola::Bola(float r_, float x_, float y_, float vx_, float vy_, float e_, float M_,float Cf_):
    r(r_),x(x_),y(y_),vx(vx_),vy(vy_),e(e_),M(M_),Cf(Cf_)
{  ofstream Fichero;
   Fichero.open("a.txt");
    float a,b,c,d,e;
    a=r;
    b=x;
    c=y;
    d=vx;
    e=vy;
    qDebug()<<r<<"  "<<x<<"  "<<y<<"  "<<vx<<"  "<<vy<<"  "<<e<<"  "<<M<<"  "<<Cf;
    Fichero << b<<'\t' << c;
     Fichero << endl;

     setFlag(QGraphicsItem::ItemIsMovable);

}

void Bola::desaceleracionX(){
    int Angulo,Velocidad;
    Velocidad = sqrt(pow(vx,2)+pow(vy,2));
    Angulo = atan2(vy,vx);
    Dx = -1*((Cf*pow(Velocidad,2)*pow(r,2))/M)*cos(Angulo);
}

void Bola::desaceleracionY(){
    int Angulo,Velocidad;
    Velocidad = sqrt(pow(vx,2)+pow(vy,2) );
    Angulo = atan2(vy,vx);
    Dy = -1*((Cf*pow(Velocidad,2)*pow(r,2))/M)*sin(Angulo)-GRAV;
}

void Bola::mover()
{
    vx=vx-(Dx*DT);
    vy=vy-(Dy*DT)-0.1;
    x=x+(vx*DT)+(Dx*pow(DT,2)/2);
    y=y+(vy*DT)+(Dy*pow(DT,2)/2);

    setPos(x,-y);
    rR=r;
    xX=x;
    yY=y;
    vxX=vx;
    vyY=vy;


}

void Bola::choque(int x0, int y0, int w, int h)
{


    if(x-r<=x0){
        vx*=-e;
        x=x0+r;



    }
    if(x+r>=x0+w){
        vx*=-e;
        x=x0+w-r;


    }
    if(y-r<=y0){
        vy*=-e;
        y=y0+r;


    }
    if(y+r>=y0+h){
        vy*=-e;
        y=y0+h-r;


    }




}


QRectF Bola::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void Bola::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->drawEllipse(boundingRect());
}

