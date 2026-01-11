#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include "scoremanager.h"

#include <QWidget>
#include <QPushButton>
#include "gamelogic.h"

namespace Ui {
class GameBoard;
}

class GameBoard : public QWidget
{
    Q_OBJECT

public:
    explicit GameBoard(QWidget *parent = nullptr);
    ~GameBoard();

    // Set game mode before showing the board
    void setGameMode(bool isPlayerVsComputer);

private slots:
    // Called when any cell button is clicked
    void onCellClicked();

    // Called when control buttons are clicked
    void onResetClicked();
    void onMainMenuClicked();

private:
    Ui::GameBoard *ui;
    GameLogic gameLogic;           // Our game logic object
    QPushButton* buttons[3][3];    // Array to store button pointers
    bool isVsComputer;             // true if playing against AI
    ScoreManager* scoreManager;

    // Helper functions
    void setupButtons();           // Store button pointers in array
    void updateBoard();            // Refresh all button labels
    void updateStatus();           // Update status message
    void handleGameOver();         // Check and handle end game
    void disableAllButtons();      // Disable all cells
    void enableAllButtons();       // Enable empty cells

signals:
    void backToMainMenu();};

#endif // GAMEBOARD_H
