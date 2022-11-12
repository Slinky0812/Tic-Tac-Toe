#ifndef GAME_H
#define GAME_H
#include "player.h"

class Game
{
public:
    Game() {};
    void drawGrid();
    bool gameLoop(Player *p, int i);
    bool minMax(Player *p, int i);
    bool onePlayerGame();
    bool twoPlayerGame();

    //functions to implement minmax algorithm
    void bestMove(char grid[3][3], Player *p, Player *user);
    int minimax(char grid[3][3], int depth, bool isMax, Player *computer, Player *user);
    bool movesLeft(char grid[3][3]);
    int evaluate(Player *p, char grid[3][3]);
    bool gameLoopPC(Player *computer, char grid[3][3], Player *user);

    char grid[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
};

#endif // GAME_H
