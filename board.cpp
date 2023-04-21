#include <iostream>
#include <array>

using namespace std;

void coreLoop(char[][5]);
void boardPrinter(const char[][5]);
void boardClear(char[][5]);
void placeALetter(char[][5], char);
void boardChecker(const char[][5], char);

bool winningMove(const char[][5], char);

bool gameOver = false;
const string dashes = "\n=+=+=\n";

int main()
{
    int menuNumber = 0;

    char array[3][5] = {' ', '|', ' ', '|', ' ',
                        ' ', '|', ' ', '|', ' ',
                        ' ', '|', ' ', '|', ' '};

    coreLoop(array);

    cout << "Final: \n\n";
    boardPrinter(array);
    return 0;
}

void coreLoop(char board[][5])
{
    bool xTurn = true;
    while (true)
    {
        boardPrinter(board);
        if (xTurn == true)
        {
            placeALetter(board, 'X');
            xTurn = false;
        }
        else
        {
            placeALetter(board, 'O');
            xTurn = true;
        }
        if (gameOver == true)
            break;
    }
}

void boardPrinter(const char array[][5])
{
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << array[i][j];
        }
        if (i < 2)
            cout << dashes;
    }
}

void placeALetter(char array[][5], char letter)
{
    bool filled = false;
    do
    {
        int positionY = 0, positionX = 0;
        cout << "\n\nWhere to put " << letter << "? (row (0 / 1 / 2), column (0 / 2 / 4) )";
        cin >> positionY >> positionX;

        if (!(array[positionY][positionX] == ' '))
        {
            cout << "ERROR, postion already filled";
            filled = true;
        }
        else
        {
            array[positionY][positionX] = letter;
            filled = false;
        }
    } while (filled == true);

    boardChecker(array, letter);
}

// reseets and clears the tic-tac-toe board
void boardClear(char array[][5])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (!(array[i][j] == '|'))
                array[i][j] = ' ';
        }
    }
}

// checks to see if a player has won the game
void boardChecker(const char array[][5], char letter)
{
    // checks if board is filled
    if (!(array[0][0] == ' ') && !(array[0][2] == ' ') && !(array[0][4] == ' '))
        if (!(array[1][0] == ' ') && !(array[1][2] == ' ') && !(array[1][4] == ' '))
            if (!(array[2][0] == ' ') && !(array[2][2] == ' ') && !(array[2][4] == ' '))
            {
                cout << "\n\nThe board is filled! Tie!";
                gameOver = true;
            }

    // checks if the latest move won the game

    if (winningMove(array, letter))
    {
        cout << "\n"
             << letter << " won!";
        gameOver = true;
    }
}

bool winningMove(const char array[][5], char letter)
{
    /*
    @|@|@
    =+=+=
     | |
    =+=+=
     | |
    */
    if ((array[0][0] == array[0][2]) && (array[0][2] == array[0][4]) && (array[0][4] == letter))
        return true;

    /*
     | |
    =+=+=
    @|@|@
    =+=+=
     | |
    */
    else if ((array[1][0] == array[1][2]) && (array[1][2] == array[1][4]) && (array[1][4] == letter))
        return true;

    /*
     | |
    =+=+=
     | |
    =+=+=
    @|@|@
    */
    else if ((array[2][0] == array[2][2]) && (array[2][2] == array[2][4]) && (array[2][4] == letter))
        return true;

    /*
    @| |
    =+=+=
    @| |
    =+=+=
    @| |
    */
    else if ((array[0][0] == array[1][0]) && (array[1][0] == array[2][0]) && (array[2][0] == letter))
        return true;

    /*
     |@|
    =+=+=
     |@|
    =+=+=
     |@|
    */
    else if ((array[0][2] == array[1][2]) && (array[1][2] == array[2][2]) && (array[2][2] == letter))
        return true;

    /*
     | |@
    =+=+=
     | |@
    =+=+=
     | |@
    */
    else if ((array[0][4] == array[1][4]) && (array[1][4] == array[2][4]) && (array[2][4] == letter))
        return true;

    /*
    @| |
    =+=+=
     |@|
    =+=+=
     | |@
    */
    else if ((array[0][0] == array[1][2]) && (array[1][2] == array[2][4]) && (array[2][4] == letter))
        return true;

    /*
     | |@
    =+=+=
     |@|
    =+=+=
    @| |
    */
    else if ((array[2][0] == array[1][2]) && (array[1][2] == array[0][4]) && (array[0][4] == letter))
        return true;

    return false;
}
