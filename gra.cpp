#include "gra.h"
#include "ui_gra.h"
#include "mainwindow.h"



Gra::Gra(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Gra)
{
    ui->setupUi(this);
    scena = new QGraphicsScene(0,0,1000,800);

    QSettings settings("ZSI", "snake_project");
    settings.beginGroup("Ustawienia");
    mapa = settings.value("Mapa", 1).toInt();
    predkosc = settings.value("Predkosc", 150).toInt();
    tryb = settings.value("Tryb",1).toInt();
    settings.endGroup();
    qDebug() << predkosc;


    ui->graphicsView->setScene(scena);

    timer = new QTimer(this);
    timer->setInterval(predkosc);
    connect(timer, SIGNAL(timeout()), this, SLOT(moveSnake()));\




    Apple = new apple();
    scena->addItem(Apple);
    Apple->setPos(700,400);

    head = new Head();
    scena->addItem(head);
    head->setPos(300,400);

    switch (mapa) {
        case 0: bok = ( head->boundingRect().width() )*2; mapaS="Mapa: Mala"; break;
        case 1: bok = head->boundingRect().width(); mapaS="Mapa: Normalna"; break;
        case 2: bok = ( head->boundingRect().width() )/2; mapaS="Mapa: Duza"; break;
    }
    switch (predkosc) {
        case 75: predkoscS = "Predkosc: Duza"; break;
        case 150: predkoscS = "Predkosc: Normalna"; break;
        case 250: predkoscS = "Predkosc: Mala"; break;
    }
    switch (tryb) {
        case 0: trybS = "Tryb: Zen"; break;
        case 1: trybS = "Tryb: Normalny"; break;
        case 2: trybS = "Tryb: Bez Smierci"; break;
    }

    body = new Body();
    bodies.prepend(body);

    scena->addItem(body);
    body->setPos(300-bok,400);


    body = new Body();
    bodies.prepend(body);

    scena->addItem(body);
    body->setPos(300-(bok*2),400);





}

Gra::~Gra()
{
    QSettings settings("ZSI", "snake_project");

    settings.endGroup();
    delete ui;
}

void Gra::on_Stop_Start_clicked()
{

    if(stan){
        timer->start();

        ui->Stop_Start->setText("MENU");
        stan = false;

    }
    else{
        timer->stop();

       // ui->Stop_Start->setText("MENU");
        this->close();
        stan = true;

        emit showMain();
    }

}
void Gra::moveSnake()
{
    current = head->pos();

    if(direction == 0){
        int x = head->x();
        int y = head->y();
        head->setPos(x+bok,y);
        qDebug() << "moveR";
    }
    else if(direction == 1){
        int x = head->x();
        int y = head->y();
        head->setPos(x-bok,y);
        qDebug() << "moveL";
    }
    else if(direction == 2){
        int x = head->x();
        int y = head->y();
        head->setPos(x,y-bok);
        qDebug() << "moveU";
    }
    else if(direction == 3){
        int x = head->x();
        int y = head->y();
        head->setPos(x,y+bok);
        qDebug() << "moveD";
    }

    if(!(scena->collidingItems(Apple).isEmpty()))
    {
        if(Apple->collidesWithItem(body))
        {
            punkty--;
        }
        punkty++;
        ui->punkty->setText("Punkty:"+QString::number(punkty));
        addBody();
        int x;
        int y;
        switch (mapa) {
        case 0:
            x = (QRandomGenerator::global()->bounded(10))*100;
            y = (QRandomGenerator::global()->bounded(8))*100;
            break;
        case 1:
            x = (QRandomGenerator::global()->bounded(20))*50;
            y = (QRandomGenerator::global()->bounded(16))*50;
            break;
        case 2:
            x = (QRandomGenerator::global()->bounded(40))*25;
            y = (QRandomGenerator::global()->bounded(32))*25;
            break;
        }
        Apple->setPos(x,y);
    }
    if(head->x()>=1000 || head->x()<0 || head->y()>=800 || head->y()<0){
        if(tryb == 0 || tryb == 2){
            if(head->x()>=1000){
               head->setPos(0,head->y());
            }
            else if(head->x()<=0){
                head->setPos(1000,head->y());
            }
            else if(head->y()>=800){
                head->setPos(head->x(),0);
            }
            else if(head->y()<0){
                head->setPos(head->x(),800);
            }
        }
        else{
            lose();
        }

    }
    if(tryb != 2){
        for(int i = 0,n = bodies.size()-1; i < n; ++i){
            if(bodies[i]->collidesWithItem(head)){
                lose();
            }
        }
    }
    moveBody(current);
}
void Gra::moveBody(QPointF prev)
{
    for (int i = 0, n = bodies.size()-1; i < n; ++i){
        bodies[i]->setPos(bodies[i+1]->pos());
    }

    bodies.last()->setPos(prev);

}

void Gra::addBody()
{
    Body *body = new Body();
    bodies.prepend(body);

    scena->addItem(body);
}

void Gra::lose()
{
    timer->stop();
    qDebug() << "przegrana";
    QMessageBox::information(this,"Przegrałeś!","Twój wynik to "+QString::number(punkty) + " punktów",QMessageBox::Ok);
    data = QDateTime::currentDateTime().toString("dd.MM.yyyy");
    godzina = QDateTime::currentDateTime().toString("hh:mm:ss");
    //QFile file("D:\\programowanie\\qt\\snake_project\\wyniki.txt");
    QFile file("wyniki.txt");
    if(file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)){
        QTextStream out(&file);
        out << "Punkty: " << punkty << " | " << godzina << " | " << data << " | " << predkoscS << " | " << mapaS << " | " << trybS <<"\n";
    }
    qDebug() << data << godzina;
    on_Stop_Start_clicked();

}
void Gra::keyPressEvent(QKeyEvent *event)
{
    if(stan == true)
    {
        return;
    }
    if (event->key() == Qt::Key_W){

        if(direction == 3 || direction == 2){
            return;
        }
        direction = 2;

        qDebug() << "up";
    }
    else if (event->key() == Qt::Key_S){

        if(direction == 2 || direction == 3){
            return;
        }
        direction = 3;
        qDebug() << "down";
    }
    else if (event->key() == Qt::Key_D){

        if(direction == 1 || direction == 0){
            return;
        }
        direction = 0;
        qDebug() << "right";
    }
    else if (event->key() == Qt::Key_A){

        if(direction == 0 || direction == 1){
            return;
        }
        direction = 1;
        qDebug() << "left";
    }
    moveSnake();
}
