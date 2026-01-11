#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , gameBoard(nullptr)
    , scoreManager(nullptr)
{
    ui->setupUi(this);

    // Create score manager
    scoreManager = new ScoreManager();

    this->setStyleSheet(
        "QMainWindow {"
        "   background-color: #1e1e1e;"
        "}"
        );

    // Title styling
    ui->titleLabel->setStyleSheet(
        "QLabel {"
        "   color: #00d4ff;"
        "   font-size: 36px;"
        "   font-weight: bold;"
        "   padding: 20px;"
        "   background: transparent;"
        "}"
        );

    // Button styling - FIXED: Define buttonStyle BEFORE using it
    QString buttonStyle =
        "QPushButton {"
        "   background-color: #2d2d2d;"
        "   color: white;"
        "   border: 2px solid #00d4ff;"
        "   border-radius: 10px;"
        "   padding: 15px;"
        "   font-size: 18px;"
        "   font-weight: bold;"
        "}"
        "QPushButton:hover {"
        "   background-color: #3d3d3d;"
        "   border: 2px solid #00ffff;"
        "}"
        "QPushButton:pressed {"
        "   background-color: #1d1d1d;"
        "}";

    ui->btnPlayerVsPlayer->setStyleSheet(buttonStyle);
    ui->btnPlayerVsComputer->setStyleSheet(buttonStyle);
    ui->btnViewScoreboard->setStyleSheet(buttonStyle);  // Now buttonStyle is defined

    // Exit button (red accent)
    ui->btnExit->setStyleSheet(
        "QPushButton {"
        "   background-color: #2d2d2d;"
        "   color: white;"
        "   border: 2px solid #ff4444;"
        "   border-radius: 10px;"
        "   padding: 15px;"
        "   font-size: 18px;"
        "   font-weight: bold;"
        "}"
        "QPushButton:hover {"
        "   background-color: #3d3d3d;"
        "   border: 2px solid #ff6666;"
        "}"
        "QPushButton:pressed {"
        "   background-color: #1d1d1d;"
        "}"
        );

    // Connect buttons
    connect(ui->btnPlayerVsPlayer, &QPushButton::clicked,
            this, &MainWindow::onPlayerVsPlayerClicked);

    connect(ui->btnPlayerVsComputer, &QPushButton::clicked,
            this, &MainWindow::onPlayerVsComputerClicked);

    connect(ui->btnExit, &QPushButton::clicked,
            this, &MainWindow::onExitClicked);

    connect(ui->btnViewScoreboard, &QPushButton::clicked,
            this, &MainWindow::onViewScoreboardClicked);
}

MainWindow::~MainWindow()
{
    if (gameBoard) {
        delete gameBoard;
    }
    delete scoreManager;
    delete ui;
}

void MainWindow::onPlayerVsPlayerClicked()
{
    if (!gameBoard) {
        gameBoard = new GameBoard();
        // Connect back signal
        connect(gameBoard, &GameBoard::backToMainMenu,
                this, &MainWindow::show);
    }

    gameBoard->setGameMode(false);
    gameBoard->show();
    this->hide();
}

void MainWindow::onPlayerVsComputerClicked()
{
    if (!gameBoard) {
        gameBoard = new GameBoard();
        connect(gameBoard, &GameBoard::backToMainMenu,
                this, &MainWindow::show);
    }

    gameBoard->setGameMode(true);
    gameBoard->show();
    this->hide();
}

void MainWindow::onExitClicked()
{
    // Close the application
    QApplication::quit();
}

void MainWindow::onViewScoreboardClicked()
{
    scoreManager->loadFromFile();  // Refresh from file
    QMap<QString, int> scores = scoreManager->getScores();

    QString message;

    if (scores.isEmpty()) {
        message = "No scores recorded yet!\n\nPlay some games to see scores here.";
    } else {
        message = "=== SCOREBOARD ===\n\n";

        // Show each player and their wins
        for (auto it = scores.begin(); it != scores.end(); ++it) {
            message += QString("%1: %2 wins\n")
                           .arg(it.key())
                           .arg(it.value());
        }
    }

    QMessageBox::information(this, "Scoreboard", message);
}
