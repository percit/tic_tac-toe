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
    unsigned int winningID; //winningNumber z wincondition.h
    unsigned int dimension;
public:
    void addMove(unsigned int , unsigned int, Player); //tutaj bedzie jeszcze argument player
    bool isMoveAllowed(unsigned int, unsigned int);
    void resetBoard();
    void displayBoard(Player, Player);
    unsigned int getWinningID(){ return winningID;}
    int Winner(Game & , Player , Player ); //wszystkie mozliwe opcje i chyba wrzuc jako argument ten min dlugosci znakow, zeby wygrac
    //https://github.com/adamek195/TicTacToe-AI/blob/master/TicTacToeGame/TicTacToeGame/Board.cpp tutaj jest funkcja check zamiast winner, moze jest lepsza...
    //https://github.com/emilia-szymanska/TicTacToe/blob/master/src/WinCondition.cpp
    std::pair< int, std::pair<int, int> > MinMax(Game & gameBoard, Player player1, Player player2, bool minOrMax, Game condition, int depth);
    //Game condition to to samo co z Wincondition condition
    void removeMove(unsigned int i, unsigned int j);
    Matrix & returnMatrix(){
        return m;
    }
    void Management();
    Game(unsigned int newDimension)
    {
        this->dimension = newDimension;
        this->m = Matrix(newDimension, newDimension);
    }
};


#endif //UNTITLED3_GAME_H
