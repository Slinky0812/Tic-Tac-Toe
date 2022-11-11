#include <iostream>
#include "player.h"

using namespace std;

void Player::placeSymbol(int x, int y, char grid[3][3]) {
    if (grid[x][y] == 'X' || grid[x][y] == 'O') {
        cout << "Cannot place symbol here" << endl;
        return;
    }

    grid[x][y] = symbol;
}
