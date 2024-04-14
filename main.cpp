#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

class Hangman
{
// constructor, seeds random number generator and sets up rest of game
public:
    Hangman()
    {
        srand(static_cast<unsigned int>(time(nullptr)));
        currentWord = string(secretWord.length(), '_');
        attemptsLeft = MAX_ATTEMPTS;
    }
// method to start game and choose category
    void playgame()
    {
        cout << "This is hangman." << endl;
        cout << "Pick any category: 1 = cars, 2 = animals, 3 = USA States" << endl;
        int chosenCategory;
        cin >> chosenCategory;

        switch (chosenCategory)
        {
        case 1:
            secretWord = getRandomWord(cars);
            break;
        case 2:
            secretWord = getRandomWord(animals); //use cases to set categories once chosen
            break;
        case 3:
            secretWord = getRandomWord(USstates);
            break;
        default:
            cout << "Please choose 1, 2, or 3" << endl;
            return;
        }
        cout << attemptsLeft << " attempts remaining." << endl;

        // most important / basic hangman functions
        while (attemptsLeft > 0)
        {
            displayGameInfo();
            char guess;
            cout << "Letter: ";
            cin >> guess;

            if (isalpha(guess)) // ensures user input is a letter
            {
                guess = tolower(guess); // convert letter to lower case for consistency
                bool correctGuess = updateWord(guess);
                if (correctGuess)
                {
                    cout << "Correct!" << endl;
                    if (currentWord == secretWord)
                    {
                        cout << "You won! The word was: " << secretWord << endl;
                        return;
                    }
                }
                else
                {
                    cout << "Incorrect." << endl;
                    attemptsLeft--;
                }
            }
            else
            {
                cout << "Enter a valid letter please." << endl;
            }
        }
        cout << "No more attempts. The secret word was: " << secretWord << endl;
    }

private:
    const int MAX_ATTEMPTS = 5;
    vector<string> cars = {"corvette", "ford", "audi", "bmw", "mazda", "buick", "chrysler", "chevrolet", "kia", "jeep", "ferrari", "tesla"};
    vector<string> animals = {"elephant", "tiger", "giraffe", "penguin", "koala", "zebra", "kangaroo", "lion", "cheetah", "panda", "gorilla", "hippopotamus"};
    vector<string> USstates = {"California", "Texas", "Florida", "New York", "Illinois", "Pennsylvania", "Ohio", "Georgia", "North Carolina", "Michigan", "New Jersey", "Virginia"};
    string secretWord;
    string currentWord;
    string guessedLetters;
    int attemptsLeft;
    // makes lists for the game to choose from above then works with the list below
    string getRandomWord(const vector<string> &wordList)
    {
        int randomIndex = rand() % wordList.size();
        return wordList[randomIndex];
    }
    // updates the current word based on user input
    bool updateWord(char guess)
    {
        bool correctGuess = false;
        guessedLetters += guess;
        for (size_t i = 0; i < secretWord.length(); ++i)
        {
            if (secretWord[i] == guess)
            {
                currentWord[i] = guess;
                correctGuess = true;
            }
        }
        return correctGuess;
    }
    // most of what the player sees, added ascii art for hangman progression
 void displayGameInfo()
    {
        switch (attemptsLeft)
        {
        case 6:
            cout << "    _______" << endl;
            cout << "   |/      |" << endl;
            cout << "   |" << endl;
            cout << "   |" << endl;
            cout << "   |" << endl;
            cout << "   |" << endl;
            cout << "___|___" << endl;
            break;
        case 5:
            cout << "    _______" << endl;
            cout << "   |/      |" << endl;
            cout << "   |      (_)" << endl;
            cout << "   |" << endl;
            cout << "   |" << endl;
            cout << "   |" << endl;
            cout << "___|___" << endl;
            break;
        case 4:
            cout << "    _______" << endl;
            cout << "   |/      |" << endl;
            cout << "   |      (_)" << endl;
            cout << "   |      \\|" << endl;
            cout << "   |" << endl;
            cout << "   |" << endl;
            cout << "___|___" << endl;
            break;
        case 3:
            cout << "    _______" << endl;
            cout << "   |/      |" << endl;
            cout << "   |      (_)" << endl;
            cout << "   |      \\|/" << endl;
            cout << "   |" << endl;
            cout << "   |" << endl;
            cout << "___|___" << endl;
            break;
        case 2:
            cout << "    _______" << endl;
            cout << "   |/      |" << endl;
            cout << "   |      (_)" << endl;
            cout << "   |      \\|/" << endl;
            cout << "   |       |" << endl;
            cout << "   |" << endl;
            cout << "___|___" << endl;
            break;
        case 1:
            cout << "    _______" << endl;
            cout << "   |/      |" << endl;
            cout << "   |      (_)" << endl;
            cout << "   |      \\|/" << endl;
            cout << "   |       |" << endl;
            cout << "   |      /" << endl;
            cout << "___|___" << endl;
            break;
        case 0:
            cout << "    _______" << endl;
            cout << "   |/      |" << endl;
            cout << "   |      (_)" << endl;
            cout << "   |      \\|/" << endl;
            cout << "   |       |" << endl;
            cout << "   |      / \\" << endl;
            cout << "___|___" << endl;
            break;
        }
        cout << "Guessed Letters: " << guessedLetters << endl;
        cout << "Word: " << currentWord << endl;
        cout << "Attempts: " << attemptsLeft << endl;
    }
};

int main()
{
    Hangman game;
    game.playgame();
    return 0;
}
