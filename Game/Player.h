#pragma once
#include <string>

using namespace std;

class Player {
public:
    Player(string name, int score) : name(name), score(score) {};
    ~Player() {};
    string getName() { return this->name; };
    int getScore() { return this->score; };
    void increaseScore() { this->score++; };
    int getAttempt() { return this->attempts; };
    void increaseAttemp() { this->attempts++; };
private:
    string name;
    int score;
    int attempts;
};