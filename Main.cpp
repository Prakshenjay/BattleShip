#include "Game.hpp"

void printArt(string filename)
{
    filename += ".txt";
    
    fstream newfile;

    newfile.open( filename , ios::in);

    if (newfile.is_open())
    {
        string tp;
        while (getline(newfile, tp))
        {
            cout << tp << "\n";
        }
        newfile.close();
    }

    char ch;
    getchar();
}

void printInstructions()
{
    std::cout << "Welcome to the Battle Ship Game!\n";
    std::cout << "================================\n";
    std::cout << "Instructions:\n";
    std::cout << "1. You and the computer each have a game board with ships.\n";
    std::cout << "2. You'll take turns to attack the opponent's board.\n";
    std::cout << "3. Each player's board is marked with 'S' for ships, 'X' for hits,\n";
    std::cout << "   and '*' for misses.\n";
    std::cout << "4. To attack, enter coordinates (e.g., A3) and see if it's a hit or miss.\n";
    std::cout << "5. The first player to sink all of the opponent's ships wins!\n";
    std::cout << "6. Have fun and enjoy the game!\n";
    std::cout << "================================\n";
}

int main()
{
    Game game;

    printArt("TitleScreen");
    printInstructions();

    game.setup();
    game.play();

    return 0;
}
