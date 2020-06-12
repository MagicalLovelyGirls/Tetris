/*#ifndef PANEL_H
#define PANEL_H

#include <QWidget>
#include <QLabel>
#include <QPalette>

class Panel: public QWidget
{
    Q_OBJECT

private:
    int score;
    QLabel *label;
public:
    Panel(QWidget *parent = nullptr);
    void add_score();
    void update_panel();
};

#endif // PANEL_H*/
