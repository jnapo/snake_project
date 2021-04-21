#ifndef WYNIKI_H
#define WYNIKI_H

#include <QDialog>

namespace Ui {
class Wyniki;
}

class Wyniki : public QDialog
{
    Q_OBJECT

public:
    explicit Wyniki(QWidget *parent = nullptr);
    ~Wyniki();

private:
    Ui::Wyniki *ui;
    QString current;
};

#endif // WYNIKI_H
