#pragma once
#include <stdio.h>
#include "Player.h"
#include "Board.h"

class Game {
public:
    Game(Player player, Board* board) : player(player), board(board) {};
    ~Game() {
        delete board;
    };
    Player getPlayer() { return this->player; };
    int getPlayerScore() { return this->player.getScore(); };
    Board* getBoard() { return this->board; };
    int getAttempPlayer() { return this->player.getAttempt(); };
    void incPlayerAttemp() { this->player.increaseAttemp(); };
    void incPlayerScore() { this->player.increaseScore(); };
    int checkEndGame(int error) { return error == 6 || 
    this->player.getScore() == this->board->getSize() ? 1 : 0; };
    void displayLettersUsed() { this->board->displayLettersUsed(); };
    void displayCorrectLetters() { this->board->displayCorrectLetters(); };
    int containLetter(const char* word, char letter, int size);
    int updateGame(char letter, char* word);

private:
    Player player;
    Board* board;
};