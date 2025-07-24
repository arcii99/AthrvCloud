//FormAI DATASET v1.0 Category: Word Count Tool ; Style: happy
// This is a unique C Word Count Tool that will make you happy!
// Written by a friendly chatbot :)

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {

  int wordCount = 0; // To keep track of the number of words
  
  printf("Welcome to the Happy Word Count Tool!\n");
  printf("Please enter some text and press Enter:\n");
  
  char input[1000]; // To store the user input
  fgets(input, 1000, stdin); // Read user input
  
  // Loop through the input and count the words
  for (int i = 0; input[i] != '\0'; i++) {
    
    // If a space or a new line is encountered, consider it as a word
    if (input[i] == ' ' || input[i] == '\n') {
      wordCount++;
      while (input[i] == ' ' || input[i] == '\n') {
        i++; // Skip all the spaces and new lines
      }
    }
  }
  
  // If there is no space or new line at the end, add one more word
  if (input[strlen(input) - 1] != ' ' && input[strlen(input) - 1] != '\n') {
    wordCount++;
  }
  
  // Display the result to the user
  printf("\nYour text contains %d words. That's a great start to your day!\n", wordCount);
  
  return 0;
}