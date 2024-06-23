#include "matrix.h"
#ifndef UNTITLED3_GAME_H
#define UNTITLED3_GAME_H



struct Move
{
    int row = 0, col = 0;
};
class Game{
private:
    int dimension = 3;
    Matrix m;
public:
    explicit Game(int newDimension): m(newDimension, newDimension), dimension(newDimension){
        if(newDimension < 3){
            std::cout << "Board too small" << std::endl;
            std::abort();
        }
    }
    void addMove(const int& r, const int& c, const char& player){ if(m(r,c) == '-')  m(r, c) = player;}
    bool isMoveAllowed(const int&,  const int&);
    void resetBoard(){ m.clear();}
    [[nodiscard]] int getDimension() const{ return dimension;}
    int getAmountOFMoves();
    void removeMove(const int& i, const int& j){m(i,j) = '-';}
    void clear(){m.clear();}
    Matrix & returnMatrix(){return m;}
    //operators
    char& operator()(const int& r, const int& c) {return m(r, c);}
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
