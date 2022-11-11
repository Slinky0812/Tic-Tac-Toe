#include <iostream>
#include "player.h"

using namespace std;

//grid of the board, initialising it with empty characters
char grid[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

//draws the board
void drawGrid() {
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
bool gameLoop(Player *p, int i) {
    //get x and y for player 1's turn
    int x, y;
    //boolean values to check for wins
    bool check1 = false;
    bool check2 = false;
    bool check3 = false;

    cout << "Player " << i << "'s turn: Please enter x and y co-ordinates: ";
    cin >> x >> y;
    //call the player's placeSymbol method to put the symbol in the right spot
    p->placeSymbol(x, y, grid);


    drawGrid();
    //calls the player's check methods to see if there are any wins
    check1 = p->checkWinHorizontal(p, grid, x);
    check2 = p->checkWinVertical(p, grid, y);
    check3 = p->checkWinDiagonal(p, grid);
    //if win, print P wins!
    if (check1 || check2 || check3) {
        cout << "P" << i << " wins" << endl;
        //return true to show that a player has won
        return true;
    }

    return false;
}

//main function
int main() {
    cout << "Welcome to Tic-Tac-Toe" << endl;

    //draw grid
    drawGrid();

    //create two instances of player, p1 and p2
    Player *p1 = new Player('X');
    Player *p2 = new Player('O');

    //game loop runs for max 9 times as there are 9 spots to place symbols
    bool check = false;
    for (int i = 0; i < 9; i++) {
        //run loop for p1
        check = gameLoop(p1, 1);
        //if p1 has won, break
        if (check) {
            break;
        }

        //run loop for p2
        check = gameLoop(p2, 2);
        //if p2 has won, breaks
        if (check) {
            break;
        }
    }

    //if check is false, then tie
    if (check == false) {
        cout << "TIE" << endl;
    }

    //free memory
    delete(p1);
    delete(p2);

    return 0;
}
