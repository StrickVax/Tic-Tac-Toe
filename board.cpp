#include <iostream>
#include <array>
using namespace std;

void boardPrinter(const char[][5]);
void boardClear(char[][5]);
void controlX(char[][5]);
void controlO(char[][5]);

bool boardFilled = false;
const string dashes = "\n=====\n";

int main()
{

    char array[3][5] = {' ', '|', ' ', '|', ' ',
                        ' ', '|', ' ', '|', ' ',
                        ' ', '|', ' ', '|', ' '};
    while (boardFilled == false)
    {
        boardPrinter(array);
        controlX(array);
        boardPrinter(array);
        controlO(array);
        boardClear(array);
    }
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

void controlX(char array[][5])
{
    bool filled = false;
    do
    {
        int positionY = 0, positionX = 0;
        cout << "\n\nWhere to put X? (row (0 / 1 / 2), column (0 / 2 / 4) )";
        cin >> positionY >> positionX;

        if (!(array[positionY][positionX] == ' '))
        {
            cout << "ERROR, postion already filled";
            filled = true;
        }
        else
        {
            array[positionY][positionX] = 'X';
            filled = false;
        }
    } while (filled == true);
}

void controlO(char array[][5])
{
    bool filled = false;
    do
    {
        int positionY = 0, positionX = 0;
        cout << "\n\nWhere to put O? (row (0 / 1 / 2), column (0 / 2 / 4) )";
        cin >> positionY >> positionX;

        if (!(array[positionY][positionX] == ' '))
        {
            cout << "ERROR, postion already filled";
            filled = true;
        }
        else
        {
            array[positionY][positionX] = 'O';
            filled = false;
        }
    } while (filled == true);
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