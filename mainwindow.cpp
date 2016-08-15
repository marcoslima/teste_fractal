#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    ui->gv->setScene(scene);
    Refresh();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_sldProfundidade_valueChanged(int value)
{
    (void)value;
    Refresh();
}

void MainWindow::on_sldComprimento_valueChanged(int value)
{
    (void)value;
    Refresh();
}

void MainWindow::on_sldAngulo_valueChanged(int value)
{
    (void)value;
    Refresh();
}

void MainWindow::Refresh()
{
    scene->clear();
    _pos = QPoint(0,0);

    _nProfundidade = ui->sldProfundidade->value();
    _nAngulo = ui->sldAngulo->value();
    _nComprimento = ui->sldComprimento->value();

    Go(_nComprimento, _nProfundidade);
}

void MainWindow::Go(double nComprimento, int nProfundidade)
{
    nProfundidade--;
    if(nProfundidade < 0 || nComprimento < 1)
    {
        QPointF ptTo(_pos.x() + nComprimento * cos(_nHead * M_PI / 180.0),
                     _pos.y() + nComprimento * sin(_nHead * M_PI / 180.0));

        QPen blackPen(Qt::black);
        scene->addLine(_pos.x(), _pos.y(), ptTo.x(), ptTo.y(), blackPen);
        _pos = ptTo;
        return;
    }

    nComprimento /= 3.0;
    Go(nComprimento, nProfundidade);
    _nHead -= _nAngulo;
    Go(nComprimento, nProfundidade);
    _nHead += 2*_nAngulo;
    Go(nComprimento, nProfundidade);
    _nHead -= _nAngulo;
    Go(nComprimento, nProfundidade);

    return;
}
