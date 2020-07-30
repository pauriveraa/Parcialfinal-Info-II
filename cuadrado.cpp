#include "cuadrado.h"
#include <QDebug>
#include <fstream>
#include <iostream>
using namespace std;

Cuadrado::Cuadrado(float r_, float x_, float y_, float vx_, float vy_, float e_, float M_,float Cf_):
    r1(r_),x1(x_),y1(y_),vx1(vx_),vy1(vy_),e1(e_),M1(M_),Cf1(Cf_)
{   ofstream Fichero;
    Fichero.open("b.txt");
     float a,b,c,d,e;

     a=r1;
     b=x1;
     c=y1;
     d=vx1;
     e=vy1;





    qDebug()<<r1<<"  "<<x1<<"  "<<y1<<"  "<<vx1<<"  "<<vy1<<"  "<<e1<<"  "<<M1<<"  "<<Cf1;
    Fichero << a<<'\t'<< b<<'\t' << c<<'\t'<< d<<'\t' << e;
     Fichero << endl;
    setFlag(QGraphicsItem::ItemIsMovable);
}

void Cuadrado::desaceleracionX(){
    int Angulo,Velocidad;
    Velocidad = sqrt(pow(vx1,2)+pow(vy1,2));
    Angulo = atan2(vy1,vx1);
    Dx1 = -1*((Cf1*pow(Velocidad,2)*pow(r1,2))/M1)*cos(Angulo);
}

void Cuadrado::desaceleracionY(){
    int Angulo,Velocidad;
    Velocidad = sqrt(pow(vx1,2)+pow(vy1,2) );
    Angulo = atan2(vy1,vx1);
    Dy1 = -1*((Cf1*pow(Velocidad,2)*pow(r1,2))/M1)*sin(Angulo)-GRAV;
}

void Cuadrado::mover()
{
    vx1=vx1-(Dx1*DT);
    vy1=vy1-(Dy1*DT)-0.1;
    x1=x1+(vx1*DT)+(Dx1*pow(DT,2)/2);
    y1=y1+(vy1*DT)+(Dy1*pow(DT,2)/2);

    setPos(x1,-y1);



}

void Cuadrado::choque(int x0, int y0, int w, int h)
{
    if(x1-r1<=x0){
        vx1*=-e1;
        x1=x0+r1;
        contador1+=1;
        qDebug()<<contador1;
    }
    if(x1+r1>=x0+w){
        vx1*=-e1;
        x1=x0+w-r1;
        contador1+=1;
        qDebug()<<contador1;
    }
    if(y1-r1<=y0){
        vy1*=-e1;
        y1=y0+r1;
        contador1+=1;
        qDebug()<<contador1;
    }
    if(y1+r1>=y0+h){
        vy1*=-e1;
        y1=y0+h-r1 ;
        contador1+=1;
        qDebug()<<contador1;
    }
}


QRectF Cuadrado::boundingRect() const
{
    return QRectF(-r1,-r1,2*r1,2*r1);
}

void Cuadrado::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->drawRect(boundingRect());
}
int Cuadrado::a(){
    ui=x1;
    return ui;

}


