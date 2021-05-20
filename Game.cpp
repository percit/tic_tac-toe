#include "Game.h"
#include <climits>
void Game::addMove( int r,  int c, char player) {
    //char sign;
    if(m(r,c) == '-') {
        m(r, c) = player;
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
int Game::getAmountOFMoves(){
    int amountOfMoves = 0;
    for(int i = 0; i < m.getCols(); ++i){
        for(int j = 0; j < m.getRows(); ++j){
            if(m(i, j) == '-') ++amountOfMoves;
        }
    }
    return amountOfMoves;
}
void Game::resetBoard() {
    m.clear();
}
void Game::removeMove( int i,  int j)
{
    m(i,j) = '-';
}

int Game::Winner() {

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
            winningPlayer = 10;
        else if(lineO_1h == m.getCols())
            winningPlayer = -10;
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
            winningPlayer = 10;
        }
        else if(lineO_1v == m.getRows()) {
            winningPlayer = -10;
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
            winningPlayer = 10;
        else if(lineO_2 == m.getCols())
            winningPlayer = -10;
        else{
            lineO_2 = 0;
            lineX_2 = 0;
        }
    }

    return winningPlayer;
}

int minimax(Game & board,  int depth, bool isMax, int alpha, int beta) //X to my, pamietaj
{
    if(depth == 7)
        return 0;

    int score = board.Winner();
    if (score == 10 || score == -10)    //if game is already won
        return score;

    if (board.getAmountOFMoves() == 0)
        return 0; //draw

    //jesli jest ruch gracza
    if (isMax)
    {
        int best = INT_MIN/10;
        for (int i = 0; i < board.getDimension(); i++)
        {
            for (int j = 0; j < board.getDimension(); j++)
            {
                if (board.isMoveAllowed(i, j))
                {
                    board.addMove(i, j, 'X');
                    best = std::max(best, minimax(board, depth + 1, !isMax, alpha, beta));

                    //remove if not optimal
                    board.removeMove(i, j);

                    // alpha beta prunning
                    alpha = std::max(alpha, best);
                    if(beta <= alpha)
                        break;
                }
            }
        }
        return best;
    }

    else //AI
    {
        int best = INT_MAX/10;
        for (int i = 0; i < board.getDimension(); i++)
        {
            for (int j = 0; j < board.getDimension(); j++)
            {
                if (board.isMoveAllowed(i, j))
                {
                    board.addMove(i, j, 'O');
                    best = std::min(best, minimax(board, depth + 1, !isMax, alpha, beta));
                    board.removeMove(i, j);
                    beta = std::min(beta, best);
                    if(beta <= alpha)
                        break;
                }
            }
        }
        return best;
    }
}

std::pair<int, int> findBestMove(Game& board)
{
    int bestVal = INT_MAX/10;
    std::pair<int, int> bestMove;
    bestMove.first = -1;
    bestMove.second = -1;
    //we check all empty places and get minmax values for each to find optimal move
    for (int i = 0; i < board.getDimension(); i++)
    {
        for (int j = 0; j < board.getDimension(); j++)
        {
            if (board.isMoveAllowed(i, j))
            {
                board.addMove(i, j, 'O');
                //getting the value for that place
                int moveVal = minimax(board,0, true, INT_MIN/10,INT_MAX/10);
                //remove move(id adds it only for checking minmax
                board.removeMove(i, j);
                //if this place is most optimal, then choose it
                if (moveVal < bestVal)
                {
                    bestMove.first = i;
                    bestMove.second = j;
                    bestVal = moveVal;
                }
            }
        }
    }
    return bestMove;
}
void playerMove(Game& board)
{
    int x = 0;
    int y = 0;
    std::cout << "Where to put the sign?  " << std::endl;
    std::cin >> x >> y ;
    if ((x <= board.getDimension() - 1 && x >= 0) && (y <= board.getDimension() - 1 && y >= 0))
    {
        if (board.isMoveAllowed(x, y))
            board.addMove(x, y, 'X');
        else
        {
            std::cout << " Place taken" << std::endl;
            playerMove(board);
        }
    }
    else
    {
        std::cout << "Out of bounds" << std::endl;
        playerMove(board);
    }

}
void aiMove(Game& board)
{
    //std::pair<int, int> bestMove = findBestMove(board);
    auto bestMove = findBestMove(board);
    int x = bestMove.first;
    int y = bestMove.second;
    if(board.isMoveAllowed(x, y))
        board.addMove(x, y, 'O');
}
void Management(Game& board)
{
    int victory = 0;
    while(board.getAmountOFMoves() > 0)
    {
        std::cout << "Your move: " << std::endl;

        if(board.getAmountOFMoves() > 0) //if any moves left
            playerMove(board);
        victory = board.Winner();
        if(victory == 10)
        {
            std::cout << "You won" << std::endl;
            break;
        }

        std::cout << board;
        std::cout << "----------" << std::endl;
        std::cout << "Ai move: " << std::endl;

        if(board.getAmountOFMoves() > 0)
            aiMove(board);

        std::cout << "----------" << std::endl;
        std::cout << board;

        victory = board.Winner();
        if(victory == -10)
        {
            std::cout << "You lost" << std::endl;
            break;
        }
    }
    if(victory == 0) //draw
    {
        std::cout << "Draw" << std::endl;;
    }
}



/*
std::pair< int, std::pair<int, int> > Game::MinMax(Game & gameBoard, Player player1, Player player2, bool minOrMax, Game condition, int depth)
{
    int tableOfMaxDepth[11] = {0, 0, 0, 10, 5, 4, 3, 3, 3, 3, 2};
    int MinMaxValue = -2;
    std::pair<int,int> move;
    unsigned int boardSize = gameBoard.getDimension();
    Matrix & fields = gameBoard.returnMatrix();
    int winner;
    int player1ID = player1.getID();
    int player2ID = player2.getID();
    int result = condition.Winner();
    //    int result = condition.Winner(gameBoard, player1, player2);
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

    for(int i = 0; i < boardSize; i++)
    {
        for(int j = 0; j < boardSize; j++)
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
 */
/*
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
