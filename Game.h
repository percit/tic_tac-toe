#include "matrix.h"
#include "Player.h"
#ifndef UNTITLED3_GAME_H
#define UNTITLED3_GAME_H

// struktura opisujaca ruch ai
struct Move
{
    int row, col;
};
class Game: public Matrix {
private:
    Matrix m;
    int winningID; //winningNumber z wincondition.h
    int dimension;
public:
    Game( int newDimension)
    {
        this->dimension = newDimension;
        this->m = Matrix(newDimension, newDimension);
    }
    void addMove( int ,  int, Player);
    bool isMoveAllowed( int,  int);
    void resetBoard();
    void displayBoard(Player, Player);
    unsigned int getWinningID(){ return winningID;}
    void removeMove( int i,  int j);
    Matrix & returnMatrix(){
        return m;
    }
    //MAIN FUNCTIONS
    int Winner(Game & , Player , Player ); //wszystkie mozliwe opcje i chyba wrzuc jako argument ten min dlugosci znakow, zeby wygrac
    //https://github.com/adamek195/TicTacToe-AI/blob/master/TicTacToeGame/TicTacToeGame/Board.cpp tutaj jest funkcja check zamiast winner, moze jest lepsza...
    //https://github.com/emilia-szymanska/TicTacToe/blob/master/src/WinCondition.cpp
    std::pair< int, std::pair<int, int> > MinMax(Game & gameBoard, Player player1, Player player2, bool minOrMax, Game condition, int depth);
    //Game condition to to samo co z Wincondition condition

    void Management();

};


#endif //UNTITLED3_GAME_H
