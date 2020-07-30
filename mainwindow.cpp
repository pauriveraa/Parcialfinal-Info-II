#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "bola.h"
#include "cuadrado.h"
#include <QGraphicsItem>
#include <QMessageBox>
#include "objetocuadrado.h"


extern MainWindow *game;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    srand(time(NULL));
    ui->setupUi(this);
    timer=new QTimer(this);                 //crea el timer
    scene=new QGraphicsScene(this);         //crea la scene
    scene->setSceneRect(0,-HEI,LEN,HEI);     //asigna el rectangulo que encierra la scene, determinado por h_limit y v_limit
     scene->addRect(scene->sceneRect());
    ui->graphicsView->setScene(scene);


    obstaculo1 = new cuadrado;   //Creo objeto cuadrado
    obstaculo1->valores(230,-240,20,20);
    scene->addItem(obstaculo1);

    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));

    connect(timer,SIGNAL(timeout()),SLOT(choque()));


    timer1= new QTimer(this);
    minutos=0;
    segundos=0;
    centesimas=0;
    connect(timer1,SIGNAL(timeout()),this,SLOT(mostrar()));
    connect(ui->start, SIGNAL(clicked()),this, SLOT(comenzar()));
 //   connect(ui->stop, SIGNAL(clicked()),this,SLOT(detener()));
   //connect(ui->reset, SIGNAL(clicked()),this,SLOT(reiniciar()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::actualizar()
{

    for(std::list<Bola*>::iterator i=bolas.begin(); i != bolas.end(); ++i){
        (*i)->mover();
        (*i)->choque(0,0,LEN,HEI);
    }
}



void MainWindow::on_pushButton_2_clicked()
{
timer->stop();



}
//void MainWindow::choque1(){
//colision=m.collidingItems().empty();//si esta vacio devuelve un 1, si no esta facio devuelve un cero

//if(colision==false){
//    if((bolas.list) ){
//        msgBox.setText("YOU WIN");
//        msgBox.exec();


//}

//}
//}

void MainWindow::on_pushButton_3_clicked()
{
        bolas.push_back(new Bola(5+rand()%31-1,            //Radio
                                 rand()%501,               //Px
                                 rand()%1001,              //Py
                                 rand()%301,               //Vx
                                 rand()%301,               //Vy
                                 (float(rand()%5)/10)+ 0.5, //Cr
                                 50+rand()%601-1,
                                 (float(rand()%10)/1000)));
        bolas.back()->mover();
        ui->graphicsView->scene()->addItem(bolas.back());


}

void MainWindow::comenzar()
{
    ui->start->setDisabled(1);
 //   ui->stop->setEnabled(1);
  //  ui->reset->setEnabled(1);

    timer1->start(10);//timer se controla en milisegundos

}

void MainWindow::detener()
{
    ui->start->setEnabled(1);
  //  ui->stop->setDisabled(1);
   // ui->reset->setEnabled(1);

    timer1->stop();
}

void MainWindow::reiniciar()
{
    ui->start->setEnabled(1);

    timer1->stop();
    minutos=0;
    segundos=0;
    centesimas=0;
    ui->centesimas->display(0);
    ui->segundos->display(0);
    ui->minutos->display(0);

}

void MainWindow::mostrar()
{

    centesimas=centesimas+1;
    ui->centesimas->display(centesimas);
        if (centesimas==99) {
            centesimas=0;
            segundos=segundos+1;
        }
    ui->segundos->display(segundos);
        if(segundos==59){
            segundos=0;
            minutos=minutos+1;
        }
   ui->minutos->display(minutos);
        if(minutos==59){
            minutos=0;
        }
if ((segundos==5||segundos==10||segundos==15||segundos==20||segundos==25||segundos==30||segundos==35||segundos==40||segundos==45||segundos==50||segundos==55)&&centesimas==0)
{
    on_pushButton_3_clicked();
}

}

void MainWindow::on_start_clicked()
{
    timer->start(10);
}
