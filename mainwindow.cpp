#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QStandardItemModel"
#include "QStandardItem"
#include "QFile"
#include "QDebug"
#include <QString>
#include "QStandardItemModel"
#include "QStandardItem"
#include <QTableWidget>
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent) :

    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}



MainWindow::~MainWindow()
{
    delete ui;
}
    QString tab;
    int str = 0;
    //QFile file("text.txt");

void MainWindow::on_pushButton_5_clicked()
{
    QFile file("text.txt");
    if(file.open(QIODevice::ReadOnly))
    {
        qDebug() << "File is open";
        qDebug() << file.isOpen();
    }
    int pred=0;
    int slo=0;
    ui->tableWidget->setColumnCount(6);
    while(!file.atEnd())
    {
        tab=file.readLine();
        str++;
        ui->tableWidget->setRowCount(str);
        pred=0;
        slo=0;
        for(int i=0; tab[i]!='\0';i++){
            if (tab[i]=='/'){
                ui->tableWidget->setItem(str-1,slo,new QTableWidgetItem(tab.mid(pred,i-pred)));
                pred=i+1;
                slo++;
            }
        }

     }
    file.close();


    ui->tableWidget->setHorizontalHeaderItem(0,new QTableWidgetItem("Фамилия"));
    ui->tableWidget->setHorizontalHeaderItem(1,new QTableWidgetItem("Имя"));
    ui->tableWidget->setHorizontalHeaderItem(2,new QTableWidgetItem("Отчество"));
    ui->tableWidget->setHorizontalHeaderItem(3,new QTableWidgetItem("Номер телефона"));
    ui->tableWidget->setHorizontalHeaderItem(4,new QTableWidgetItem("Адрес"));
    ui->tableWidget->setHorizontalHeaderItem(5,new QTableWidgetItem("Дата рождения"));
    str=0;
}

void MainWindow::on_pushButton_6_clicked()
{

}

void MainWindow::on_addRow_clicked()
{
    ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);
}

void MainWindow::on_deleteRow_clicked()
{

}

void MainWindow::on_saveTable_clicked()
{
}
