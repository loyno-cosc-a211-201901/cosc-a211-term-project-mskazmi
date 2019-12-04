#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <string>

const int MAXIMUMTRIES = 9;  // Maximum tries allowed is 9
int determineCorrectLetter(char, string, string&);  // Function to determine whether the guessed letter is correct or not

int main(){
    char guess;  // Variable to store the guessed letter
    int wrongCounter = 0;  // Count each wrong guess
    string wordChosen;  // Store the word that was chosen from the word bank
    string wordBank[] = {
        "reward", "orange", "bracelet", "duvet", "swimsuit",
         "texture", "brainstorm", "dove", "cupid", "blowfish",
        "ape", "wallaby", "canary", "cinderella", "paddington",
        "ratatouille", "firemen", "present", "letter", "claw", 
        "play", "shovel" };  // Word bank for hangman game
    
    char Upperalphabet[] = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
        'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
        'Y', 'Z' };  // Display the letters available

    char Loweralphabet[] = {
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
        'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
        'y', 'z' };  // Erase each letter that is already guessed (using lowercase 
                     //  because only lowercase is acceptable (but will display in uppercase like shown above))


    srand(time(0));  // seed for random number
    int wordNo = (rand() % (21 - 0));  // generate random number to select a random letter from word bank

    wordChosen = wordBank[wordNo];  // store the random word in this variable

    string copy(wordChosen.length(), '_');  // convert the letters of the 'wordChosen' to blanks
    
    // Display Hangman menu
    cout << "--------------------------\n";
    cout << "     Hangman Minigame     \n";
    cout << "--------------------------\n";
    cout << "          ____" << endl;
    cout << "         |    |" << endl;
    cout << "         |    o" << endl;
    cout << "         |   /|" << '\\' << endl;
    cout << "         |    |" << endl;
    cout << "         |   / " << '\\' << endl;
    cout << "        _|_" << endl;
    cout << "       |   |______" << endl;
    cout << "       |          |" << endl;
    cout << "       |__________|" << endl;
    cout << "--------------------------\n";
    cout << "       Guess Words:       \n";
    cout << "--------------------------\n";

    while (wrongCounter < MAXIMUMTRIES){
        for (int x = 0; x < wordChosen.length(); x++){
            cout << copy[x] << " ";
        }
        cout << endl;
        cout << "--------------------------\n";
        cout << "Guess a letter (ONLY IN LOWER CASE!): ";
        cin >> guess;
        cout << "---------------------------------------------\n";
        cout << "    Available Letters (PICK ONLY THESE!):    \n";
        cout << "---------------------------------------------\n";

        // Change Alphabet in the alphabet pool to empty space whenever a user uses that alphabet
        for (int count = 0; count < 26; count++){
            if (Upperalphabet[count] == guess || Loweralphabet[count] == guess){
                Upperalphabet[count] = ' ';
            }
        }

        // Indent the alphabet pool
        for (int countDisplayAlphabet = 0; countDisplayAlphabet < 26; countDisplayAlphabet++){
            cout << Upperalphabet[countDisplayAlphabet] << " ";
            if (countDisplayAlphabet == 7 || countDisplayAlphabet == 15){
                cout << endl;
            }
            if (countDisplayAlphabet == 23){
                cout << endl << "      ";
            }
        }

        // Determine if the guessed letter has been guessed already. Display it and still count it as INCORRECT
        if (determineCorrectLetter(guess, wordChosen, copy) == 0){
            for (int counter = 0; counter < wordChosen.length(); counter++){
                if (guess == wordChosen[counter]){
                    cout << "\nYou already chose this letter!";
                }
            }
            
            cout << "\nIncorrect letter!\n";
            wrongCounter++;

            // Display hangman progress after each wrong guess
            if (wrongCounter == 1){
                cout << "--------------------------\n";
                cout << "       |   |______" << endl;
                cout << "       |          |" << endl;
                cout << "       |__________|" << endl;
                cout << "--------------------------\n";
            }
            if (wrongCounter == 2){
                cout << "--------------------------\n";
                cout << "         |     " << endl;
                cout << "         |     " << endl;
                cout << "         |     " << endl;
                cout << "         |     " << endl;
                cout << "         |     " << endl;
                cout << "        _|_" << endl;
                cout << "       |   |______" << endl;
                cout << "       |          |" << endl;
                cout << "       |__________|" << endl;
                cout << "--------------------------\n";
            }
            if (wrongCounter == 3){
                cout << "--------------------------\n";
                cout << "          ____" << endl;
                cout << "         |    |" << endl;
                cout << "         |     " << endl;
                cout << "         |     " << endl;
                cout << "         |     " << endl;
                cout << "         |     " << endl;
                cout << "        _|_" << endl;
                cout << "       |   |______" << endl;
                cout << "       |          |" << endl;
                cout << "       |__________|" << endl;
                cout << "--------------------------\n";
            }
            if (wrongCounter == 4){
                cout << "--------------------------\n";
                cout << "          ____" << endl;
                cout << "         |    |" << endl;
                cout << "         |    o" << endl;
                cout << "         |     " << endl;
                cout << "         |     " << endl;
                cout << "         |     " << endl;
                cout << "        _|_" << endl;
                cout << "       |   |______" << endl;
                cout << "       |          |" << endl;
                cout << "       |__________|" << endl;
                cout << "--------------------------\n";
            }
            if (wrongCounter == 5){
                cout << "--------------------------\n";
                cout << "          ____" << endl;
                cout << "         |    |" << endl;
                cout << "         |    o" << endl;
                cout << "         |    |" << endl;
                cout << "         |    |" << endl;
                cout << "         |     " << endl;
                cout << "        _|_" << endl;
                cout << "       |   |______" << endl;
                cout << "       |          |" << endl;
                cout << "       |__________|" << endl;
                cout << "--------------------------\n";
            }
            if (wrongCounter == 6){
                cout << "--------------------------\n";
                cout << "          ____" << endl;
                cout << "         |    |" << endl;
                cout << "         |    o" << endl;
                cout << "         |   /|" << endl;
                cout << "         |    |" << endl;
                cout << "         |     " << endl;
                cout << "        _|_" << endl;
                cout << "       |   |______" << endl;
                cout << "       |          |" << endl;
                cout << "       |__________|" << endl;
                cout << "--------------------------\n";
            }
            if (wrongCounter == 7){
                cout << "--------------------------\n";
                cout << "          ____" << endl;
                cout << "         |    |" << endl;
                cout << "         |    o" << endl;
                cout << "         |   /|" << '\\' << endl;
                cout << "         |    |" << endl;
                cout << "         |     " << endl;
                cout << "        _|_" << endl;
                cout << "       |   |______" << endl;
                cout << "       |          |" << endl;
                cout << "       |__________|" << endl;
                cout << "--------------------------\n";
            }
            if (wrongCounter == 8){
                cout << "--------------------------\n";
                cout << "          ____" << endl;
                cout << "         |    |" << endl;
                cout << "         |    o" << endl;
                cout << "         |   /|" << '\\' << endl;
                cout << "         |    |" << endl;
                cout << "         |   / " << endl;
                cout << "        _|_" << endl;
                cout << "       |   |______" << endl;
                cout << "       |          |" << endl;
                cout << "       |__________|" << endl;
                cout << "--------------------------\n";
            }
            if (wrongCounter == 9){
                cout << "--------------------------\n";
                cout << "          ____" << endl;
                cout << "         |    |" << endl;
                cout << "         |    o" << endl;
                cout << "         |   /|" << '\\' << endl;
                cout << "         |    |" << endl;
                cout << "         |   / " << '\\' << endl;
                cout << "        _|_" << endl;
                cout << "       |   |______" << endl;
                cout << "       |          |" << endl;
                cout << "       |__________|" << endl;
                cout << "--------------------------\n";
            }
        }else {
            cout << "\nCorrect guess!";
        }

        // Display how many tries are left
        cout << "Tries left: " << (MAXIMUMTRIES - wrongCounter) << endl;

        // Display this when the user guesses all of the words
        if (wordChosen == copy){
            cout << "--------------------------\n" << wordChosen << "\n--------------------------" << endl;
            cout << "Correct! YOU WON!!!" << endl;
            break;
        }
    }

    // Display this when user runs out of tries
    if (wrongCounter == MAXIMUMTRIES)
        cout << "You ran out of tries! You Lost!";

    return 0;
    
}

// Function to determine whether the guessed letter is correct or not
int determineCorrectLetter(char letterChosen, string hiddenWord, string &currentLetter){
    int x;
    int correct = 0;
    int size = hiddenWord.length();

    for (x = 0; x < size; x++){
        // pass on to the main function if the guess is incorrect
        if (letterChosen == currentLetter[x]){
            return 0;
        }
        // Swap blank to guessed letter (if correct)
        if (letterChosen == hiddenWord[x]){
            currentLetter[x] = letterChosen;
            correct++;
        }
    }
    
    return correct;
}