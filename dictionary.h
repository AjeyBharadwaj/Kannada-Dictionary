#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QLabel;
class QLineEdit;
class QTextEdit;
QT_END_NAMESPACE

//! [class definition]
class AddressBook : public QWidget
{
    Q_OBJECT

public:
    AddressBook(QWidget *parent = 0);

private:
    QLineEdit *wordLine;
    QTextEdit *meaningText;
};
//! [class definition]

#endif
