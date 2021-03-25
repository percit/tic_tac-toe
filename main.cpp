#include "matrix.h"
#include "Player.h"
#include "Game.h"
int main(){
    //TESTING GAME CLASS


    //TESTING PLAYER CLASS


    //TESTING MATRIX CLASS
    Matrix m(3,3);
    m.fill();
    m.setValue(1,1,'x');
   // std::cout << m;
   // m.getMoves(); //nie dziala
    std::cout << m(1,1);




























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