#include "tictac.hpp"

int main()
{

    cout << "TIC-TAC-TOE GAME" << endl;
    cout << endl;
    cout << endl;
    cout << "Player 1 Is: 'O'" << endl;
    cout << "player 2 Is: 'X'" << endl;
    cout << endl;
    cout << endl;


    Board Triki;

    Triki.drawBoard();
    Triki.updateBoard();
    Triki.declareWinner();

    return 0;
}

