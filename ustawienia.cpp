#include "ustawienia.h"
#include "ui_ustawienia.h"

Ustawienia::Ustawienia(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ustawienia)
{
    ui->setupUi(this);
}

Ustawienia::~Ustawienia()
{
    delete ui;
}

void Ustawienia::on_Zapisz_clicked()
{
    QSettings settings("ZSI", "snake_project");

    settings.beginGroup("Ustawienia");
    settings.setValue("Mapa", mapa);
    settings.setValue("Predkosc", predkosc);
    settings.setValue("Tryb",tryb);
    settings.endGroup();

    close();
}

void Ustawienia::on_MalaP_clicked()
{
    predkosc = 250;
}

void Ustawienia::on_NormP_clicked()
{
    predkosc = 150;
}

void Ustawienia::on_DuzaP_clicked()
{
    predkosc = 75;
}


void Ustawienia::on_MalaM_clicked()
{
    mapa = 0; //10x8
}

void Ustawienia::on_NormM_clicked()
{
    mapa = 1; //20x16
}

void Ustawienia::on_DuzaM_clicked()
{
    mapa = 2; //40x32
}


void Ustawienia::on_Zen_clicked()
{
    tryb = 0;
}

void Ustawienia::on_Norm_clicked()
{
    tryb = 1;
}

void Ustawienia::on_BezS_clicked()
{
    tryb = 2;
}
