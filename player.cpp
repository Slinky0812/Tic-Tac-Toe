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

bool Player::checkWinHorizontal(Player *p, char grid[3][3]) {

    for (int i = 0; i < 3; i++) {
        if (grid[0][i] == p->symbol && grid[1][i] == p->symbol && grid[2][i] == p->symbol) {
            return true;
        }
    }

    return false;
}

bool Player::checkWinVertical(Player *p, char grid[3][3]) {

    for (int i = 0; i < 3; i++) {
        if (grid[i][0] == p->symbol && grid[i][1] == p->symbol && grid[i][2] == p->symbol) {
            return true;
        }
    }

    return false;
}

bool Player::checkWinLeftDiagonal(Player *p, char grid[3][3]) {

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

bool Player::checkWinRightDiagonal(Player *p, char grid[3][3]) {
    if (grid[0][2] == p->symbol && grid[1][1] == p->symbol && grid[2][0] == p->symbol) {
        return true;
    } else {
        return false;
    }
}
