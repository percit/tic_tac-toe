#include "matrix.h"
#include <exception>

std::ostream& operator<<( std::ostream& out, Matrix& m){
    for(int i = 0; i < m.rows; i++){
        for(int j = 0; j < m.cols; j++){
            std::cout<< " | " << m(i, j) ;
        }
        std::cout << " | " << std::endl;
    }
    return out;
}
char& Matrix::operator()(const int& r, const  int& c){
    if(r < rows && c < cols)
        return board.at(r + c * rows);
    else {
        std::cout << "r: " << r << " c: " << c;
        throw std::invalid_argument("out of bounds");
    }
}

void Matrix::clear() {
    if(!board.empty()){
        std::fill(board.begin(), board.end(), '-');
    }
}
