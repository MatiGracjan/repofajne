#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include "kaczka.h"
#include <QTimer>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void kaczkaSlot();
     void counterUpdate();



     void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    QGraphicsScene *scene;
    kaczka *Kaczka;
    int licznik;
     QTimer *timer;
     int time, a, x, y;
     bool clicked = false;
     void keyPressEvent(QKeyEvent * event);
};
#endif // WIDGET_H
