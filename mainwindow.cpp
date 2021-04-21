#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Wyjscie_clicked()
{
    QApplication::quit();
}


void MainWindow::on_NowaGra_clicked()
{

    gra = new Gra();

    gra->show();
    connect(gra, SIGNAL(showMain()), this, SLOT(show()));

    this->hide();
    //this->show();
}

void MainWindow::on_Ustawienia_clicked()
{
    ustawienia->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    wyniki = new Wyniki();
    wyniki->show();
}
