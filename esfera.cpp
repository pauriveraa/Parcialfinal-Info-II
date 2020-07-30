#include "esfera.h"

Esfera::Esfera(float r, float _x, float _y)
{
radio=r;
x=_x;
y=_y;



}
QRectF Esfera::boundingRect() const
{

  return QRectF(x,y,2*radio,2*radio);

}

void Esfera::paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::darkGreen);
    painter->drawEllipse(boundingRect());

}
