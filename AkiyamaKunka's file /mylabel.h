#ifndef MYLABEL_H
#define MYLABEL_H

#include <QWidget>
#include <QLabel>
#include <QMouseEvent>

class myLabel : public QLabel
{
    Q_OBJECT
public:
    explicit myLabel(QWidget *parent = nullptr);

    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);

    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);

signals:

};

#endif // MYLABEL_H
