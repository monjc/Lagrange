#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    double a[4];
    double b[4];
    double y[4];

private:
    Ui::MainWindow *ui;
public slots:
    void metodo(); //Run the processes
    void limpiar(); //Clear all the variables
};

#endif // MAINWINDOW_H
