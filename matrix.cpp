#include "matrix.h"

void Matrix::fill(){
     for(int i = 0; i < rows * cols; i++){
     board.push_back('-');//zamien na cos innego debilu XD
         /*
     std::fill(board.begin(), board.end(), static_cast<char>(numbers);
          numbers++;
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
