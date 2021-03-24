#include "matrix.h"
#include <exception>

void Matrix::fill(){
     for(int i = 0; i < rows * cols; i++){
     board.push_back('-');//zamien na cos innego debilu XD
         /*
     std::fill(board.begin(), board.end(), static_cast<char>(numbers);
          numbers++; no i tutaj powinno byc getNumbers czy jakos tak
    */
     }
}
std::ostream& operator<<(std::ostream& out, Matrix& m){ //przenies do pliku matrix.cpp
    for(int i = 0; i < m.rows; i++){
        for(int j = 0; j < m.cols; j++){
            //std::cout<< m.getValue(i, j);
            std::cout<< " | " << m(i, j) ;
        }
        std::cout << " | " << std::endl;
    }
    return out;
}
char& Matrix::operator()( int r,  int c){
    if(r < rows && c < cols)
        return board.at(r + c * rows);
    else
        throw std::invalid_argument("dupa");
}