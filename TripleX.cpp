#include <iostream>
#include <ctime>
void PrintIntroduction(int Difficulty, int HealthBar) {

    std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty;
    std::cout << "\nEnter the code to continue...DO NOT MESS UP!\n\n";
    std::cout << "\nRemaining Health: " << HealthBar;

}

bool PlayGame(int Difficulty, int HealthBar) {

    PrintIntroduction(Difficulty, HealthBar);

    // Declear 3 number code
    const int CodeA = rand() % Difficulty + Difficulty; // setting values based on difficulty level
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << std::endl;
    std::cout << "+ There are 3 numbers in the code";
    std::cout << "\n+ The codes add-up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to give: " << CodeProduct << std::endl;

    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if player guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct) {
        std::cout << "You win!\n";
        return true;
    }
    else {
        std::cout << "Uh oh! WRONG GUESS!";
        std::cout << "\nYou get tazed!";
        return false;
    }
}

int main() {

    srand(time(NULL)); // create new random sequence based on time of day

    int HealthBar = 100;
    int Difficulty = 1;
    int const MaxDifficulty = 10;

    while (Difficulty <= MaxDifficulty) {
        bool Complete = PlayGame(Difficulty, HealthBar);
        std::cin.clear(); // clears any errors
        std::cin.ignore(); // Discards the buffer

        if (Complete) {
            std::cout << "\nCONGRATS! ON TO THE NEXT LEVEL";
            ++Difficulty;
        }
        if (HealthBar == 0) {
            break;
        }
        else {
            std::cout << "\nOUCH";
            HealthBar = HealthBar - 50;
        }

        
    }
    std::cout << "\n*** Great work! you got all the files ***\n";
    return 0;
}