#ifndef TICTAC_HPP
#define TICTAC_HPP

#include <iostream>

using namespace std;

class Board {

    private:

    char matrix[3][3];
    char activePlayer;
    char winner;

    public:

    Board();
    void drawBoard();
    void updateBoard();
    char checkBoard ();
    void declareWinner ();
};

#endif // TICTAC_HPP
