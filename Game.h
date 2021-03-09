#include "matrix.h"
#include "Player.h"
#ifndef UNTITLED3_GAME_H
#define UNTITLED3_GAME_H


class Game: public Matrix, public Player {
private:
    Matrix m;
    unsigned int winningID;
public:
    void addMove(unsigned int , unsigned int, Player ); //tutaj bedzie jeszcze argument player
    bool isMoveAllowed(unsigned int, unsigned int);
    void resetBoard();
    void displayBoard(Player, Player);
    unsigned int getWinningID(){ return winningID;}
    int Winner(Game & , Player , Player ); //wszystkie mozliwe opcje i chyba wrzuc jako argument ten min dlugosci znakow, zeby wygrac
};


#endif //UNTITLED3_GAME_H
