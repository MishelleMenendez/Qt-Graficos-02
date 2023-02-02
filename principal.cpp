#include "principal.h"
#include "ui_principal.h"

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    lienzo = QPixmap(500,500);
    this->dibujar();

    ui->outCuadro->setPixmap(lienzo);

}

Principal::~Principal()
{
    delete ui;
}

void Principal::dibujar()
{
    lienzo.fill(Qt::white);

    QPainter painter(&lienzo);

    int x =20;
    int y =0;

    // Crear un pincel para los bordes
    QPen pincel;
    pincel.setWidth(5);
    pincel.setColor(Qt::blue);
    pincel.setJoinStyle(Qt::MiterJoin);

    // Colores de la primera
    QColor colorRelleno1(0,70,211);
    QColor colorBorde1(0,47,141);

    pincel.setColor(colorBorde1);
    painter.setPen(pincel);
    painter.setBrush(colorRelleno1);

    //Datos primera barra
    int nota1=ui->calNota1->value();
    int altoN1=this->getAlto(nota1);
    int aumN1=this->aum(altoN1);

    // Dibujar primera barra
    painter.drawRect(x+50, y+50+aumN1,100,altoN1);

    // Colores de la segunda barra
    QColor colorRelleno2(79,48,255);
    QColor colorBorde2(34,21,111);

    pincel.setColor(colorBorde2);
    painter.setPen(pincel);
    painter.setBrush(colorRelleno2);

    //Datos segunda barra
    int nota2=ui->calNota2->value();
    int altoN2=this->getAlto(nota2);
    int aumN2=this->aum(altoN2);

    // Dibujar segunda barra
    painter.drawRect(x+170, y+50+aumN2,100,altoN2);

    // Colores de la tercera barra
    QColor cRellenoBarra3(147,0,110);
    QColor cBordeBarra3(109,0,82);

    pincel.setColor(cBordeBarra3);
    painter.setPen(pincel);
    painter.setBrush(cRellenoBarra3);

    //Datos tercera barra
    int nota3=ui->calNota3->value();
    int altoN3=this->getAlto(nota3);
    int aumN3=this->aum(altoN3);

    // Dibujar tercera barra
    painter.drawRect(x+290, y+50+aumN3,100,altoN3);

    //Creando los colores del plano
    QColor cProm(0, 0, 0);

    pincel.setColor(cProm);
    painter.setPen(pincel);

    float prom1=promedio(nota1,nota2,nota3);
    ui->promedio->setText(QString::number(prom1));
    int altoN4=this->getAlto(prom1);
    int aumN4=this->aum(altoN4);
    painter.drawLine(x+25,aumN4+50,450,aumN4+50);

    // Creando los colores del plano cartesiano
    QColor cPlano(0, 0, 0);

    // Estableciendo colores al pincel
    pincel.setColor(cPlano);
    painter.setPen(pincel);

    // Plano Cartesiano
    painter.drawLine(x+25,y+450,450,450);
    painter.drawLine(x+20,y+20,x+20,450);

    // Intervalos

    for(int i=0;i<=10;i++){
        QString intervalo;
        int a=this->getAlto(i);
        int b=this->aum(a);
        intervalo=QString::number(i);
        painter.drawText(x-10,b+50,intervalo);
    }

}

int Principal::getAlto(int valor)
{
    return 40*valor;
}

int Principal::aum(int alto)
{
    return 400-alto;
}

int Principal::promedio(int n1, int n2, int n3)
{
    return (n1+n2+n3)/3;
}


void Principal::on_actionGuardar_triggered()
{
    QString nombreArchivo = QFileDialog::getSaveFileName(
                this,"Guardar imagen",QString(),"Imagenes (*.png)");
    if (!nombreArchivo.isEmpty()){
        if (lienzo.save(nombreArchivo))
            QMessageBox::information(this,"Guardar imagen","Archivo guarado en: " + nombreArchivo);
        else
            QMessageBox::warning(this,"Guardar imagen","No se pudo guardar el archivo");
    }
}

void Principal::on_pushButton_clicked(bool checked)
{
    dibujar();
    ui->outCuadro->setPixmap(lienzo);
}

void Principal::on_calNota1_valueChanged(int arg1)
{
    dibujar();
    ui->outCuadro->setPixmap(lienzo);
}

void Principal::on_calNota2_valueChanged(int arg1)
{
    dibujar();
    ui->outCuadro->setPixmap(lienzo);
}

void Principal::on_calNota3_valueChanged(int arg1)
{
    dibujar();
    ui->outCuadro->setPixmap(lienzo);
}

void Principal::on_actionNuevo_triggered()
{
    // Limpiar widgets
    limpiar();
}

void Principal::limpiar()
{
    // Limpiar widgets
    ui->calNota1->setValue(0);
    ui->calNota2->setValue(0);
    ui->calNota3->setValue(0);

}



