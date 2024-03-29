#include <iostream>
#include <string>
#include <vector>
#include "board.h"

bool gameOver = false;
const std::string dashes = "\n=+=+=\n";

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
    std::cout << std::endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            std::cout << array[i][j];
        }
        if (i < 2)
            std::cout << dashes;
    }
}

void placeALetter(char array[][5], char letter)
{
    bool filled = false;
    do
    {
        char positionRow, positionCol;
        std::cout << "\n\nWhere to put " << letter << "? ( column (A/B/C), row (1/2/3) )";
        std::cin >> positionCol >> positionRow;

        int row = convertRowCharToInt(positionRow);
        int col = convertColCharToInt(positionCol);

        if (!(array[row][col] == ' '))
        {
            std::cout << "ERROR, postion already filled";
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
        std::cout << "\n\nThe board is filled! Tie!\n";
        gameOver = true;
    }

    // checks if the latest move won the game

    if (winningMove(array, letter))
    {
        std::cout << "\n"
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
        std::cout << "Invalid row character. Please choose 1, 2, or 3." << std::endl;
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
        std::cout << "Invalid column character. Please choose A, B, or C." << std::endl;
        break;
    }

    return colInt;
}

void undoMove(char (&array)[][5])
{
}
