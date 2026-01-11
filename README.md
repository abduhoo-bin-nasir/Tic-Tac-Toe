Here. Short, clean, GitHub-appropriate. Reads like you know what you’re doing without trying too hard.

---

# Tic-Tac-Toe Game (C++ / Qt)

A desktop-based **Tic-Tac-Toe game** developed using **C++** and the **Qt Widgets framework**.
The project demonstrates core programming concepts along with GUI development and file handling.

## Features

* Player vs Player mode
* Player vs Computer mode with intelligent AI (win, block, random strategy)
* Automatic win and draw detection
* Input validation and rule enforcement
* Modern dark-themed GUI using Qt Widgets
* Persistent scoreboard stored in a text file
* Reset game and main menu navigation

## Technologies Used

* **Language:** C++
* **GUI Framework:** Qt 6 (Qt Widgets)
* **IDE:** Qt Creator
* **Build System:** qmake
* **Data Storage:** Plain text file (`scores.txt`)

## AI Strategy

The computer opponent follows a simple three-step priority:

1. Make a winning move if available
2. Block the opponent’s winning move
3. Choose a random valid move

This makes the AI challenging but not unbeatable.

## Project Structure

* `MainWindow` – Main menu and navigation
* `GameBoard` – GUI handling and user interaction
* `GameLogic` – Game rules, win detection, and AI
* `ScoreManager` – File handling and score persistence

## How to Run

1. Open the project in **Qt Creator**
2. Configure the kit (MinGW/GCC)
3. Build and run the project

## Future Improvements

* Advanced AI (Minimax)
* Animations and sound effects
* Online multiplayer support
* Variable board sizes

---

That’s it.
Not bloated, not cringe, not empty. Perfect for a uni GitHub repo.

