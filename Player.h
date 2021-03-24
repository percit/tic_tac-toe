#ifndef UNTITLED3_PLAYER_H
#define UNTITLED3_PLAYER_H


class Player {
private:

public:
    unsigned int playerID; // 1 is X, 2 is O
    char TickOrToe;
    Player(unsigned int a, char b): playerID(a), TickOrToe(b){}
   // int getID(){return playerID;}
    //char getSign(){ return TickOrToe;}
};
#endif //UNTITLED3_PLAYER_H
