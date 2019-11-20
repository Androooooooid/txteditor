#include <QDialog>

class mydialog : public QDialog
{
    Q_OBJECT
public:
    explicit mydialog(QWidget *parent = 0);
    int s;
    void on_deleteRow_clicked();

signals:

public slots:

};
