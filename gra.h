#ifndef GRA_H
#define GRA_H

#include <QDialog>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QPoint>
#include <QTimer>
#include <QString>
#include <QRandomGenerator>
#include <QList>
#include <QDebug>
#include <QMessageBox>
#include <QDateTime>
#include <QFile>
#include <QByteArray>

#include "apple.h"
#include "head.h"
#include "body.h"

namespace Ui {
class Gra;
}

class Gra : public QDialog
{
    Q_OBJECT

public:
    explicit Gra(QWidget *parent = nullptr);
    ~Gra();

    void keyPressEvent(QKeyEvent *event);

private slots:
    void on_Stop_Start_clicked();
    void moveSnake();
    void moveBody(QPointF prev);
    void addBody();
    void lose();

signals:
    void showMain();

private:
    Ui::Gra *ui;
    QGraphicsScene *scena;
    QGraphicsRectItem *ri;
    apple *Apple;
    Head *head;
    Body *body;
    QPointF current;
    QTimer *timer;


    bool stan = true;
    int direction = 0;
    int punkty = 0;
    int predkosc;
    int mapa;
    int bok;
    int tryb;
    QString godzina;
    QString data;
    QString predkoscS;
    QString mapaS;
    QString trybS;

    QList<Body*> bodies;
};

#endif // GRA_H
