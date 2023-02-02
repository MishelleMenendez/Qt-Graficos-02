#include "principal.h"

#include <QApplication>
#include <QTranslator>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator traduccion;
    QStringList idiomas;
    idiomas << "Ruso" << "Japonés" << "Español";
    QString idioma_s = QInputDialog::getItem(NULL,
                                             "Idioma",
                                             "Seleccione un idioma: ",
                                             idiomas);
    if (idioma_s == "Ruso")
    {
        traduccion.load(":/graficos_ru.qm");
    }else if (idioma_s == "Japonés")
    {
        traduccion.load(":/graficos_jp.qm");
    }
    if (idioma_s != "Español"){
        a.installTranslator(&traduccion);
    }
    Principal w;
    w.show();
    return a.exec();
}
