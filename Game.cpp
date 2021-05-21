#include "Game.h"
#include <climits>
void Game::addMove( int r,  int c, char player) {
    if(m(r,c) == '-') {
        m(r, c) = player;
    }
}
bool Game::isMoveAllowed( int r,  int c) {
    if (m(r, c) != '-' ) {
        return false;
    }
    else{
        return true;
    }
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
    int lineO_h = 0, lineX_h = 0; //for horizontal - will be needed for multithreading
    int lineO_v = 0, lineX_v = 0; //for vertical
    int lineO_d1 = 0, lineX_d1 = 0, lineO_d2 = 0, lineX_d2 = 0;//for diagonal

    for (int i = 0; i < m.getRows(); i++) { //poziomo - horizontal
        for (int j = 0; j < m.getCols(); j++) {
            if (m(i, j) == 'X')   //   longest substring/binary number anything for XXX0X, so it will be 1 for X and 1 for 0
                lineX_h++;
            else if (m(i, j) == 'O')
                lineO_h++;
        }
        if(lineX_h == m.getCols()) { //DODAJ ARGUMENT Z ILOSCIA ZNAKOW DO WYGRANEJ
            winningPlayer = 10;
            return winningPlayer;
        }
        lineX_h = 0;
        if(lineO_h == m.getCols()){
            winningPlayer = -10;
            return winningPlayer;
        }
        lineO_h = 0;
    }

    for (int i = 0; i < m.getRows(); i++) { //pionowo - vertical
        for (int j = 0; j < m.getCols(); j++) {
            if (m(j, i) == 'X')   //
                lineX_v++;
            else if (m(j, i) == 'O')
                lineO_v++;
        }
        if(lineX_v == m.getRows()) {
            winningPlayer = 10;
            return winningPlayer;
        }
        lineX_v = 0;
        if(lineO_v == m.getRows()) {
            winningPlayer = -10;
            return winningPlayer;
        }
        lineO_v = 0;

    }

    for (int i = 0; i < m.getCols(); i++) { //na ukos
        if (m(i, i) == 'X')
            lineX_d1++;
        else if (m(i, i) == 'O')
            lineO_d1++;
    }
    for (int j = 0; j < m.getCols(); ++j) { //na odwrotny ukos
        if (m(j, m.getCols()-1-j) == 'X')
            lineX_d2++;
        else if (m(j, m.getCols()-1-j) == 'O')
            lineO_d2++;
    }
        if(lineX_d1 == m.getCols() || lineX_d2 == m.getCols()){
            winningPlayer = 10;
            return winningPlayer;
        }
        lineX_d1 = 0;
        lineX_d2 = 0;
        if(lineO_d1 == m.getCols() || lineO_d2 == m.getCols()){
            winningPlayer = -10;
            return winningPlayer;
        }
        lineO_d1 = 0;
        lineO_d2 = 0;


    return 0;
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


    if (isMax)//player's turn
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


