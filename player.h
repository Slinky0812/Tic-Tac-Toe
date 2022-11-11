#ifndef PLAYER_H
#define PLAYER_H


class Player {
public:
    //the player's symbol ('X' or 'O')
    char symbol;
    //constructor
    Player(char s) { symbol = s; };
    //function to place the symbol in the right spot
    void placeSymbol(int x, int y, char grid[3][3]);
    bool checkWinHorizontal(Player *p, char grid[3][3], int x);
    bool checkWinVertical(Player *p, char grid[3][3], int y);
    bool checkWinDiagonal(Player *p, char grid[3][3]);
};

#endif // PLAYER_H
