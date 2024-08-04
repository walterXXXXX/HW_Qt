#ifndef GRAPHICWINDOW_H
#define GRAPHICWINDOW_H

#include <QMainWindow>
#include "qcustomplot.h"

namespace Ui {
class GraphicWindow;
}

class GraphicWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GraphicWindow(QWidget *parent = nullptr);
    ~GraphicWindow();

    void addGraphic(QVector<double> x, QVector<double> y);
    void clearGraphic();

private:
    Ui::GraphicWindow *ui;
    QCPGraph *graph;
};

#endif // GRAPHICWINDOW_H
