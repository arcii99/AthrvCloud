//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Romeo and Juliet
// Prologue
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
  // Opening dialogue
  printf("Two households, both alike in dignity,\n");
  printf("In fair Verona, where we lay our scene,\n");
  printf("From ancient grudge break to new mutiny,\n");
  printf("Where civil blood makes civil hands unclean.\n\n");

  // Introduction
  printf("Welcome to the C Music Library Management System!\n");
  printf("What may we assist you with today?\n");
  
  // Variables
  char commands[6][15] = {"add", "delete", "display", "search", "help", "quit"};
  char input[15];
  
  // Main loop
  while (1) {
    // Prompt user for input
    printf("\nCommand: ");
    fgets(input, 15, stdin);
    input[strcspn(input, "\n")] = 0; // Remove trailing newline character

    // Check if input matches valid commands
    int match = 0;
    for (int i = 0; i < 6; i++) {
      if (strcmp(input, commands[i]) == 0) {
        match = 1;
        break;
      }
    }

    // Execute commands based on user input
    if (match) {
      if (strcmp(input, commands[0]) == 0) {
        // "add" command
        printf("\nYou have chosen to add a new song to the library!\n");
        // Code to add song here
        
      } else if (strcmp(input, commands[1]) == 0) {
        // "delete" command
        printf("\nYou have chosen to delete a song from the library!\n");
        // Code to delete song here
        
      } else if (strcmp(input, commands[2]) == 0) {
        // "display" command
        printf("\nYou have chosen to display the entire library!\n");
        // Code to display library here
        
      } else if (strcmp(input, commands[3]) == 0) {
        // "search" command
        printf("\nYou have chosen to search for a song in the library!\n");
        // Code to search library here
        
      } else if (strcmp(input, commands[4]) == 0) {
        // "help" command
        printf("\nYou have requested assistance with the system!\n");
        // Code to display help information here
        
      } else {
        // "quit" command
        printf("\nParting is such sweet sorrow, but we must bid you adieu!\n");
        break;
      }
    } else {
      printf("\nYou speak an infinite deal of nothing.\nPlease try another command or type 'help' for assistance.\n");
    }
  }

  // Epilogue
  printf("\nGood night, good night! Parting is such sweet sorrow,\nThat I shall say good night till it be morrow.\n");
  return 0;
}