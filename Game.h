#include "matrix.h"
#ifndef UNTITLED3_GAME_H
#define UNTITLED3_GAME_H



struct Move
{
    int row = 0, col = 0;
};
class Game{
private:
   // int winningID = 0; //winningNumber z wincondition.h
    int dimension = 3;
    Matrix m;
public:
    Game(int newDimension): m(newDimension, newDimension), dimension(newDimension){}
    void addMove( int r,  int c, char player){ if(m(r,c) == '-')  m(r, c) = player;}
    bool isMoveAllowed( int,  int);
    void resetBoard(){ m.clear();}
    [[nodiscard]] int getDimension() const{ return dimension;}
    int getAmountOFMoves();
    void removeMove( int i,  int j){m(i,j) = '-';}
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
    int Winner();


};
//random managment functions
void playerMove(Game& board);
void aiMove(Game& board);
void Management(Game& board);

#endif //UNTITLED3_GAME_H
