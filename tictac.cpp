#include "tictac.hpp"


Board::Board()
{                          //Default constructor

      int counter = 1;

      for (int i=0; i<3; i++){
          for (int j=0; j<3; j++){
              matrix [i][j] = ' ';
              counter++;
          }
      }

      activePlayer = 'O';
      winner = ' ';
}


void Board::drawBoard()        //Draws the board in console
{
    int counter=0;

       cout <<"    BOARD" <<endl;
       cout <<endl;

       for(int i=0; i < 3 ; i++)
       {
           for(int j=0; j < 3; j++)
           {
           cout << "|" << matrix[i][j] <<"|";               //<< "\t";
           counter ++;

            if (counter == 3)
            {
               cout <<"\n";
               counter = 0;
            }
          }
       }

   cout <<endl;
}

void Board::updateBoard()       //Receives Coordinates
{
    int counter = 0;

    while (counter < 9)
    {
    int pos1,pos2;

    cout << "           Active Player Is: '" << activePlayer << "'" << endl;
    cout << "Enter The Coordinates For The Next Movement" << endl;
    cin >> pos1 >> pos2;
    cout << endl;

    if ((pos1 >= 0 && pos1 <=2) &&  (pos2 >= 0 && pos2 <=2))
    {
        if (matrix [pos1][pos2] == ' ')
        {

            if (activePlayer == 'O')
            {
            matrix [pos1][pos2] = 'O';
            activePlayer = 'X';
            }

            else if (activePlayer == 'X')
            {
            matrix [pos1][pos2] = 'X';
            activePlayer = 'O';
            }

           if (counter >= 4)
            {
                winner = checkBoard();

                if (winner != ' ')
                {

                    counter = 9;
                }
                else if (winner == ' ' && counter == 8)
                {
                    winner = 'E';

                    counter = 9;
                }
                else
                {
                    continue;
                }
            }

        //drawBoard();
        counter++;
        }

        else
        {
        cout << "This Position Is Already Marked" << endl;
        cout << "    Check Another Position" << endl;
        cout << endl;
        cout << endl;
        }
    }
    else
    {
    cout << "      This Coordinates Are Incorrect" << endl;
    cout << "Enter A Valid Coordinates Between 0 And 2" << endl;
    cout << endl;
    cout << endl;
    }
    drawBoard();
  }
}

char Board::checkBoard ()           //check identical elements
{
    int conO = 0;
    int conX = 0;

    int conzO = 0;
    int conzX = 0;

    int row = 0;
    int contX = 0;
    int contO = 0;

    int colum = 0;
    int contyX = 0;
    int contyO = 0;

   //check in cross

    for (int row=0; row<3; row++)
     {
    for (int col=3; col>0; --col)
     {
       if (matrix [row][col-1] == 'X')
       {
           conX++;
       }

       else if (matrix [row][col-1] == 'O')
       {
           conO++;
       }
     }
     }

    if (conO == 3)
        winner = 'O';

    else if (conX == 3)
        winner = 'X';



    //check in cross

    for (int row=0; row<3; row++)
    {
    for (int col=0; col<3; col++)
    {
       if (matrix [row][col] == 'X')
       {
           conzX++;
       }

       else if (matrix [row][col] == 'O')
       {
           conzO++;
       }
    }
    }

    if (conzO == 3)
        winner = 'O';

    else if (conzX == 3)
        winner = 'X';

 //check in X

  while (row < 3)
  {
  for (int col=0; col<3; col++)
  {
    if (matrix [row][col] == 'X')
    {
        contX++;
    }

    else if (matrix [row][col] == 'O')
    {
        contO++;
    }
  }

 if (contO == 3)
     winner = 'O';

 else if (contX == 3)
     winner = 'X';

 else if (contO != 3 && contX != 3)
 {
     contO = 0;
     contX = 0;
     row++;
 }
 }

 //check in Y

 while (colum < 3)
 {
 for (int fil=0; fil<3; fil++)
 {
    if (matrix [fil][colum] == 'X')
    {
        contyX++;
    }

    else if (matrix [fil][colum] == 'O')
    {
        contyO++;
    }
 }

 if (contyO == 3)
     winner = 'O';

 else if (contyX == 3)
     winner = 'X';

 else if (contyO != 3 && contyX != 3)
 {
     contyO = 0;
     contyX = 0;
     colum++;
 }
 }

return  winner;
}

void Board::declareWinner ()
{
    if (winner == 'E')
    {
        cout << "No Winner, TIE Between Two Players" << endl;
        cout << endl;
        drawBoard();
    }
    else if (winner == 'X' || winner == 'O')
    {
        cout << "******WINNER******" << endl;
        cout << endl;
        cout << "The Winner Is: " << winner << endl;
        cout << endl;
        drawBoard();
        cout << endl;
        cout << endl;
    }

}
