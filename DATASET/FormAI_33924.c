//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: random
#include <stdio.h>

// Define dictionary for C Cat Language Translator
const char* cat_words[] = {"meow", "purr", "hiss", "scratch", "nap", 
                           "mouse", "tuna", "catnip", "lap", "snooze"};

const char* human_words[] = {"Hello", "I'm happy", "I'm angry", "I'm irritated", "I'm tired", 
                           "I want food", "Give me fish", "I want some catnip", "Let me sit on your lap", "I'm going to sleep"};

// Define main function
int main() {
  // Display welcome message
  printf("Welcome to C Cat Language Translator!\n");

  // Declare variables for user input and translation output
  char input[50];
  char output[50];

  // Main program loop
  while(1) {
    // Prompt user for input
    printf("Enter your cat's message: ");
    scanf("%s", input);

    // Check if input equals "quit", break if it does
    if(strcmp(input, "quit") == 0) {
      printf("Goodbye!");
      break;
    }
    
    // Loop through dictionary to find match for input
    int i;
    for(i = 0; i < 10; i++) {
      if(strcmp(input, cat_words[i]) == 0) {
        strcpy(output, human_words[i]);
        break;
      }
    }
    
    // Display translation output, or notify user if translation not found
    if(i < 10) {
      printf("Translation: %s\n", output);
    } else {
      printf("Translation not found!\n");
    }
  }

  return 0;
}