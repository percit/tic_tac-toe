#ifndef UNTITLED3_PLAYER_H
#define UNTITLED3_PLAYER_H


class Player {
private:

public:
    int playerID; // 1 is X, 2 is O
    char TickOrToe;
    Player( int a, char b): playerID(a), TickOrToe(b){}//wybieram id playera, czyli 1/2, a potem znak
   // int getID(){return playerID;}
    //char getSign(){ return TickOrToe;}
};
#endif //UNTITLED3_PLAYER_H
