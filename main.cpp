#include "board.cpp"

int main()
{
    int menuNumber = 0;

    char array[3][5] = {' ', '|', ' ', '|', ' ',
                        ' ', '|', ' ', '|', ' ',
                        ' ', '|', ' ', '|', ' '};

    coreLoop(array);

    std::cout << "Final: \n\n";
    boardPrinter(array);
    return 0;
}
