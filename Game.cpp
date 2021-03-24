#include "Game.h"

void Game::addMove(unsigned int r, unsigned int c, Player player) {
    //pomysl czy trza sprawdzac tu wymiary, czy w przeciazeniu ()
    char sign;
    if(player.playerID == 1){
        sign = 'X';
    }
    else sign = 'O';
    m.setValue(r, c, sign);

}
bool Game::isMoveAllowed(unsigned int r, unsigned int c) {
    if(getMoves() > 0) {
        if ((m.getValue(r, c) == 'X') || (m.getValue(r, c) == 'O'))
            return false;
    }
    int temp = getMoves() - 1; // we change amout of moves
    setMoves(temp);
    return true;
}
void Game::resetBoard() {
    m.fill();//a kto mi tak pisac zabroni XD
}
void Game::removeMove(unsigned int i, unsigned int j)
{
    m.setValue(i,j, 0);
}
int Game::Winner(Game &game1, Player player1, Player player2) { //  EW SPOJRZ NA WINNING CONDITION EMILII, TA FUNKCJA MA ZWRACAC 10 JESLI WYGRAM, -10 JESLI PRZEGRAM I 0 JESLI REMIS

    int winningPlayer = 0;
    int lineO_1 = 0, lineX_1 = 0; //for horizontal and vertical
    int lineO_2 = 0, lineX_2 = 0;//for diagonal
    for (int i = 0; i < m.getCols(); i++) { //poziomo
        for (int j = 0; j < m.getCols(); j++) {
            if (m.getValue(i, j) == 'X')   //   JAK BEDE ZMIENIAC NA TE Z ODPOWIEDNIA DLUGOSCIA TO TU BEDE ZMIENIAL KOD
                lineX_1++;
            else if (m.getValue(i, j) == 'O')
                lineO_1++;
        }
        if(lineO_1 == m.getCols()) //DODAJ ARGUMENT Z ILOSCIA ZNAKOW DO WYGRANEJ
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
std::pair< int, std::pair<int, int> > Game::MinMax(Game & gameBoard, Player player1, Player player2, bool minOrMax, Game condition, int depth)
{
    int tableOfMaxDepth[11] = {0, 0, 0, 10, 5, 4, 3, 3, 3, 3, 2};
    int MinMaxValue = -2;
    std::pair<int,int> move;
    unsigned int boardSize = gameBoard.getCols();
    Matrix & fields = gameBoard.returnMatrix();
    int winner;
    int player1ID = player1.playerID;
    int player2ID = player2.playerID;
    int result = condition.Winner(gameBoard, player1, player2);
    std::pair <int, std::pair<int, int> > nextRecursion;
    if(result == 0)
    {
        winner = 0;
    }
    else
    {
        if(result == player1ID)
        {
            winner = 1;
        }
        else
        {
            if(result == player2ID) winner = -1;
            else winner = 2;
        }
    }

    if(winner != 2)
        return {winner, {-1, -1} };

    if(boardSize <= 10)
    {
        if(depth == tableOfMaxDepth[boardSize])
            return {0, {-1, -1}};
    }
    else
    {
        if(depth == 2)
            return {0, {-1, -1}};

    }

    for(unsigned int i = 0; i < boardSize; i++)
    {
        for(unsigned int j = 0; j < boardSize; j++)
        {
            if(fields(i,j) == 0)
            {
                if(minOrMax)			//maximizing
                {
                    gameBoard.addMove(i, j, player1);
                    nextRecursion = MinMax(gameBoard, player1, player2, false, condition, depth+1);
                    if(MinMaxValue == -2 or nextRecursion.first > MinMaxValue)
                    {
                        MinMaxValue = nextRecursion.first;
                        move = {i,j};
                    }
                }
                else				//minimizing
                {
                    gameBoard.addMove(i, j, player2);
                    nextRecursion = MinMax(gameBoard, player1, player2, true, condition, depth+1);
                    if(MinMaxValue == -2 or nextRecursion.first < MinMaxValue)
                    {
                        MinMaxValue = nextRecursion.first;
                        move = {i,j};
                    }

                }
                gameBoard.removeMove(i,j);
            }
        }
    }

    return {MinMaxValue, move};
}
void Game::Management()
{
    unsigned int winningNumber, sizeOfBoard;
    char AISign, userSign;
    std::pair<int, std::pair<int, int> > resultOfMinMax;
    unsigned int row, column, counter = 0;

    std::cout << "Size of the board: ";
    std::cin >> sizeOfBoard;
    while(sizeOfBoard < 3 || sizeOfBoard > 50)
    {
        std::cout << "Incorrect value. Type again: ";
        std::cin >> sizeOfBoard;
    }

    Game board = Game(sizeOfBoard);

    std::cout << "Number of elements in a row to win: ";
    std::cin >> winningNumber;
    while(winningNumber <= 1 || winningNumber > sizeOfBoard)
    {
        std::cout << "Incorrect value. Type again: ";
        std::cin >> winningNumber;
    }

    Game win = Game(winningNumber);

    std::cout << "Type your sign: ";
    std::cin >> userSign;
    Player user = Player(1, userSign);

    std::cout << "Type the sign of the AI: ";
    std::cin >> AISign;
    Player AI = Player(2, AISign);

    std::cout << "Who should start: you (type: 1) or AI (type 2)? ";
    std::cin >> counter;
    while(counter != 1 and counter != 2)
    {
        std::cout << "Incorrect value. Type again: ";
        std::cin >> counter;
    }

    int if_victory = win.Winner(board, user, AI);
    std::cout << "Type your move as: row column" << std::endl;
    board.displayBoard(user, AI);

    while(if_victory == -1)
    {
        if(counter % 2 == 1)
        {
            std::cout << "Your turn. Make your move: ";
            std::cin >> row >> column;
            while(board.isMoveAllowed(row - 1, column - 1) != true)
            {
                std::cout << "You cannot make that move, type again: ";
                std::cin >> row >> column;
            }
            board.addMove(row - 1, column - 1, user);
        }
        else
        {
            std::cout << "AI's turn" <<std::endl;
            resultOfMinMax = MinMax(board, user, AI, false, win, 0);
            board.addMove(resultOfMinMax.second.first, resultOfMinMax.second.second, AI);


        }

        board.displayBoard(user, AI);
        counter++;
        if_victory = win.Winner(board, user, AI);
    }

    if(if_victory == user.playerID)
    {
        std::cout << "YOU WON! :)"<<std::endl;
    }
    else
    {
        if (if_victory == AI.playerID) std::cout << "AI WON! :(" << std::endl;
        else std::cout << "DRAW" <<std::endl;
    }
}
