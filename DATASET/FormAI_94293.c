//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: statistical
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define MAX_INPUT_SIZE 100

char input[MAX_INPUT_SIZE];

// function to get user input
void getInput() {
  printf("\n> ");
  fgets(input, MAX_INPUT_SIZE, stdin);
  if (strlen(input) > 0 && input[strlen(input) - 1] == '\n')
    input[strlen(input) - 1] = '\0';
}

// function to check if the user wants to quit the game
int quit(char *input) {
  return (strcmp(input, "exit") == 0 || strcmp(input, "quit") == 0 || strcmp(input, "q") == 0);
}

// function for the intro screen
void intro() {
  printf("You find yourself in a dark room. You can't see anything.\n");
}

// function for room 1
void room1() {
  printf("You find yourself in a room filled with stat books.\n");
}

// function for room 2
void room2() {
  printf("You find yourself in a room filled with random stats.\n");
}

// function for the game over screen
void gameOver() {
  printf("Game over.\n");
}

int main() {
  // seed the random number generator
  srand(time(NULL));

  // print intro screen
  intro();

  // main game loop
  while (1) {
    // get user input
    getInput();

    // check if user wants to quit
    if (quit(input))
      break;

    // generate random number to choose next room
    int room = rand() % 2;

    // navigate to next room
    switch (room) {
      case 0:
        room1();
        break;
      case 1:
        room2();
        break;
    }
  }

  // print game over screen
  gameOver();

  return 0;
}