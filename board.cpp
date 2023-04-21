#include <iostream>
#include <array>

using namespace std;

void coreLoop(char[][5]);
void boardPrinter(const char[][5]);
void boardClear(char[][5]);
void placeALetter(char[][5], char);
void boardChecker(const char[][5], char);
int convertRowCharToInt(char);
int convertColCharToInt(char);

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
    char currentPlayer = 'X';

    while (true)
    {
        boardPrinter(board);
        placeALetter(board, currentPlayer);
        // if (currentPlayer == X) is true, assign O. If false, assign X
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        if (gameOver)
        {
            break;
        }
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
        char positionRow, positionCol;
        cout << "\n\nWhere to put " << letter << "? ( column (A/B/C), row (1/2/3) )";
        cin >> positionCol >> positionRow;

        int row = convertRowCharToInt(positionRow);
        int col = convertColCharToInt(positionCol);

        if (!(array[row][col] == ' '))
        {
            cout << "ERROR, postion already filled";
            filled = true;
        }
        else
        {
            array[row][col] = letter;
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
    int filledCells = 0;
    // checks if board is filled
    for (int c = 0; c < 5; c += 2)
    {
        for (int r = 0; r < 3; r++)
        {
            if (array[c][r] != ' ')
            {
                filledCells += 1;
            }
        }
    }

    if (filledCells == 9)
    {
        cout << "\n\nThe board is filled! Tie!\n";
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
    // horizontals
    for (int i = 0; i < 3; i += 1)
    {
        if ((array[i][0] == letter) && (array[i][2] == letter) && (array[i][4] == letter))
        {
            return true;
        }
    }

    // verticals
    for (int i = 0; i < 5; i += 2)
    {
        if ((array[0][i] == letter) && (array[1][i] == letter) && (array[2][i] == letter))
        {
            return true;
        }
    }

    // diagonals
    if ((array[0][0] == letter) && (array[1][2] == letter) && (array[2][4] == letter))
    {
        return true;
    }

    if ((array[2][0] == letter) && (array[1][2] == letter) && (array[0][4] == letter))
    {
        return true;
    }

    return false;
}

int convertRowCharToInt(char rowChar)
{
    int rowInt = -1;
    switch (rowChar)
    {
    case '1':
        rowInt = 0;
        break;
    case '2':
        rowInt = 1;
        break;
    case '3':
        rowInt = 2;
        break;
    default:
        cout << "Invalid row character. Please choose 1, 2, or 3." << endl;
        break;
    }
    return rowInt;
}

int convertColCharToInt(char colChar)
{
    int colInt = -1;

    switch (colChar)
    {
    case 'A':
    case 'a':
        colInt = 0;
        break;
    case 'B':
    case 'b':
        colInt = 2;
        break;
    case 'C':
    case 'c':
        colInt = 4;
        break;
    default:
        cout << "Invalid column character. Please choose A, B, or C." << endl;
        break;
    }

    return colInt;
}