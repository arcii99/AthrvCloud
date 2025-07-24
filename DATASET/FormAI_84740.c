//FormAI DATASET v1.0 Category: String manipulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100
#define MAX_PLAYER_COUNT 4

// Function to get the string input from a player
void getPlayerInput(char* playerInput, int playerNumber) {
  printf("\nPlayer %d, enter a string: ", playerNumber);
  fgets(playerInput, MAX_STRING_LENGTH, stdin);
  playerInput[strcspn(playerInput, "\n")] = 0;  // Remove the newline character from the input
}

// Function to manipulate the string entered by a player
void manipulateString(char* playerInput) {
  for (int i = 0; playerInput[i] != '\0'; i++) {
    // Replace all spaces with a dash (-)
    if (playerInput[i] == ' ') {
      playerInput[i] = '-';
    }
    // Convert all uppercase letters to lowercase
    if (playerInput[i] >= 'A' && playerInput[i] <= 'Z') {
      playerInput[i] += 32;
    }
    // Remove all punctuation marks
    if (ispunct(playerInput[i])) {
      for (int j = i; playerInput[j] != '\0'; j++) {
        playerInput[j] = playerInput[j+1];
      }
      i--;
    }
  }
}

int main() {
  char playerInputs[MAX_PLAYER_COUNT][MAX_STRING_LENGTH];
  char manipulatedStrings[MAX_PLAYER_COUNT][MAX_STRING_LENGTH];

  // Get the input from each player
  for (int i = 0; i < MAX_PLAYER_COUNT; i++) {
    getPlayerInput(playerInputs[i], i+1);
  }

  // Manipulate the string entered by each player
  for (int i = 0; i < MAX_PLAYER_COUNT; i++) {
    manipulateString(playerInputs[i]);
    strcpy(manipulatedStrings[i], playerInputs[i]);
    printf("\nManipulated string from Player %d: %s\n", i+1, manipulatedStrings[i]);
  }

  return 0;
}