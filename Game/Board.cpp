#include "Board.h"

void Board::displayLettersUsed() {
    cout << "Letters used : ";
    for(int i = 0; i < this->sizeLettersUsed; i++) {
        if(this->correctLettersIdx[i]) {
            cout << "\033[32m" << this->lettersUsed[i] << "\033[0m" << " ";
        } else {
            cout << "\033[31m" << this->lettersUsed[i] << "\033[0m" << " ";
        }
    }
    cout << endl;
}

void Board::displayCorrectLetters() {
    cout << "Letters of the word : ";
    for(int i = 0; i < this->size; i++) {
        cout << this->correctLetters[i];
    }
    cout << endl;
}

int Board::containElt(char* board, char letter, int size) {
    for(int i = 0; i < size; i++) {
        if(board[i] == letter) {
            return 1;
        }
    }
    return 0;
}

int Board::updateBoards(char letter, int idx, int state) {
    int e = 0;
    if(state) {
        // Update main board
        if(this->correctLetters[idx] = '_') {
            e = 1;
            this->correctLetters[idx] = letter;
        }
    }

    if(!this->containElt(this->lettersUsed, letter, this->sizeLettersUsed)) {
        // Update second board
        this->sizeLettersUsed++;
        char* newLettersUsed = new char[sizeLettersUsed];
        int* newCorrectLettersIdx = new int[sizeLettersUsed];

        // Copy existing data to the new arrays
        memcpy(newLettersUsed, this->lettersUsed, (sizeLettersUsed - 1) * sizeof(char));
        memcpy(newCorrectLettersIdx, this->correctLettersIdx, (sizeLettersUsed - 1) * sizeof(int));

        // Add the new element and state
        newLettersUsed[sizeLettersUsed - 1] = letter;
        newCorrectLettersIdx[sizeLettersUsed - 1] = state;

        // Deallocate the old arrays
        delete[] this->lettersUsed;
        delete[] this->correctLettersIdx;

        // Update pointers to the new arrays
        this->lettersUsed = newLettersUsed;
        this->correctLettersIdx = newCorrectLettersIdx;
    }
    return e == 1 ? 1 : 0;
}