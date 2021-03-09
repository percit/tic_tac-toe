#include "Game.h"

void Game::addMove(unsigned int r, unsigned int c, Player player) {
    //pomysl czy trza sprawdzac tu wymiary, czy w przeciazeniu ()
    char sign;
    if(player.getID() == 1){
        sign = 'X';
    }
    else sign = 'O';
    m.setValue(r, c, sign);
}
bool Game::isMoveAllowed(unsigned int r, unsigned int c) {
    if((m.getValue(r, c) == 'X') || (m.getValue(r, c) == 'O'))
        return false;
}
void Game::resetBoard() {
    m.fill();//a kto mi tak pisac zabroni XD
}
int Game::Winner(Game &game1, Player player1, Player player2) {
    //sprawdz czy pionowo i poziomo cos sie znajdzie
    //mozna w sumie podzielic na 3 funckje,
    //zacznij od sprawdzania max dlugosci
    //jade po pierwszej linice, i sprawdzam, czy kazdy znak to X albo O
    int winningPlayer = 0;
    int lineO_1 = 0, lineX_1 = 0,lineO_2 = 0, lineX_2 = 0;//checks for number of signs in a line
    for (int i = 0; i < m.getCols(); i++) { //poziomo
        for (int j = 0; j < m.getCols(); j++) {
            if (m.getValue(i, j) == 'X')   //   JAK BEDE ZMIENIAC NA TE Z ODPOWIEDNIA DLUGOSCIA TO TU BEDE ZMIENIAL KOD
                lineX_1++;
            else if (m.getValue(i, j) == 'O')
                lineO_1++;
        }
        if(lineO_1 == m.getCols())
            winningPlayer = 1;
        else if(lineX_1 == m.getCols())
            winningPlayer = 2;
        else{
            lineO_1 = 0;
            lineX_1 = 0;
        }
    }
    for (int i = 0; i < m.getCols(); i++) { //pionowo
        for (int j = 0; j < m.getCols(); j++) {
            if (m.getValue(j, i) == 'X')   //   sprawdz czy to dziala xd
                lineX_1++;
            else if (m.getValue(i, j) == 'O')
                lineO_1++;
        }
        if(lineO_1 == m.getCols())
            winningPlayer = 1;
        else if(lineX_1 == m.getCols())
            winningPlayer = 2;
        else{
            lineO_1 = 0;
            lineX_1 = 0;
        }
    } //tutaj bede musial zmienic kod zeby ogarnac z dwoch stron to
    for (int i = 0; i < m.getCols(); i++) { //pionowo
        for (int j = 0; j < m.getCols(); j++) {
            if (m.getValue(i, i) == 'X')   //   sprawdz czy to dziala xd
                lineX_2++;
            else if (m.getValue(i, i) == 'O')
                lineO_2++;
            else if (m.getValue(j, j) == 'X')
                lineO_2++;
            else if (m.getValue(j, j) == 'O')
                lineO_2++;
        }
        if(lineO_2 == m.getCols())
            winningPlayer = 1;
        else if(lineX_1 == m.getCols())
            winningPlayer = 2;
        else{
            lineO_2 = 0;
            lineX_2 = 0;
        }
    }
    return winningPlayer;
}