#include "graphicwindow.h"
#include "ui_graphicwindow.h"

GraphicWindow::GraphicWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GraphicWindow)
{
    ui->setupUi(this);

    graph = new QCPGraph(ui->customPlot->xAxis, ui->customPlot->yAxis);
    ui->customPlot->addGraph();
    ui->customPlot->setInteraction(QCP::iRangeZoom, true);
    ui->customPlot->setInteraction(QCP::iRangeDrag, true);

}

GraphicWindow::~GraphicWindow()
{
    delete ui;
}

void GraphicWindow::addGraphic(QVector<double> x, QVector<double> y)
{
    graph->addData(x, y);
    ui->customPlot->rescaleAxes();
    ui->customPlot->replot();
}

void GraphicWindow::clearGraphic()
{
    graph->data()->clear();
    ui->customPlot->graph(0)->data()->clear();
    ui->customPlot->replot();
}
