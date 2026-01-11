#include "gameboard.h"
#include "ui_gameboard.h"
#include <QMessageBox>
#include <QInputDialog>

GameBoard::GameBoard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameBoard),
    isVsComputer(false)
{
    ui->setupUi(this);
    this->setStyleSheet(
        "QWidget {"
        "   background-color: #1e1e1e;"
        "}"
        );

    scoreManager = new ScoreManager();

    // Status label styling
    ui->statusLabel->setStyleSheet(
        "QLabel {"
        "   background-color: #2d2d2d;"
        "   color: #00d4ff;"
        "   font-size: 20px;"
        "   font-weight: bold;"
        "   padding: 15px;"
        "   border-radius: 10px;"
        "   border: 2px solid #00d4ff;"
        "   margin: 10px;"
        "}"
        );

    // Control buttons styling
    QString controlButtonStyle =
        "QPushButton {"
        "   background-color: #2d2d2d;"
        "   color: white;"
        "   border: 2px solid #00d4ff;"
        "   border-radius: 8px;"
        "   padding: 12px;"
        "   font-size: 16px;"
        "   font-weight: bold;"
        "   margin: 5px;"
        "}"
        "QPushButton:hover {"
        "   background-color: #3d3d3d;"
        "   border: 2px solid #00ffff;"
        "}"
        "QPushButton:pressed {"
        "   background-color: #1d1d1d;"
        "}";

    ui->btnReset->setStyleSheet(controlButtonStyle);
    ui->btnMainMenu->setStyleSheet(controlButtonStyle);


    setupButtons();

    // Connect all cell buttons
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            connect(buttons[i][j], &QPushButton::clicked,
                    this, &GameBoard::onCellClicked);
        }
    }

    // Connect control buttons
    connect(ui->btnReset, &QPushButton::clicked,
            this, &GameBoard::onResetClicked);
    connect(ui->btnMainMenu, &QPushButton::clicked,
            this, &GameBoard::onMainMenuClicked);

    updateStatus();
}

GameBoard::~GameBoard()
{
    delete scoreManager;
    delete ui;
}

void GameBoard::setGameMode(bool isPlayerVsComputer)
{
    isVsComputer = isPlayerVsComputer;
    gameLogic.initializeBoard();
    updateBoard();
    updateStatus();
}

void GameBoard::setupButtons()
{
    // Store pointers
    buttons[0][0] = ui->btn_0_0;
    buttons[0][1] = ui->btn_0_1;
    buttons[0][2] = ui->btn_0_2;
    buttons[1][0] = ui->btn_1_0;
    buttons[1][1] = ui->btn_1_1;
    buttons[1][2] = ui->btn_1_2;
    buttons[2][0] = ui->btn_2_0;
    buttons[2][1] = ui->btn_2_1;
    buttons[2][2] = ui->btn_2_2;

    // ===== DARK THEME CELL STYLING =====

    QString cellStyle =
        "QPushButton {"
        "   background-color: #2d2d2d;"
        "   border: 3px solid #444444;"
        "   border-radius: 15px;"
        "   font-size: 48px;"
        "   font-weight: bold;"
        "   color: white;"
        "}"
        "QPushButton:hover {"
        "   background-color: #3d3d3d;"
        "   border: 3px solid #00d4ff;"
        "}"
        "QPushButton:disabled {"
        "   background-color: #252525;"
        "}";

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            buttons[i][j]->setStyleSheet(cellStyle);
        }
    }
}

void GameBoard::onCellClicked()
{
    // Find which button was clicked
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender());

    // Find its position in our array
    int row = -1, col = -1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (buttons[i][j] == clickedButton) {
                row = i;
                col = j;
                break;
            }
        }
        if (row != -1) break;
    }

    // Try to make the move
    char currentPlayer = gameLogic.getCurrentPlayer();
    if (gameLogic.makeMove(row, col, currentPlayer)) {
        // Move was successful
        updateBoard();

        // Check if game is over
        char winner = gameLogic.checkWinner();
        if (winner != 'N') {
            handleGameOver();
            return;
        }

        // Switch player
        gameLogic.switchPlayer();
        updateStatus();

        // If vs computer and now it's O's turn, make computer move
        if (isVsComputer && gameLogic.getCurrentPlayer() == 'O') {
            gameLogic.makeComputerMove();
            updateBoard();

            // Check if computer won
            winner = gameLogic.checkWinner();
            if (winner != 'N') {
                handleGameOver();
                return;
            }

            // Switch back to player
            gameLogic.switchPlayer();
            updateStatus();
        }
    }
}

void GameBoard::updateBoard()
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            char value = gameLogic.getCellValue(i, j);
            if (value == ' ') {
                buttons[i][j]->setText("");
                buttons[i][j]->setEnabled(true);

                // Empty cell style
                buttons[i][j]->setStyleSheet(
                    "QPushButton {"
                    "   background-color: #2d2d2d;"
                    "   border: 3px solid #444444;"
                    "   border-radius: 15px;"
                    "   font-size: 48px;"
                    "   font-weight: bold;"
                    "}"
                    "QPushButton:hover {"
                    "   background-color: #3d3d3d;"
                    "   border: 3px solid #00d4ff;"
                    "}"
                    );
            } else {
                buttons[i][j]->setText(QString(value));
                buttons[i][j]->setEnabled(false);

                // X = Cyan
                if (value == 'X') {
                    buttons[i][j]->setStyleSheet(
                        "QPushButton {"
                        "   background-color: #2d2d2d;"
                        "   border: 3px solid #00d4ff;"
                        "   border-radius: 15px;"
                        "   font-size: 48px;"
                        "   font-weight: bold;"
                        "   color: #00d4ff;"
                        "}"
                        );
                }
                // O = Red/Orange
                else {
                    buttons[i][j]->setStyleSheet(
                        "QPushButton {"
                        "   background-color: #2d2d2d;"
                        "   border: 3px solid #ff4444;"
                        "   border-radius: 15px;"
                        "   font-size: 48px;"
                        "   font-weight: bold;"
                        "   color: #ff4444;"
                        "}"
                        );
                }
            }
        }
    }
}

void GameBoard::updateStatus()
{
    char currentPlayer = gameLogic.getCurrentPlayer();
    if (currentPlayer == 'X') {
        ui->statusLabel->setText("Player X's Turn");
    } else {
        if (isVsComputer) {
            ui->statusLabel->setText("Computer's Turn (O)");
        } else {
            ui->statusLabel->setText("Player O's Turn");
        }
    }
}

void GameBoard::handleGameOver()
{
    char winner = gameLogic.checkWinner();

    QString message;
    if (winner == 'X') {
        message = "Player X Wins!";
        ui->statusLabel->setText("Game Over - X Wins!");
    } else if (winner == 'O') {
        if (isVsComputer) {
            message = "Computer Wins!";
            ui->statusLabel->setText("Game Over - Computer Wins!");
        } else {
            message = "Player O Wins!";
            ui->statusLabel->setText("Game Over - O Wins!");
        }
    } else if (winner == 'D') {
        message = "It's a Draw!";
        ui->statusLabel->setText("Game Over - Draw!");
    }

    disableAllButtons();

    // Show message box
    QMessageBox::information(this, "Game Over", message);
}

void GameBoard::disableAllButtons()
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            buttons[i][j]->setEnabled(false);
        }
    }
}

void GameBoard::enableAllButtons()
{
    updateBoard();  // This will enable only empty cells
}

void GameBoard::onResetClicked()
{
    gameLogic.initializeBoard();
    updateBoard();
    updateStatus();
    enableAllButtons();
}
void GameBoard::onMainMenuClicked()
{
    // Check if game ended with a winner
    char winner = gameLogic.checkWinner();

    if (winner == 'X' || winner == 'O') {
        // Ask for winner's name
        bool ok;
        QString winnerName = QInputDialog::getText(
            this,
            "Winner Name",
            "Enter winner's name:",
            QLineEdit::Normal,
            "",
            &ok
            );

        if (ok && !winnerName.isEmpty()) {
            scoreManager->addWin(winnerName);
        }
    }

    emit backToMainMenu();
    this->close();
}
