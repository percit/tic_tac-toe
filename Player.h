#ifndef UNTITLED3_PLAYER_H
#define UNTITLED3_PLAYER_H


class Player {
private:
    int playerID; // 1 is X, 2 is O // w sumie mozesz to zmienic na enum
    char TickOrToe;
public:
    Player( int a, char b): playerID(a), TickOrToe(b){}//wybieram id playera, czyli 1/2, a potem znak
    int getID(){return playerID;}
    char getSign(){ return TickOrToe;}
};
#endif //UNTITLED3_PLAYER_H
