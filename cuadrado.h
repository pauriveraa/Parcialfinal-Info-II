#ifndef CUADRADO_H
#define CUADRADO_H




#include <cmath>
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>

#define DT 0.1
#define GRAV 10;

class Cuadrado: public QGraphicsItem
{
public:
    Cuadrado(float r_=10, float x_=0, float y_=0, float vx_=0, float vy_=0, float e_=1, float M_=0, float Cf_=0);
    void mover();
    void choque(int x0, int y0, int w, int h);
    void set_vel(float v, float a);
    void set_pos(float x_, float y_);
    void desaceleracionX();
    void desaceleracionY();


    QRectF boundingRect() const;    //necesario definirla, devuelve el rectangulo que encierra el objeto
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //define como se pintara el objeto

    int a();
float ui;
    float r1;
    float x1;
    float y1;
    float vx1;
    float vy1;
    float e1;
    float M1;
    float Cf1;
    float Dx1;
    float Dy1;
    float rR1;
    float xX1;
    float yY1;
    float vxX1;
    float vyY1;
int contador1=0;


};

























#endif // CUADRADO_H
