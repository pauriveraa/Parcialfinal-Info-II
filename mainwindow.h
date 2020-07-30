#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>
#include <list>
#include <cstdlib>
#include <ctime>
#include "bola.h"
#include <iostream>
#include "objetocuadrado.h"
#include "cuadrado.h"
#include "muros.h"
#include <QMessageBox>

#define LEN 500
#define HEI 300
#define L -1

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



private slots:
    void actualizar();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void comenzar();//Las funciones que van a actuar de acuerdo a la señal
    void detener();
    void reiniciar();
    void mostrar();

    void on_start_clicked();

public:
    Ui::MainWindow *ui;
    QTimer *timer;              //timer para los intervalos de tiempo entre cada frame
     QTimer *timer1;
    QGraphicsScene *scene;      //scene que muestra los objetos animados
    //float dt;                   //intervalo de tiempo entre frames
   list<Bola*> bolas;
   int minutos, segundos, centesimas;



private:
 Bola *esfera[3];
 Bola *b;
 cuadrado *obstaculo1;
   int contador=0;

    bool colision;
    QMessageBox msgBox;
   // int a=0;
};

#endif // MAINWINDOW_H
