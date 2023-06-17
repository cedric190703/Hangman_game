#include "Game/Game.h"
#include "Ascii_code/ascii_code.h"
#include "wordsBank/selectWord.h"
#include <ctime>
#include <cstring>

int main() {
    while(true) {
        srand(time(0)); 
        // Choose a word in the bank
        char* word = getWord();

        // Initialize objects
        string name;
        cout << "What's your name ?" << endl;
        cin >> name;
        Player player(name, 0);
        cout << endl;
        int wordSize = strlen(word);
        Board* board = new Board(word, wordSize);

        // Create Game
        Game game(player, board);
        int errors = 0;
        char letter;
        int cpt;
        // While not finish
        while(!game.checkEndGame(errors)) {
            // Display elements of the game
            game.displayCorrectLetters();
            game.displayLettersUsed();
            cout << endl;
            displayAscii(errors);

            // Player has to choose a letter
            cout << game.getPlayer().getName() << " Choose a letter :" << endl;
            cin >> letter;
            cout << endl;

            // Evaluate the letter chosen
            if(game.containLetter(word, letter, wordSize)) {
                cout << "Good job ! This letter is in the word !" << endl;
                // Manage changes
                // cout << game.getPlayerScore() << endl;
                // cout << game.getBoard()->getSize() << endl;
                cpt = game.updateGame(letter, word);
                for(int k = 0; k < cpt; k++) {
                    game.incPlayerScore();
                }
            } else {
                cout << "Damn ! This letter isn't in the word !" << endl;
                // Manage changes
                cpt = game.updateGame(letter, word);
                errors++;
            }
            cout << endl;
            game.incPlayerAttemp();
        }
        if(errors < 6) {
            cout << "Congratulation !" << endl;
            cout << "Total attempts : " << game.getAttempPlayer() << endl;
        } else {
            cout << endl;
            displayAscii(errors);
            cout << "You lose !" << endl;
            cout << "Total attempts : " << game.getAttempPlayer() << endl;
        }
        cout << "The word was : " << word << endl;
        cout << endl;
        char answer;
        cout << "You want to stop or to restart one game ? (stop) -> S or s, (restart) -> R or r:" << endl;
        cin >> answer;
        cout << endl;
        while(answer != 'R' && answer != 'r' && answer != 'S' && answer != 's') {
            cout << "I don't anderstand your choice :" << endl;
            cin >> answer;
        }
        delete[] word;
        if(answer == 'S' || answer == 's') {
            break;
        }
    }

    return 0;
}