#include <iostream>
#include "game.h"
#include "player.h"

using namespace std;

//draws the board
void Game::drawGrid() {
    cout << endl;
    //\t = tab
    cout << "\t " << grid[0][0] << " | " << grid[0][1] << " | " << grid[0][2] << " \t" << endl;
    cout << "\t" << "---" << "|" << "---" << "|" << "---" << " \t" << endl;
    cout << "\t " << grid[1][0] << " | " << grid[1][1] << " | " << grid[1][2] << " \t" << endl;
    cout << "\t" << "---" << "|" << "---" << "|" << "---" << " \t" << endl;
    cout << "\t " << grid[2][0] << " | " << grid[2][1] << " | " << grid[2][2] << " \t" << endl;
    cout << endl;
}

//runs the game
bool Game::gameLoop(Player *p, int i) {
    //get x and y for player 1's turn
    int x, y;

    //boolean values to check for wins
    bool check1 = false;
    bool check2 = false;
    bool check3 = false;
    bool check4 = false;

    cout << "Player " << i << "'s turn: Please enter x and y co-ordinates: ";
    cin >> x >> y;
    //call the player's placeSymbol method to put the symbol in the right spot
    p->placeSymbol(x, y, grid);

    //draw the grid with new symbol
    drawGrid();

    //calls the player's check methods to see if there are any wins
    check1 = p->checkWinHorizontal(p, grid);
    check2 = p->checkWinVertical(p, grid);
    check3 = p->checkWinLeftDiagonal(p, grid);
    check4 = p->checkWinRightDiagonal(p, grid);
    //if win, print P wins!
    if (check1 || check2 || check3 || check4) {
        cout << "P" << i << " wins" << endl;
        //return true to show that a player has won
        return true;
    }

    //return false if all checks are false
    return false;
}

//checks if any moves can be made
bool Game::movesLeft(char grid[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] != ' ') {
                return false;
            }
        }
    }

    //moves can be made
    return true;
}

//evaluates possible placements
int Game::evaluate(Player *p, char grid[3][3]) {
    //checks if there are any wins possible in all directions
    bool check1 = p->checkWinHorizontal(p, grid);
    bool check2 = p->checkWinVertical(p, grid);
    bool check3 = p->checkWinLeftDiagonal(p, grid);
    bool check4 = p->checkWinRightDiagonal(p, grid);

    //if there are any wins, return a score of +10
    if (check1 || check2 || check3 || check4) {
        return +10;
    //no possible wins, return -10;
    } else {
        return -10;
    }


    return 0;
}

//implementing the minimax algorithm
int Game::minimax(char grid[3][3], int depth, bool isMax, Player *computer, Player *user) {
    //calls evaluate to get the score of possible moves
    int score = evaluate(computer, grid);

    //returns the score for any possible play
    if (score == 10) {
        return score;
    }
    if (score == -10) {
        return score;
    }

    //check for moves
    if (movesLeft(grid) == false) {
        return 0;
    }

    //check if it is the player's turn
    if (isMax) {
        //set a score to -1000 that will eventually be changed
        int best = -1000;

        //loop through the grid and check for an empty space
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (grid[i][j] == ' ') {
                    //set the empty space to the player's symbol;
                    grid[i][j] = computer->symbol;
                    //recursively call the minimax function, increasing the depth by 1
                    //as we are moving further down the tree
                    //set the result to the best value
                    best = minimax(grid, depth + 1, !isMax, computer, user);
                    //reset the space to being empty
                    grid[i][j] = ' ';
                }
            }
        }
        //return the best score from running through this loop
        return best;

    //repeat the same loops and checks, but for the computer
    } else {
        int best = 1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (grid[i][j] == ' ') {
                    grid[i][j] = user->symbol;
                    best = minimax(grid, depth + 1, !isMax, computer, user);
                    grid[i][j] = ' ';
                }
            }
        }
        return best;
    }

}

//find the best move for the computer to make
void Game::bestMove(char grid[3][3], Player *computer, Player *user) {
    //initialise the bestVal, row, and col values.
    int bestVal = -1000;
    int row = -1;
    int col = -1;

    //loop through the grid
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            //check if there is an empty space
            if (grid[i][j] == ' ') {
                //replace the empty space with the symbol.
                grid[i][j] = computer->symbol;
                //call the minimax function and set the result to the moveVal variable
                int moveVal = minimax(grid, 0, false, computer, user);
                //reset the space to be empty
                grid[i][j] = ' ';

                //if the score of the new move is greater than the new move:
                //change the values of row and col to i and j, and bestVal to moveVal;
                if (moveVal > bestVal) {
                    row = i;
                    col = j;
                    bestVal = moveVal;
                }
            }
        }
    }

    //place the symbol in the best calculated place
    computer->placeSymbol(row, col, grid);
}

//game loop for the computer
bool Game::gameLoopPC(Player *computer, char grid[3][3], Player *user) {
    //call the bestMove function, and hence the minimax algorithm
    bestMove(grid, computer, user);

    cout << "Computer's turn" << endl;

    //draw the grid with new symbol
    drawGrid();

    //calls the computer's check methods to see if there are any wins
    bool check1 = computer->checkWinHorizontal(computer, grid);
    bool check2 = computer->checkWinVertical(computer, grid);
    bool check3 = computer->checkWinLeftDiagonal(computer, grid);
    bool check4 = computer->checkWinRightDiagonal(computer, grid);
    //if win, print computer wins!
    if (check1 || check2 || check3 || check4) {
        cout << "Computer wins!" << endl;
        //return true to show that a player has won
        return true;
    }

    //return false if all checks are false
    return false;
}

//function for 1 player game
bool Game::onePlayerGame() {
    //draw grid
    drawGrid();

    //create player instances for both player 1 and 2
    Player *p1 = new Player('X');
    Player *p2 = new Player('O');

    //check variable to see if any player has won
    bool check = false;
    //game loop runs for max 9 times as there are 9 spots to place symbols
    for (int i = 0; i < 9; i++) {
        //run loop for p1
        check = gameLoop(p1, 1);
        //if p1 has won, free memory and return true
        if (check) {
            delete(p1);
            delete(p2);
            return true;
        }

        //run loop (and hence, minimax algorithm) for computer
        check = gameLoopPC(p2, grid, p1);
        //if computer has won, free memory and return true;
        if (check) {
            delete(p1);
            delete(p2);
            return true;
        }
    }

    //check is false, then tie
    //free memory
    delete(p1);
    delete(p2);

    cout << "TIE" << endl;

    return false;
}

//function for 2 player game
bool Game::twoPlayerGame() {
    //draw grid
    drawGrid();

    //create two instances of player, p1 and p2
    Player *p1 = new Player('X');
    Player *p2 = new Player('O');

    //check variable to see if any player has won
    bool check = false;
    //game loop runs for max 9 times as there are 9 spots to place symbols
    for (int i = 0; i < 9; i++) {
        //run loop for p1
        check = gameLoop(p1, 1);
        //if p1 has won, free memory and return true
        if (check) {
            delete(p1);
            delete(p2);
            return true;
        }

        //run loop for p2
        check = gameLoop(p2, 2);
        //if p2 has won, free memory and return true
        if (check) {
            delete(p1);
            delete(p2);
            return true;
        }
    }

    //check is false, then tie
    //free memory
    delete(p1);
    delete(p2);

    cout << "TIE" << endl;
    return false;
}


