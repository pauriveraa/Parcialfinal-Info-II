#ifndef BOLA_H
#define BOLA_H

#include <cmath>
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>


#include <QGraphicsTextItem>

#define DT 0.1
#define GRAV 10;

class Bola: public QGraphicsItem
{
public:
    Bola(float r_, float x_, float y_, float vx_, float vy_, float e_=1, float M_=0, float Cf_=0);

    void mover();
    void choque(int x0, int y0, int w, int h);
    void set_vel(float v, float a);
    void set_pos(float x_, float y_);
    void desaceleracionX();
    void desaceleracionY();


    QRectF boundingRect() const;    //necesario definirla, devuelve el rectangulo que encierra el objeto
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //define como se pintara el objeto


float ui;
    float r;
    float x;
    float y;
    float vx;
    float vy;
    float e;
    float M;
    float Cf;
    float Dx;
    float Dy;
    float rR;
    float xX;
    float yY;
    float vxX;
    float vyY;
    int contadorbola=0;


  bool colision=true;

};

#endif // BOLA_H
