/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QPushButton *btnPlayerVsPlayer;
    QPushButton *btnPlayerVsComputer;
    QPushButton *btnViewScoreboard;
    QPushButton *btnExit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(400, 300);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName("titleLabel");
        QFont font;
        font.setPointSize(24);
        font.setBold(true);
        titleLabel->setFont(font);
        titleLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(titleLabel);

        btnPlayerVsPlayer = new QPushButton(centralwidget);
        btnPlayerVsPlayer->setObjectName("btnPlayerVsPlayer");

        verticalLayout->addWidget(btnPlayerVsPlayer);

        btnPlayerVsComputer = new QPushButton(centralwidget);
        btnPlayerVsComputer->setObjectName("btnPlayerVsComputer");

        verticalLayout->addWidget(btnPlayerVsComputer);

        btnViewScoreboard = new QPushButton(centralwidget);
        btnViewScoreboard->setObjectName("btnViewScoreboard");

        verticalLayout->addWidget(btnViewScoreboard);

        btnExit = new QPushButton(centralwidget);
        btnExit->setObjectName("btnExit");

        verticalLayout->addWidget(btnExit);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Tic Tac Toe", nullptr));
        titleLabel->setText(QCoreApplication::translate("MainWindow", "Tic-Tac-Toe", nullptr));
        btnPlayerVsPlayer->setText(QCoreApplication::translate("MainWindow", "Player vs Player", nullptr));
        btnPlayerVsComputer->setText(QCoreApplication::translate("MainWindow", "Player vs Computer", nullptr));
        btnViewScoreboard->setText(QCoreApplication::translate("MainWindow", "View Scoreboard", nullptr));
        btnExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
