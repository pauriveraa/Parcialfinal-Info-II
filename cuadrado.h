#ifndef CUADRADO_H
#define CUADRADO_H

#include <QGraphicsItem>
#include <QPainter>
class cuadrado: public QGraphicsItem
{
public:
    cuadrado();//Constructor
    float r=30;
    float t=300;
    float posx;
    float posy;
    float radio;
    float radio2;
    void valores(float x,float y,float r1,float r2);
    void caidalibre(float vx, float vy);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    ~cuadrado(); //Destructor
};


#endif // CUADRADO_H
