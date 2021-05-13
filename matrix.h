#ifndef UNTITLED3_MATRIX_H
#define UNTITLED3_MATRIX_H
#include <iostream>
#include <vector>

class Matrix
{
private:
    int cols = 0;
    int rows = 0;
    std::vector<char> board;
    int amount_of_moves =  rows * cols; //WERSJA PROBNA, TA NIZEJ TO BEDZIE OSTATECZNA

public:
    explicit Matrix(int a = 3, int b = 3): cols(a), rows(b) {
        if((cols == rows) && (rows >=3) && (rows <=10)) {
            board.reserve(cols * rows);
        }
    }
    virtual ~Matrix()  = default;
    Matrix() = delete; //deleting default constructor
    Matrix(const Matrix &m){ //copy constructor
        cols = m.cols;
        rows = m.rows;
        board = m.board;
    }
    Matrix(Matrix &&m) noexcept :  cols(m.cols),  rows(m.rows),  board(std::move(m.board)){} //coping cols and rows, cause they are just ints
    //getters and setters
    void setCols( int a){ cols = a;}
    void setRows( int b){ rows = b;}
    void setMoves( int c){amount_of_moves = c;}
    [[nodiscard]] int getCols() const{ return cols;}
    int getRows(){ return rows;}
    [[nodiscard]] int getMoves() const{ return amount_of_moves;} //POTTENTIALLY NOT NEEDED
    // operator overloading
    char &operator()( int r,  int c);
    friend std::ostream& operator<<(std::ostream& out, Matrix& m);
    //functions
    void fill();
    void clear();
};
#endif //UNTITLED3_MATRIX_H
