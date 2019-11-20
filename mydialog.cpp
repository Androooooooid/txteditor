#include "mydialog.h"

mydialog::mydialog(QWidget *parent) :
 QDialog(parent)
{
}

void mydialog::on_pushButton_clicked()
{
  //s = ui->lineEdit->text().toInt(); // сохраняем результат
  accept(); // говорим что диалог выполнился успешно (а не закрыт с отменой)
}
