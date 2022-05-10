#include "kaczka.h"
#include <QPen>
#include <QBrush>
#include <QGraphicsSceneMouseEvent>
#include "QRandomGenerator"

kaczka::kaczka()
{

    QPen pen(Qt::green);
    pen.setWidth(2);

    QBrush brush(QPixmap(":/zdiencia/kaczka.jpg"));
    
    setRect(-50, -50, 50, 50);
    setPen(pen);
    setBrush(brush);

}

void kaczka::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton) {
        qDebug() << "klik";
        emit mousePressSignal();
    }
}
