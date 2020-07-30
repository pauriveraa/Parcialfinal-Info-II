#ifndef ESFERA_H
#define ESFERA_H
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>

class Esfera: public QGraphicsItem
{

public:
    Esfera(float r, float _x,float _y);
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);


private:
   float radio;
   float x;
   float y;






};
