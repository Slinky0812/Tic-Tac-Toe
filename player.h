#ifndef PLAYER_H
#define PLAYER_H


class Player
{
private:
    char symbol;
public:
    Player(char s) { symbol = s; };
    void placeSymbol(int x, int y, char grid[3][3]);
};

#endif // PLAYER_H
