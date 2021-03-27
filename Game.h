#include "matrix.h"
#include "Player.h"
#ifndef UNTITLED3_GAME_H
#define UNTITLED3_GAME_H


struct Move
{
    int row, col;
};
class Game: public Matrix {
private:
    int winningID = 0; //winningNumber z wincondition.h
    int dimension = 3;
    Matrix m;
public:
    Game(int newDimension): m(newDimension, newDimension), dimension(newDimension)
    {
      // m(newDimension, newDimension);
    }
    void addMove( int ,  int, Player);
    bool isMoveAllowed( int,  int);
    void resetBoard();
    void displayBoard();
    int getWinningID(){ return winningID;}
    void removeMove( int i,  int j);

    Matrix & returnMatrix(){
        return m;
    }

    //MAIN FUNCTIONS
    int Winner(Game & , Player , Player ); //wszystkie mozliwe opcje i chyba wrzuc jako argument ten min dlugosci znakow, zeby wygrac
    std::pair< int, std::pair<int, int> > MinMax(Game & gameBoard, Player player1, Player player2, bool minOrMax, Game condition, int depth);
    //Game condition to to samo co z Wincondition condition

    void Management();

};


#endif //UNTITLED3_GAME_H
