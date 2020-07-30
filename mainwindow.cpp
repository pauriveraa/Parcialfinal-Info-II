#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cuadrado.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene=new QGraphicsScene(this);         //crea la escena
    scene->setSceneRect(120,100,250,120);   //Set de la escena con los parametros (x,y,ancho,alto)
    scene->setBackgroundBrush(QImage("C:../versión 13/juego/audio/c.png"));
    scene->setBackgroundBrush(QImage("C:../versión 13/juego/audio/c.png"));
    ui->graphicsView->setScene(scene);
    this->resize(640, 480);
    setFixedSize(650,450);// ancho y altura del mainwindow mas no de la view
    //qDebug()<<this->size();


    obstaculo1 = new cuadrado;   //Creo objeto cuadrado
    obstaculo1->valores(230,240,20,20);
    scene->addItem(obstaculo1);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

}
