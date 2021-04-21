#ifndef USTAWIENIA_H
#define USTAWIENIA_H

#include <QDialog>
#include <QSettings>

namespace Ui {
class Ustawienia;
}

class Ustawienia : public QDialog
{
    Q_OBJECT

public:
    explicit Ustawienia(QWidget *parent = nullptr);
    ~Ustawienia();

private slots:
    void on_Zapisz_clicked();

    void on_MalaP_clicked();

    void on_NormP_clicked();

    void on_DuzaP_clicked();

    void on_MalaM_clicked();

    void on_NormM_clicked();

    void on_DuzaM_clicked();

    void on_Norm_clicked();

    void on_Zen_clicked();

    void on_BezS_clicked();

private:
    Ui::Ustawienia *ui;
    int mapa = 1;
    int predkosc = 1;
    int tryb = 1;
};

#endif // USTAWIENIA_H
