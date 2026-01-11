#ifndef GAMELOGIC_H
#define GAMELOGIC_H

class GameLogic
{
public:
    GameLogic();  // Constructor

    // Core game functions
    void initializeBoard();           // Reset the board
    bool makeMove(int row, int col, char player);  // Place X or O
    char checkWinner();               // Returns 'X', 'O', 'D' (draw), or 'N' (none)
    bool isBoardFull();               // Check if game is a draw
    char getCurrentPlayer();          // Returns 'X' or 'O'
    void switchPlayer();              // Toggle between X and O
    char getCellValue(int row, int col);  // Get what's in a cell

    // Computer AI functions
    bool makeComputerMove();          // Computer makes a move

private:
    char board[3][3];      // 2D array to store the game state
    char currentPlayer;    // 'X' or 'O'

    // Helper functions for computer AI
    bool tryToWin();       // Computer tries to win
    bool tryToBlock();     // Computer tries to block player
    void makeRandomMove(); // Computer picks random empty cell
    bool checkLine(int r1, int c1, int r2, int c2, int r3, int c3, char player);
};

#endif // GAMELOGIC_H
