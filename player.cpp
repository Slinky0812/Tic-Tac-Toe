#include <iostream>
#include "player.h"

using namespace std;

void Player::placeSymbol(int x, int y, char grid[3][3]) {

    //checks if there is already something in this spot
    if (grid[x][y] == 'X' || grid[x][y] == 'O') {
        cout << "Cannot place symbol here" << endl;
        return;
    }

    //adds the character to the right spot
    grid[x][y] = symbol;
}

bool Player::checkWinHorizontal(Player *p, char grid[3][3], int x) {

    int count = 0;

    for (int i = 0; i < 3; i++) {
        if (grid[x][i] == p->symbol) {
            count++;
        }
    }

    if (count == 3) {
        cout << "here horiz" << endl;
        return true;
    } else {
        return false;
    }
}

bool Player::checkWinVertical(Player *p, char grid[3][3], int y) {

    int count = 0;

    for (int i = 0; i < 3; i++) {
        if (grid[i][y] == p->symbol) {
            count++;
        }
    }

    if (count == 3) {
        cout << "here vert" << endl;
        return true;
    } else {
        return false;
    }
}

bool Player::checkWinDiagonal(Player *p, char grid[3][3]) {

    int count = 0;

    for (int i = 0; i < 3; i++) {
        if (grid[i][i] == p->symbol) {
            count++;
        }
    }

    if (count == 3) {
        cout << "here diag" << endl;
        return true;
    } else {
        return false;
    }
}
