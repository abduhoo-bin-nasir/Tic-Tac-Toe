#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "gameboard.h"
#include <QMainWindow>
#include "scoremanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // These functions are called when buttons are clicked
    void onPlayerVsPlayerClicked();
    void onPlayerVsComputerClicked();
    void onExitClicked();
    void onViewScoreboardClicked();  // <-- FIXED: Added semicolon here

private:
    Ui::MainWindow *ui;
    GameBoard *gameBoard;
    ScoreManager* scoreManager;
};

#endif // MAINWINDOW_H
