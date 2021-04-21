#include "wyniki.h"
#include "ui_wyniki.h"

#include <QFile>
#include <QIODevice>
#include <QTextStream>

Wyniki::Wyniki(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Wyniki)
{
    ui->setupUi(this);
    //QFile file("D:\\programowanie\\qt\\snake_project\\wyniki.txt");
    QFile file("wyniki.txt");
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&file);
        int i = 1;
        while(!in.atEnd()){
            current = ui->wyniki->toPlainText();
            ui->wyniki->setText(current+ QString::number(i) + "." + in.readLine()+"\n");
            i++;
        }
        file.close();
    }
}

Wyniki::~Wyniki()
{
    delete ui;
}
