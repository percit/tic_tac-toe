#include "matrix.h"
#include "Player.h"
#include "Game.h"
int main(){
    //TESTING GAME CLASS
    Game game1(3);
    Player player1(1, 'X');
    game1.isMoveAllowed(1,1);
    //game1.addMove(1,1, player1);
    //game1.isMoveAllowed(1,1);
    //game1.resetBoard();
    //game1.displayBoard();
    //TESTING PLAYER CLASS
    /*
    Player player1(1, 'X');
    std::cout << player1.getID();
    std::cout << player1.getSign();
    */

    //TESTING MATRIX CLASS
    /*
    Matrix m(3,3);
    m.fill();
    m(1,1) = 'x';
    std:: cout << m.getMoves();
    std::cout << m;
    std::cout << m(1,1);
    */



























    /*
    int size = 0;
   // int sing_length = 0;
    Player player1(1, 'X');
    Player player2(2, 'O');
    std::cout << "Say the dimensions of matrix" << std::endl;
    std::cin >> size;
    //Matrix m(size, size);
    Game g(size);
    g.fill();
    std::cout<< g;
   // g.addMove(2,2, player1);// pamietaj, ze od zera liczymy
    //std::cout << g;
    */


    return 0;
}