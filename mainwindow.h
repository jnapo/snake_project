#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gra.h"
#include "ustawienia.h"
#include "wyniki.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Wyjscie_clicked();
    void on_NowaGra_clicked();

    void on_Ustawienia_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    Gra *gra;
    Ustawienia *ustawienia = new Ustawienia();
    Wyniki *wyniki;
};
#endif // MAINWINDOW_H
