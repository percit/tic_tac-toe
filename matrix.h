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
    int amount_of_moves = 9; //WERSJA PROBNA, TA NIZEJ TO BEDZIE OSTATECZNA

public:
    Matrix(int a = 3, int b = 3): cols(a), rows(b) { //we give min size of 3x3 , MOZNA UPROSCIC DO JEDNEGO WYMIARU, ALE W WERSJI OSTATECZNEJ
        if((cols == rows) && (rows >=3) && (rows <=10)) {
            board.reserve(cols * rows);
        }
    }
    ~Matrix() {}
   // Matrix() = delete; //deleting default constructor
    //getters and setters
    void setCols( int a){ cols = a;}
    void setRows( int b){ rows = b;}
    void setMoves( int c){amount_of_moves = rows * cols;}
    int getCols(){ return cols;};
    int getRows(){ return rows;}
    int getMoves(){ return amount_of_moves;}
    // operator overloading
    char &operator()( int r,  int c);
    friend std::ostream& operator<<(std::ostream& out, Matrix& m);
    //functions
    void fill();
};
#endif //UNTITLED3_MATRIX_H
