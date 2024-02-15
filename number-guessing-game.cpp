#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    srand(time(0)); // seed the random number generator

    int randomNumber = rand() % 100 + 1; // generate a random number between 1 and 100
    int userGuess;
    int attempts = 0;

    cout << "Welcome to the number guessing game! I have generated a random number between 1 and 100. Try to guess it!" << endl;

    do {
        cout << "Enter your guess: ";
        cin >> userGuess;
        attempts++;

        if (userGuess < randomNumber) {
            cout << "Too low! Try again." << endl;
        } else if (userGuess > randomNumber) {
            cout << "Too high! Try again." << endl;
        }

    } while (userGuess != randomNumber);

    cout << "Congratulations! You found the number in " << attempts << " attempts." << endl;

    return 0;
}
