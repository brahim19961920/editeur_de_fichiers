#ifndef CLASS_H
#define CLASS_H
#include <QtWidgets>
#include <vector>
#include <QFile>
#include <QTextStream>
class fenetre:public QWidget{
Q_OBJECT
public:
fenetre();

public slots:
void executer();

private:
std::vector<QRadioButton*> tab;
QGridLayout* layout_principal;
QGroupBox* box;
QGridLayout* layout;
QPushButton* execution;
     QFile *fichier;
     QTextStream *inp;
QTextEdit *console;
QFile *fichier1;
QTextStream *inp1;


};

#endif // CLASS_H
