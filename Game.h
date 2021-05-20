#include "matrix.h"
#include "Player.h"
#ifndef UNTITLED3_GAME_H
#define UNTITLED3_GAME_H



struct Move
{
    int row = 0, col = 0;
};
class Game{
private:
    int winningID = 0; //winningNumber z wincondition.h
    int dimension = 3;
    Matrix m;
public:
    Game(int newDimension): m(newDimension, newDimension), dimension(newDimension)
    {
      // m(newDimension, newDimension);
    }
    void addMove( int ,  int, char);
    bool isMoveAllowed( int,  int);
    void resetBoard();
    void displayBoard();
    void setWinningID(int ID){winningID = ID;}
    int getWinningID(){ return winningID;}
    int getDimension(){ return dimension;}
    int getAmountOFMoves();
    void removeMove( int i,  int j);
    void fill(){m.fill();}
    void clear(){m.clear();}
    Matrix & returnMatrix(){return m;}
    //operators
    char& operator()( int r,  int c) {return m(r, c);}
    friend std::ostream& operator<<(std::ostream& out, Game& game){
        out << game.m;
        return out;
    }
    //MAIN FUNCTIONS
    int Winner(); //wszystkie mozliwe opcje i chyba wrzuc jako argument ten min dlugosci znakow, zeby wygrac
   // std::pair< int, std::pair<int, int> > MinMax(Game & gameBoard, Player player1, Player player2, bool minOrMax, Game condition, int depth);
  // int minimax(Game & gameBoard, int depth, bool isMax, int alpha, int beta);

    //Game condition to to samo co z Wincondition condition

   // void Management();

};
//random managment functions
void playerMove(Game& board);
void aiMove(Game& board);
void Management(Game& board);

#endif //UNTITLED3_GAME_H
