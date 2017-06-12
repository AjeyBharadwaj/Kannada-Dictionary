#include <QtWidgets>
#include <QFile>
#include <QTextStream>
#include "dictionary.h"

#include <iostream>
#include <String>
using namespace std;

//! [constructor and input fields]
AddressBook::AddressBook(QWidget *parent)
    : QWidget(parent)
{
    QLabel *wordLabel = new QLabel(tr("Word:"));
    wordLine = new QLineEdit;

    QLabel *meaningLabel = new QLabel(tr("Meaning:"));
    meaningText = new QTextEdit;
//! [constructor and input fields]

//! [layout]
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(wordLabel, 0, 0);
    mainLayout->addWidget(wordLine, 0, 1);
    mainLayout->addWidget(meaningLabel, 1, 0, Qt::AlignTop);
    mainLayout->addWidget(meaningText, 1, 1);
//! [layout]

//![setting the layout]
    setLayout(mainLayout);
    setWindowTitle(tr("Simple Kannda Dictionary"));
    
    QFile allWords(":/All.txt");;
    //if (allWords.open(QIODevice::ReadOnly)) {
    if (!allWords.exists()) {
        std::cout << "Error in reading file" << endl;
        setWindowTitle(tr("Error in loading"));
    }
    if (!allWords.open(QIODevice::ReadOnly)) {
        qDebug() << allWords.errorString() ;
    } else {
        QString x = QString::fromUtf8( "\u0C85\u0C82\u0C95" );
        qDebug() << qPrintable(x);
        meaningText->setText(qPrintable(x));
        //meaningText->setText(QString("\u0B86").unicode());
        //meaningText->setText(QString::fromUtf8("\u0C86\u0C82\u0C97\u0CCD\u0CB2\u0CA6\u0CB2\u0CCD\u0CB2\u0CBF : "));
        //meaningText->setPlainText(QTextStream(&allWords).readAll());
    }
    
}
//! [setting the layout]
