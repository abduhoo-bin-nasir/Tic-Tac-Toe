#include "gamelogic.h"
#include <cstdlib>  // For random number generation
#include <ctime>    // For seeding random

GameLogic::GameLogic()
{
    // Seed random number generator once when object is created
    srand(time(0));
    initializeBoard();
}

void GameLogic::initializeBoard()
{
    // Fill all cells with space character (empty)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
    currentPlayer = 'X';  // X always starts
}

bool GameLogic::makeMove(int row, int col, char player)
{
    // Check if position is valid and empty
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        return false;  // Out of bounds
    }

    if (board[row][col] != ' ') {
        return false;  // Cell already occupied
    }

    // Make the move
    board[row][col] = player;
    return true;
}

char GameLogic::getCellValue(int row, int col)
{
    return board[row][col];
}

char GameLogic::getCurrentPlayer()
{
    return currentPlayer;
}

void GameLogic::switchPlayer()
{
    // Toggle between X and O
    if (currentPlayer == 'X') {
        currentPlayer = 'O';
    } else {
        currentPlayer = 'X';
    }
}

bool GameLogic::isBoardFull()
{
    // Check if any cell is empty
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;  // Found an empty cell
            }
        }
    }
    return true;  // All cells filled
}

char GameLogic::checkWinner()
{
    // Check all 3 rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2] &&
            board[i][0] != ' ') {
            return board[i][0];  // Return 'X' or 'O'
        }
    }

    // Check all 3 columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] &&
            board[1][j] == board[2][j] &&
            board[0][j] != ' ') {
            return board[0][j];
        }
    }

    // Check diagonal (top-left to bottom-right)
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2] &&
        board[0][0] != ' ') {
        return board[0][0];
    }

    // Check diagonal (top-right to bottom-left)
    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0] &&
        board[0][2] != ' ') {
        return board[0][2];
    }

    // Check for draw
    if (isBoardFull()) {
        return 'D';  // Draw
    }

    return 'N';  // No winner yet (None)
}

// Computer AI Implementation
bool GameLogic::makeComputerMove()
{
    // Strategy 1: Try to win
    if (tryToWin()) {
        return true;
    }

    // Strategy 2: Block player from winning
    if (tryToBlock()) {
        return true;
    }

    // Strategy 3: Make random move
    makeRandomMove();
    return true;
}

bool GameLogic::tryToWin()
{
    // Check each empty cell - if placing O there wins, do it
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                // Temporarily place O
                board[i][j] = 'O';

                // Check if this creates a win
                if (checkWinner() == 'O') {
                    return true;  // Keep the move
                }

                // Undo the move
                board[i][j] = ' ';
            }
        }
    }
    return false;
}

bool GameLogic::tryToBlock()
{
    // Check each empty cell - if placing X there would win for player, block it
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                // Temporarily place X (opponent)
                board[i][j] = 'X';

                // Check if this would win for X
                if (checkWinner() == 'X') {
                    // Block by placing O here
                    board[i][j] = 'O';
                    return true;
                }

                // Undo the test move
                board[i][j] = ' ';
            }
        }
    }
    return false;
}

void GameLogic::makeRandomMove()
{
    // Collect all empty cells
    int emptyCells[9][2];  // Max 9 empty cells, each stores [row, col]
    int count = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                emptyCells[count][0] = i;
                emptyCells[count][1] = j;
                count++;
            }
        }
    }

    // Pick a random empty cell
    if (count > 0) {
        int randomIndex = rand() % count;
        int row = emptyCells[randomIndex][0];
        int col = emptyCells[randomIndex][1];
        board[row][col] = 'O';
    }
}
