#include "Game.h"
#include <ctype.h>

int Game::containLetter(const char* word, char letter, int size) {
    for(int i = 0; i < size; i++) {
        if(toupper(word[i]) == toupper(letter)) {
            return 1;
        }
    }
    return 0;
}

int Game::updateGame(char letter, char* word) {
    int state = 0;
    int cpt = 0;
    for(int i = 0; i < this->board->getSize(); i++) {
        if(toupper(word[i]) == toupper(letter)) {
            state = 1;
            cpt += this->board->updateBoards(word[i], i, 1);
        }
    }
    if(!state) {
        this->board->updateBoards(letter, 0, 0);
    }
    return cpt;
}