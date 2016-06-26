/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *SearchSpace;
    QPushButton *Searchbtn;
    QTableWidget *Result;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(600, 500);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        SearchSpace = new QLineEdit(centralWidget);
        SearchSpace->setObjectName(QStringLiteral("SearchSpace"));
        SearchSpace->setClearButtonEnabled(true);

        horizontalLayout->addWidget(SearchSpace);

        Searchbtn = new QPushButton(centralWidget);
        Searchbtn->setObjectName(QStringLiteral("Searchbtn"));
        Searchbtn->setEnabled(false);
        Searchbtn->setAutoDefault(false);
        Searchbtn->setFlat(false);

        horizontalLayout->addWidget(Searchbtn);


        verticalLayout->addLayout(horizontalLayout);

        Result = new QTableWidget(centralWidget);
        Result->setObjectName(QStringLiteral("Result"));
        Result->setSelectionMode(QAbstractItemView::SingleSelection);
        Result->setSelectionBehavior(QAbstractItemView::SelectRows);
        Result->setRowCount(0);
        Result->setColumnCount(0);

        verticalLayout->addWidget(Result);


        verticalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        Searchbtn->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        SearchSpace->setPlaceholderText(QApplication::translate("MainWindow", "Search word...", 0));
        Searchbtn->setText(QApplication::translate("MainWindow", "Search", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
