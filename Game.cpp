#include "Game.h"

void Game::addMove( int r,  int c, Player player) {
    char sign;
    if(m(r,c) == '-') {
        if (player.getID() == 1) {
            sign = 'X';
            m(r, c) = sign;
        } else if (player.getID() == 2) {
            sign = 'O';
            m(r, c) = sign;
        }
    }
}
bool Game::isMoveAllowed( int r,  int c) { //w przyszlosci popraw
    if (m(r, c) != '-' ) {
        return false;
    }
    else{
        return true;
    }

    /*
    if(m.getMoves() > 0) {
        if ((m(r, c) == 'X') || (m(r, c) == 'O'))
            return false;
    }
    int temp = m.getMoves() - 1; // we change amout of moves
    m.setMoves(temp);
    return true;
     */
}
void Game::resetBoard() {
    m.clear();
}
void Game::removeMove( int i,  int j)
{
    m(i,j) = '-';
}

int Game::Winner() { //   TA FUNKCJA MA ZWRACAC 10 JESLI WYGRAM, -10 JESLI PRZEGRAM I 0 JESLI REMIS

    int winningPlayer = 0;
    int lineO_1h = 0, lineX_1h = 0; //for horizontal - will be needed for multithreading
    int lineO_1v = 0, lineX_1v = 0; //for vertical
    int lineO_2 = 0, lineX_2 = 0;//for diagonal

    for (int i = 0; i < m.getRows(); i++) { //poziomo - horizontal
        for (int j = 0; j < m.getCols(); j++) {
            if (m(i, j) == 'X')   //   longest substring/binary number anything for XXX0X, so it will be 1 for X and 1 for 0
                lineX_1h++;
            else if (m(i, j) == 'O')
                lineO_1h++;
        }
        if(lineX_1h == m.getCols()) //DODAJ ARGUMENT Z ILOSCIA ZNAKOW DO WYGRANEJ
            winningPlayer = 1;
        else if(lineO_1h == m.getCols())
            winningPlayer = 2;
        else{
            lineO_1h = 0;
            lineX_1h = 0;
        }
    }


    for (int i = 0; i < m.getRows(); i++) { //pionowo - vertical
        for (int j = 0; j < m.getCols(); j++) {
            if (m(j, i) == 'X')   //
                lineX_1v++;
            else if (m(j, i) == 'O')
                lineO_1v++;
        }
        if(lineX_1v == m.getRows()) {
            winningPlayer = 1;
        }
        else if(lineO_1v == m.getRows()) {
            winningPlayer = 2;
        }
        else{
            lineO_1v = 0;
            lineX_1v = 0;
        }
    }

    for (int i = 0; i < m.getCols(); i++) { //na ukos
        for (int j = 0; j < m.getCols(); j++) {
            if (m(i, i) == 'X')   //
                lineX_2++;
            else if (m(i, i) == 'O')
                lineO_2++;
            else if (m(j, j) == 'X')
                lineO_2++;
            else if (m(j, j) == 'O')
                lineO_2++;
        }
        if(lineX_2 == m.getCols())
            winningPlayer = 1;
        else if(lineO_2 == m.getCols())
            winningPlayer = 2;
        else{
            lineO_2 = 0;
            lineX_2 = 0;
        }
    }

    return winningPlayer;
}




/*
 for(int i = 0; i < 3; ++i){ poziomo
 for(int j = 0; i < 3; ++j){ poziomo
if(board[i, j] == board[i, j] == board[i, j]
 winner = board[i, 0]

 for(int i = 0; i < 3; ++i){ pionowo
 for(int j = 0; i < 3; ++j){
if(board[j, i] == board[j, i] == board[j, i]
 winner = board[0, i]

 diagonal
 if(board[0,0] == board[1,1] == board[2,2]){
 winner = board[0,0]
  if(board[2,0] == board[1,1] == board[0,2]){
 winner = board[2,0]
*/









/*
std::pair< int, std::pair<int, int> > Game::MinMax(Game & gameBoard, Player player1, Player player2, bool minOrMax, Game condition, int depth)
{
    int tableOfMaxDepth[11] = {0, 0, 0, 10, 5, 4, 3, 3, 3, 3, 2};
    int MinMaxValue = -2;
    std::pair<int,int> move;
    unsigned int boardSize = gameBoard.getCols();
    Matrix & fields = gameBoard.returnMatrix();
    int winner;
    int player1ID = player1.getID();
    int player2ID = player2.getID();
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

    int if_victory = win.Winner(board, AI);
    std::cout << "Type your move as: row column" << std::endl;
   // board.displayBoard(user, AI); //NAPRAW TO
   std::cout << board;

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

       // board.displayBoard(user, AI); //NAPRAW TO
       std::cout << board;
        counter++;
        if_victory = win.Winner(board, AI);
    }

    if(if_victory == user.getID())
    {
        std::cout << "YOU WON! :)"<<std::endl;
    }
    else
    {
        if (if_victory == AI.getID()) std::cout << "AI WON! :(" << std::endl;
        else std::cout << "DRAW" <<std::endl;
    }
}
*/
