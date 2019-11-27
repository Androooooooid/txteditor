
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
    QFile file("C:\\Users\\Alfa7\\Downloads\\txteditor-master\\text.txt");
    file.open(QIODevice::ReadOnly);
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


    ui->tableWidget->setHorizontalHeaderItem(0,new QTableWidgetItem("Дата зачисления"));
    ui->tableWidget->setHorizontalHeaderItem(1,new QTableWidgetItem("ФИО"));
    ui->tableWidget->setHorizontalHeaderItem(2,new QTableWidgetItem("Специальность"));
    ui->tableWidget->setHorizontalHeaderItem(3,new QTableWidgetItem("Факультет"));
    ui->tableWidget->setHorizontalHeaderItem(4,new QTableWidgetItem("Курс"));
    ui->tableWidget->setHorizontalHeaderItem(5,new QTableWidgetItem("Средний балл"));
    str=0;
}

void MainWindow::on_addRow_clicked()
{
    ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);
}

void MainWindow::on_deleteRow_clicked()
{
    QModelIndexList selectedRows = ui->tableWidget->selectionModel()->selectedRows();
    while (!selectedRows.empty()) {

        ui->tableWidget->removeRow(selectedRows[0].row());
        selectedRows = ui->tableWidget->selectionModel()->selectedRows();
    }
}

void MainWindow::on_saveTable_clicked()
{
    QFile file("C:\\Users\\Alfa7\\Downloads\\txteditor-master\\text.txt");
    if (file.open(QIODevice::WriteOnly));
    {
        qDebug() <<"good";
        qint32 row(ui->tableWidget->rowCount()), column(ui->tableWidget->columnCount());
        QString str;
        qDebug() << row << column;
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < column; j++) //цикл при j = 0, пока j < row, j увеличивается на единицу
            {
                QTableWidgetItem *itab = ui->tableWidget->item(i,j);
                if (itab)
                    str+=ui->tableWidget->item(i,j)->text();
                str+="/";
            }
            str+="\n";
        }
        file.write(str.toUtf8());
        file.close();
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    int avg=0;
    qint32 row(ui->tableWidget->rowCount());
    for (int i = 0; i < row; ++i)
    {
        avg+=ui->tableWidget->item(i,5)->text().toInt();
    }
    avg=avg / row;
    ui->label_2->setNum(avg);
}
