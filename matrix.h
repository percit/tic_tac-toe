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
   // int number = 0;//TO MA WYPELNIC MATRIX, ALE NARAZIE NIE DZIALA
    int amount_of_moves =  rows * cols; //WERSJA PROBNA, TA NIZEJ TO BEDZIE OSTATECZNA

public:
    explicit Matrix(int a = 3, int b = 3): cols(a), rows(b) { //we give min size of 3x3 , MOZNA UPROSCIC DO JEDNEGO WYMIARU, ALE W WERSJI OSTATECZNEJ
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
    Matrix(Matrix &&m) noexcept{
        cols = m.cols;
        rows = m.rows;
        board = m.board;
        //deleting copies
        m.cols = 0;
        m.rows = 0;
        m.board.clear();
    }
    //getters and setters
    void setCols( int a){ cols = a;}
    void setRows( int b){ rows = b;}
    void setMoves( int c){amount_of_moves = c;} // nie dziala
    int getCols(){ return cols;}
    int getRows(){ return rows;}
    int getMoves(){ return amount_of_moves;}
    // operator overloading
    char &operator()( int r,  int c);
    friend std::ostream& operator<<(std::ostream& out, Matrix& m);
    //functions
    void fill();
    void clear();
};
#endif //UNTITLED3_MATRIX_H
