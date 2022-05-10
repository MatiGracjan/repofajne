#ifndef KACZKA_H
#define KACZKA_H

#include <QGraphicsRectItem>
#include <QObject>

class kaczka : public QObject, public QGraphicsRectItem
{
    Q_OBJECT

public:
    kaczka();

    void mousePressEvent(QGraphicsSceneMouseEvent *event);

signals:
    void mousePressSignal();


};

#endif // KACZKA_H

