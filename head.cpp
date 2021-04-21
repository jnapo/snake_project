#include "head.h"
Head::Head()
{
    setPixmap(QPixmap(":/black.png"));
    QSettings settings("ZSI", "snake_project");
    settings.beginGroup("Ustawienia");
    mapa = settings.value("Mapa", 1).toInt();
    switch (mapa) {
        case 0: setScale(2.0);break;
        case 1: setScale(1.0);break;
        case 2: setScale(0.5);break;
    }
}
