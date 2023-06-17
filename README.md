# Hangman_game
This project is about to create an Hangman game in c++.

Structure of the project :
<pre>
.
├── Ascii_code
│   ├── ascii_code.cpp
│   └── ascii_code.h
├── Game
│   ├── Board.cpp
│   ├── Board.h
│   ├── Game.cpp
│   ├── Game.h
│   └── Player.h
├── main.cpp
├── Makefile
├── README.md
└── wordsBank
    ├── bank.txt
    ├── selectWord.cpp
    └── selectWord.h

3 directories, 13 files
</pre>

<hr>

### An example of the game: 
<pre>
What's your name ?
cedric

Letters of the word : _______
Letters used : 

  +---+
  |   |
      |
      |
      |
      |
=========

cedric Choose a letter :
e

Damn ! This letter isn't in the word !

Letters of the word : _______
Letters used : e 

  +---+
  |   |
  O   |
      |
      |
      |
=========

cedric Choose a letter :
a

Good job ! This letter is in the word !

Letters of the word : _____a_
Letters used : e a 

  +---+
  |   |
  O   |
      |
      |
      |
=========

cedric Choose a letter :
t

Good job ! This letter is in the word !

Letters of the word : _____at
Letters used : e a t 

  +---+
  |   |
  O   |
      |
      |
      |
=========

cedric Choose a letter :
k

Good job ! This letter is in the word !

Letters of the word : K____at
Letters used : e a t K 

  +---+
  |   |
  O   |
      |
      |
      |
=========

cedric Choose a letter :
u

Good job ! This letter is in the word !

Letters of the word : Ku__uat
Letters used : e a t K u 

  +---+
  |   |
  O   |
      |
      |
      |
=========

cedric Choose a letter :
m

Good job ! This letter is in the word !

Letters of the word : Kum_uat
Letters used : e a t K u m 

  +---+
  |   |
  O   |
      |
      |
      |
=========

cedric Choose a letter :
q

Good job ! This letter is in the word !

Congratulation !
Total attempts : 7
The word was : Kumquat

You want to stop or to restart one game ? (stop) -> S or s, (restart) -> R or r:
</pre>
