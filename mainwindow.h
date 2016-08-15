#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_sldProfundidade_valueChanged(int value);

    void on_sldComprimento_valueChanged(int value);

    void on_sldAngulo_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    int _nProfundidade;
    int _nComprimento;
    int _nAngulo;
    int _nHead = 0;
    QPointF _pos = QPointF(0,0);

private:
    void Refresh(void);
    void Go(double nComprimento, int nProfundidade);
};

#endif // MAINWINDOW_H
