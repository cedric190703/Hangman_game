#pragma once
#include <iostream>
#include <string.h>

using namespace std;

class Board {
public:
    Board(char* word, int size) {
        this->correctLetters = new char[size];
        for(int i = 0; i < size; i++) {
            this->correctLetters[i] = '_';
        }
        this->lettersUsed = nullptr;
        this->correctLettersIdx = nullptr;
        this->size = size;
        this->sizeLettersUsed = 0;
    }
    ~Board() {
        delete[] lettersUsed;
        delete[] correctLetters;
        delete[] correctLettersIdx;
    }
    char* getLettersUsed() { return this->lettersUsed; };
    char* getcorrectLetters() { return this->correctLetters; };
    int* getcorrectLettersIdx() { return this->correctLettersIdx; };
    int getSize() { return this->size; } ;
    void displayLettersUsed();
    void displayCorrectLetters();
    int updateBoards(char letter, int idx, int state);
    int containElt(char* board, char letter, int size);

private:
    char* lettersUsed;
    int* correctLettersIdx;
    char* correctLetters;
    int size;
    int sizeLettersUsed;
};