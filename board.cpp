#include <iostream>
#include <array>
#include <time.h>
#include "computerTurn.h"

using namespace std;

void boardPrinter(const char[][5]);
void boardClear(char[][5]);
void placeALetter(char[][5], char);
void boardChecker(const char[][5]);

bool boardFilled = false;
const string dashes = "\n=+=+=\n";

int main()
{
    srand(time(0));
    int menuNumber = 0;

    char array[3][5] = {' ', '|', ' ', '|', ' ',
                        ' ', '|', ' ', '|', ' ',
                        ' ', '|', ' ', '|', ' '};
    do
    {
        boardPrinter(array);
        placeALetter(array, 'X');
        boardPrinter(array);
        placeALetter(array, 'O');

    } while (boardFilled == false);
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

void boardChecker(const char array[][5])
{
    for (int j = 0; j < 5; j++)
    {
        if (!(array[0][j] == ' ') && !(array[1][j] == ' ') && !(array[2][j] == ' '))
        {
            
        }
    }
}