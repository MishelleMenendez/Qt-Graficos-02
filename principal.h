#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>
#include <QPaintEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();

private slots:
    void on_actionGuardar_triggered();

    void on_pushButton_clicked(bool checked);

    void on_calNota1_valueChanged(int arg1);

    void on_calNota2_valueChanged(int arg1);

    void on_calNota3_valueChanged(int arg1);

    void on_actionNuevo_triggered();


private:
    Ui::Principal *ui;
    QPixmap lienzo;

    void limpiar();
    void dibujar();
    int getAlto(int valor);
    int aum(int alto);
    int promedio(int nt1,int nt2,int nt3);
};
#endif // PRINCIPAL_H
