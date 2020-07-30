#ifndef MUROS_H
#define MUROS_H
#include <QGraphicsItem>
#include <QPainter>


class Muro:public QGraphicsItem
{
public:

    float posx;
    float posy;
    float radio;
    float radio2;
    Muro();
    void valores(float x,float y,float r1,float r2);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    ~Muro();
};

#endif // MUROS_H
