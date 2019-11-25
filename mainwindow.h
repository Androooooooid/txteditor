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

    int getX() const;
    void setX(int value);

private slots:
    void on_pushButton_5_clicked();

    void on_addRow_clicked();

    void on_deleteRow_clicked();

    void on_saveTable_clicked();

private:
    Ui::MainWindow *ui;
    int x;

     QString m_line1;
};

#endif // MAINWINDOW_H
