#ifndef BOARD_H
#define BOARD_H

void coreLoop(char[][5]);
void boardPrinter(const char[][5]);
void boardClear(char (&)[][5]);
void placeALetter(char[][5], char);
void boardChecker(const char[][5], char);
int convertRowCharToInt(char);
int convertColCharToInt(char);
void undoMove(char (&)[][5]);

bool winningMove(const char[][5], char);

#endif