#include "class.h"
#include <QObject>

#include <QByteArray>
using namespace std;
fenetre::fenetre():QWidget(){
    layout=new QGridLayout();
    box=new QGroupBox("Sélctionner un fichier à executer");
    layout_principal=new QGridLayout();
    system("./exe /home/brahim/C++|cut -d / -f 2->fichiers");
            fichier=new QFile("fichiers");
    if (fichier->open(QIODevice::ReadOnly)){
        int i(0);
     inp=new QTextStream(fichier);

    }
    int i(0);
    while(!inp->atEnd()){
        QString s=inp->readLine();
    if(!s.isEmpty()){
    tab.push_back(new QRadioButton());
    tab[i]->setText(s);
    layout->addWidget(tab[i],i/2,i%2);

    i++;

    }}

box->setLayout(layout);
execution=new QPushButton("executer le code séléctionné");
layout_principal->addWidget(box,0,0);
layout_principal->addWidget(execution,1,0);
setLayout(layout_principal);
QObject::connect(execution,SIGNAL(clicked()),this,SLOT(executer()));
}

void fenetre::executer(){
    int i(0);

    while(i<tab.size()){
        if(tab[i]->isChecked())
            break;
        else
            i++;
    }
    if(i<tab.size()){
        QString s="./executer ./"+tab[i]->text();
     QByteArray byte=s.toLocal8Bit();
     const char* ch=byte.data();
     system(ch);



    }
    else{
        QMessageBox::critical(this,"Erreur","Veuillez sélectionner un fichier ");
    }



}
