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
    //getters and setters
    void setCols(unsigned int a){ cols = a;}
    void setRows(unsigned int b){ rows = b;}
    void setMoves(unsigned int c){amount_of_moves = rows * cols;}
    int getCols(){ return cols;};
    int getRows(){ return rows;}
    int getMoves(){ return amount_of_moves;}
    void setValue(unsigned int r, unsigned int c, char value){board.at(r + c * rows) = value;}
    char getValue(unsigned int r, unsigned int c){return board.at(r + c * rows);}
    // operator overloading
    char &operator()(unsigned int r, unsigned int c){if(r < rows && c < cols) return board.at(r + c * rows);} //no difference between rows and cols here
    friend std::ostream& operator<<(std::ostream& out, Matrix& m);
    //functions
    void fill();
};
#endif //UNTITLED3_MATRIX_H
