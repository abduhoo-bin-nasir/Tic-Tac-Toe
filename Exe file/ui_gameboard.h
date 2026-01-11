/********************************************************************************
** Form generated from reading UI file 'gameboard.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEBOARD_H
#define UI_GAMEBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameBoard
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *statusLabel;
    QGridLayout *gridLayout;
    QPushButton *btn_2_0;
    QPushButton *btn_1_1;
    QPushButton *btn_2_1;
    QPushButton *btn_1_2;
    QPushButton *btn_0_0;
    QPushButton *btn_2_2;
    QPushButton *btn_1_0;
    QPushButton *btn_0_1;
    QPushButton *btn_0_2;
    QPushButton *btnMainMenu;
    QPushButton *btnReset;

    void setupUi(QWidget *GameBoard)
    {
        if (GameBoard->objectName().isEmpty())
            GameBoard->setObjectName("GameBoard");
        GameBoard->resize(585, 529);
        layoutWidget = new QWidget(GameBoard);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 20, 563, 496));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        statusLabel = new QLabel(layoutWidget);
        statusLabel->setObjectName("statusLabel");
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        statusLabel->setFont(font);
        statusLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(statusLabel);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        btn_2_0 = new QPushButton(layoutWidget);
        btn_2_0->setObjectName("btn_2_0");
        QFont font1;
        font1.setPointSize(36);
        font1.setBold(true);
        btn_2_0->setFont(font1);

        gridLayout->addWidget(btn_2_0, 2, 0, 1, 1);

        btn_1_1 = new QPushButton(layoutWidget);
        btn_1_1->setObjectName("btn_1_1");
        btn_1_1->setFont(font1);

        gridLayout->addWidget(btn_1_1, 1, 1, 1, 1);

        btn_2_1 = new QPushButton(layoutWidget);
        btn_2_1->setObjectName("btn_2_1");
        btn_2_1->setFont(font1);

        gridLayout->addWidget(btn_2_1, 2, 1, 1, 1);

        btn_1_2 = new QPushButton(layoutWidget);
        btn_1_2->setObjectName("btn_1_2");
        btn_1_2->setFont(font1);

        gridLayout->addWidget(btn_1_2, 1, 2, 1, 1);

        btn_0_0 = new QPushButton(layoutWidget);
        btn_0_0->setObjectName("btn_0_0");
        btn_0_0->setFont(font1);

        gridLayout->addWidget(btn_0_0, 0, 0, 1, 1);

        btn_2_2 = new QPushButton(layoutWidget);
        btn_2_2->setObjectName("btn_2_2");
        btn_2_2->setFont(font1);

        gridLayout->addWidget(btn_2_2, 2, 2, 1, 1);

        btn_1_0 = new QPushButton(layoutWidget);
        btn_1_0->setObjectName("btn_1_0");
        btn_1_0->setFont(font1);

        gridLayout->addWidget(btn_1_0, 1, 0, 1, 1);

        btn_0_1 = new QPushButton(layoutWidget);
        btn_0_1->setObjectName("btn_0_1");
        btn_0_1->setFont(font1);

        gridLayout->addWidget(btn_0_1, 0, 1, 1, 1);

        btn_0_2 = new QPushButton(layoutWidget);
        btn_0_2->setObjectName("btn_0_2");
        btn_0_2->setFont(font1);

        gridLayout->addWidget(btn_0_2, 0, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        btnMainMenu = new QPushButton(layoutWidget);
        btnMainMenu->setObjectName("btnMainMenu");

        verticalLayout->addWidget(btnMainMenu);

        btnReset = new QPushButton(layoutWidget);
        btnReset->setObjectName("btnReset");

        verticalLayout->addWidget(btnReset);


        retranslateUi(GameBoard);

        QMetaObject::connectSlotsByName(GameBoard);
    } // setupUi

    void retranslateUi(QWidget *GameBoard)
    {
        GameBoard->setWindowTitle(QCoreApplication::translate("GameBoard", "Tic-Tac-Toe Game", nullptr));
        statusLabel->setText(QCoreApplication::translate("GameBoard", "Player X's Turn", nullptr));
        btn_2_0->setText(QString());
        btn_1_1->setText(QString());
        btn_2_1->setText(QString());
        btn_1_2->setText(QString());
        btn_0_0->setText(QString());
        btn_2_2->setText(QString());
        btn_1_0->setText(QString());
        btn_0_1->setText(QString());
        btn_0_2->setText(QString());
        btnMainMenu->setText(QCoreApplication::translate("GameBoard", "Main Menu", nullptr));
        btnReset->setText(QCoreApplication::translate("GameBoard", "Reset Game", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameBoard: public Ui_GameBoard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEBOARD_H
