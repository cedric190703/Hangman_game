#include "selectWord.h"

char* getWord() {
    ifstream file("wordsBank/bank.txt");

    // Get a random number between 0 and 74
    int randomNumber = std::rand() % 75;
    int cpt = 0;
    char* line = nullptr;

    if (file.is_open()) {
        string tempLine;
        while (getline(file, tempLine) && cpt < randomNumber) {
            cpt++;
        }

        file.close();

        line = new char[tempLine.length() + 1];
        strcpy(line, tempLine.c_str());
    } else {
        cout << "Unable to open the file." << std::endl;
    }

    return line;
}