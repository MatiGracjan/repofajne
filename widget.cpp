#include "widget.h"
#include "ui_widget.h"
#include <QPen>
#include <QBrush>
#include <QGraphicsEllipseItem>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsTextItem>
#include <QFont>
#include <QGraphicsPixmapItem>
#include "QDateTime"
#include "QString"
#include <QRandomGenerator>
#include <QRect>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    licznik = 0;
    time = 5;
    timer = new QTimer(this);





    connect(timer, SIGNAL(timeout()), this, SLOT(counterUpdate()));

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);



    QPixmap img = QPixmap(":/zdiencia/kaczka.jpg");
    QGraphicsPixmapItem *pixmap = scene->addPixmap(img);

    pixmap->setScale(0.5);
    pixmap->setPos(-20,20);
    pixmap->setRotation(0);

    Kaczka = new kaczka();
    scene->addItem(Kaczka);

    connect(Kaczka, SIGNAL(mousePressSignal()), this, SLOT(kaczkaSlot()));




  timer->start(1000);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::kaczkaSlot()
{
    qDebug() << "kaczka slot";
    ui->label_2->setText(QString::number(++licznik));
}
void Widget::counterUpdate()
{
    if(time != 0){
        time--;
        QString timeFormat = QDateTime::fromSecsSinceEpoch(time, Qt::OffsetFromUTC).toString("mm:ss");
        ui->label_3->setText(timeFormat);
        if(time%1   == 0){
            x = rand()%450;
            y= rand()%450;
            ui->pushButton->setGeometry(x, y, 75,75 );
        }
    }
    if(time == 0){
        ui->label_4->setText("Game over");
    }
}
void Widget::keyPressEvent(QKeyEvent *event)
{
    if(event ->key() == Qt::Key_Space){
        qDebug() << "Cheater";
            close();
        }
    }

void Widget::on_pushButton_clicked(){
    if(time != 0){
        ++time;
        ui->label_2->setText(QString::number(++licznik));
        x = rand()%450;
        y= rand()%450;
        ui->pushButton->setGeometry(x, y, 75,75 );
    }
}



