#include <iostream>
#include "player.h"

using namespace std;

char grid[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

void drawBoard() {
    cout << endl;
    cout << "\t " << grid[0][0] << " | " << grid[0][1] << " | " << grid[0][2] << " \t" << endl;
    cout << "\t" << "---" << "|" << "---" << "|" << "---" << " \t" << endl;
    cout << "\t " << grid[1][0] << " | " << grid[1][1] << " | " << grid[1][2] << " \t" << endl;
    cout << "\t" << "---" << "|" << "---" << "|" << "---" << " \t" << endl;
    cout << "\t " << grid[2][0] << " | " << grid[2][1] << " | " << grid[2][2] << " \t" << endl;
    cout << endl;
}

void gameLoop(Player *p1, Player *p2) {

    int x, y;
    cout << "Player 1's turn: Please enter x and y co-ordinates: ";
    cin >> x >> y;
    p1->placeSymbol(x, y, grid);
    drawBoard();

    cout << "Player 2's turn: Please enter x and y co-ordinates: ";
    cin >> x >> y;
    p2->placeSymbol(x, y, grid);
    drawBoard();
}

int main()
{
    cout << "Welcome to Tic-Tac-Toe" << endl;

    drawBoard();
    Player *p1 = new Player('X');
    Player *p2 = new Player('O');

    int count = 0;
    while (count < 9) {
        gameLoop(p1, p2);
        count++;
    }

    return 0;
}
