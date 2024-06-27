#include "piano.h"
#include <QApplication>
#include <QPushButton>
#include <QSound>
#include <QSoundEffect>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QMessageBox>
int high=0;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Piano w;
    w.show();

    return a.exec();
}
