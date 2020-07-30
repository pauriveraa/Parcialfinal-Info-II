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


    ui->pushButton_3->hide();

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

        if((*i)->bandera==1)
        {
            qDebug()<<(*i)->bandera;
         (*i)->hide();
            (*i)->bandera=0;
             qDebug()<<(*i)->bandera;
        }

    }
}



void MainWindow::on_pushButton_2_clicked()
{
    timer->start(10);
     bolas.push_back(new Bola(5+rand()%31-1,            //Radio
                              rand()%500,               //Px
                              rand()%1001,              //Py
                              0,               //Vx
                              rand()%60,               //Vy
                              0, //Cr
                              30,
                              (30)));
     bolas.back()->mover();
     ui->graphicsView->scene()->addItem(bolas.back());



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
                                 rand()%100,               //Px
                                 rand()%1001,              //Py
                                 rand()%101,               //Vx
                                 rand()%101,               //Vy
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
    if(segundos==5){

        obstaculo1 = new cuadrado;   //Creo objeto cuadrado
        obstaculo1->valores(230,-240,20,20);
        scene->addItem(obstaculo1);

    }
    if(segundos==10){

        obstaculo3 = new cuadrado;   //Creo objeto cuadrado
        obstaculo3->valores(30,-240,20,20);
        scene->addItem(obstaculo3);


    }
    if(segundos==15){

        obstaculo4 = new cuadrado;   //Creo objeto cuadrado
        obstaculo4->valores(280,-210,20,20);
        scene->addItem(obstaculo4);
        delete obstaculo3;

    }
    if(segundos==20){

        obstaculo5 = new cuadrado;   //Creo objeto cuadrado
        obstaculo5->valores(250,-140,20,20);
        scene->addItem(obstaculo5);
        delete  obstaculo1;

    }
    if(segundos==25){
        obstaculo6 = new cuadrado;   //Creo objeto cuadrado
        obstaculo6->valores(230,-220,20,20);
        scene->addItem(obstaculo6);


    }
    if(segundos==30){

        obstaculo7 = new cuadrado;   //Creo objeto cuadrado
        obstaculo7->valores(250,-20,20,20);
        scene->addItem(obstaculo7);
        delete  obstaculo5;

    }
    if(segundos==35){

        obstaculo8 = new cuadrado;   //Creo objeto cuadrado
        obstaculo8->valores(130,-280,20,20);
        scene->addItem(obstaculo8);

    }
    if(segundos==40){

        obstaculo9 = new cuadrado;   //Creo objeto cuadrado
        obstaculo9->valores(170,-182,20,20);
        scene->addItem(obstaculo9);
        delete  obstaculo7;
        delete  obstaculo8;

    }

}

}

void MainWindow::on_start_clicked()
{
    timer->start(10);
}
