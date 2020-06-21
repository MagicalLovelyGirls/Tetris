#include "mylabel.h"
#include <QDebug>

myLabel::myLabel(QWidget *parent) : QLabel(parent)
{

}
void myLabel::enterEvent(QEvent *event){
    qDebug() << "Mouse enter";

}
void myLabel::leaveEvent(QEvent *event){
    qDebug() << " Mouse leave";
}

void myLabel::mousePressEvent(QMouseEvent *ev){
    if(ev->button() == Qt::LeftButton) {
    QString str = QString("Mouse pressed at x %1 = y = %2 global x = %3, global y = %4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
    qDebug() << str;
}

}
void myLabel::mouseReleaseEvent(QMouseEvent *ev){
    qDebug() << " Mouse released";
}
void myLabel::mouseMoveEvent(QMouseEvent *ev){

    //qDebug() << " Mouse mouved";

    //QString str = QString("Mouse pressed at x %1 = y = %2 global x = %3, global y = %4").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
    //qDebug() << str;
}
