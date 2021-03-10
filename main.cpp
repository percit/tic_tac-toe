#include "matrix.h"

int main(){
    int size = 0;
    int sing_length = 0;
    std::cout << "Say the dimensions of matrix" << std::endl;
    std::cin >> size;
    Matrix m(size, size);
    m.fill();
    std::cout << m;




    /*drawBoard();
    std::cout << "\n";
    current_marker = 'x';
    placeMarker(8);
    drawBoard();*/
    return 0;
}