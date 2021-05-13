#ifndef UNTITLED3_PLAYER_H
#define UNTITLED3_PLAYER_H


class Player {
private:
    int playerID = 0; // 1 is X, 2 is O // w sumie mozesz to zmienic na enum
    char sign = '-';
public:
    Player( int a, char b): playerID(a), sign(b){}//wybieram id playera, czyli 1/2, a potem znak
    [[nodiscard]] int getID() const{return playerID;}
    char getSign(){ return sign;}
};
#endif //UNTITLED3_PLAYER_H
