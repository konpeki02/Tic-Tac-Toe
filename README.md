# Tic-Tac-Toe
**Overview**
- This is a Tic-Tac-Toe game implemented in C++ which allows the user to play from the terminal
----
**Features**:
- Implemented in c++ using vector and while loops in an algorithm
- Validated the functionality of game through manual testing located in *test.txt*
- Header File implemented to write the number of wins per player
- Implements algorithm to determine a player or computer win and draw
- ex: `Player 1-4-7 vertical win`
  `Computer 1-5-9 diagonal win`
  `Draw`
- Prevents garbage data from being entered and prompts user to select new square if tile is already chosen
- Previous moves from game can be viewed 
----
## Screen Shots
<img width="192" alt="Start of Game" src="https://user-images.githubusercontent.com/92644639/162825411-2bbd6a31-467b-4d85-b2a8-339d0b529c69.png">

+ Start of game, user is prompted to choose a tile.

----
<img width="249" alt="Player Win" src="https://user-images.githubusercontent.com/92644639/162825472-e8f5c2f3-54e2-4ee0-b870-4b6e2d728a52.png">

+ Player Wins, is prompted to play again
----
<img width="634" alt="Computer Win" src="https://user-images.githubusercontent.com/92644639/162825510-913ada52-b2b8-4551-afb6-3d4583213ba0.png">

+ Computer wins, player is prompted to play again
 ----


## File Details
- *main.cpp* - This file contains the source code for the main file
- *iofiles.h* - This is the header file that allows writing and reading from text files
- *test.txt* - File allows for manual testing to make sure game is running correctly

## How to Run the Game
1. Download all the files from the repository.
2. Compile from the terminal `g++ -o output main.cpp`
3. Run `./output`

## Game Menu

Player can select `Y/N` to:
- view past games
- quit game/play again
- search past games
- view moves of previous game




