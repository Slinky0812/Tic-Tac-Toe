#include <iostream>
#include "game.h"

using namespace std;

//main function
int main() {
    cout << "Welcome to Tic-Tac-Toe" << endl;

    cout << "" << endl;

    cout << "Player 1 - X" << endl;
    cout << "Player 2 - O" << endl;

    cout << "" << endl;

    //number of players given by the user
    int numOfPlayers;
    cout << "One player or Two players? ";
    cin >> numOfPlayers;

    //instance of new game
    Game *game = new Game();

    //call the right function depending on the number of players
    if (numOfPlayers == 1) {
        game->onePlayerGame();
    } else if (numOfPlayers == 2) {
        game->twoPlayerGame();
    } else {
        cout << "Wrong number of players" << endl;
    }

    delete(game);
    return 0;
}
