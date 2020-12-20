#include <iostream>
#include <array>

using namespace std;

void boardPrinter(const char[][5]);
void boardClear(char[][5]);
void placeALetter(char[][5], char);
void boardChecker(const char[][5]);

bool boardFilled = false;
const string dashes = "\n=+=+=\n";

int main()
{
    int menuNumber = 0;

    char array[3][5] = {' ', '|', ' ', '|', ' ',
                        ' ', '|', ' ', '|', ' ',
                        ' ', '|', ' ', '|', ' '};

    for (int i = 0;; i++)
    {
        boardPrinter(array);
        placeALetter(array, 'X');
        if (boardFilled == true)
            break;

        boardPrinter(array);
        placeALetter(array, 'O');
        if (boardFilled == true)
            break;
    }

    cout << "Final: \n\n";
    boardPrinter(array);
    return 0;
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

    boardChecker(array);
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
void boardChecker(const char array[][5])
{
    if (!(array[0][0] == ' ') && !(array[0][2] == ' ') && !(array[0][4] == ' '))
        if (!(array[1][0] == ' ') && !(array[1][2] == ' ') && !(array[1][4] == ' '))
            if (!(array[2][0] == ' ') && !(array[2][2] == ' ') && !(array[2][4] == ' '))
            {
                cout << "\n\nThe board is filled! Tie!";
                boardFilled = true;
            }
}
