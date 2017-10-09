#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <cmath>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
        connect(ui->metodo,SIGNAL(clicked()),this,SLOT(metodo()));//connections slots-buttons
        connect(ui->borrar,SIGNAL(clicked()),this,SLOT(limpiar()));
        connect(ui->salir,SIGNAL(clicked()),this,SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::metodo ()
{
    QString temp1, temp2, temp3, temp4;
    double x1=ui->x1->value();//Save the value of the spinboxes in the variables
    double x2=ui->x2->value();
    double x3=ui->x3->value();
    double x4=ui->x4->value();
    double y1=ui->y1->value();
    double y2=ui->y2->value();
    double y3=ui->y3->value();
    double y4=ui->y4->value();
    double x=ui->x->value();
    double polinomio[4];//array
    double f, m;
    int i=0, j=0, n;
    a[0]=x1;a[1]=x2;a[2]=x3;a[3]=x4;
    b[0]=y1;b[1]=y2;b[2]=y3;b[3]=y4;
    for(n=1;n<4;n++)
    {
        m=0;
        for(i=0;i<=n;i++)
        {
            f=1.00;
            for(j=0;j<=n;j++)
            {
                if(i!=j)
                {
                  f=f*((x-a[j])/(a[i]-a[j]));
                }
            }
            f=f*b[i];
             m=m+f;
        }
        polinomio[n]=m;//result
    }
   temp1.append("Función 1=").append(temp2.setNum(polinomio[1])).append("\nFuncion 2=").append(temp3.setNum(polinomio[2])).append("\nFunción 3=").append(temp4.setNum(polinomio[3]));
    ui->textBrowser->setText(temp1);//shows the results
}
    void MainWindow::limpiar ()//clear all the spinboxes
    {
        ui->x1->setValue(0.0);
        ui->x2->setValue(0.0);
        ui->x3->setValue(0.0);
        ui->x4->setValue(0.0);
        ui->y1->setValue(0.0);
        ui->y2->setValue(0.0);
        ui->y3->setValue(0.0);
        ui->y4->setValue(0.0);
        ui->x->setValue(0.0);
        ui->textBrowser->clear();
    }
