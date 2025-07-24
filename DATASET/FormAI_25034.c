//FormAI DATASET v1.0 Category: Word Count Tool ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countWords(char *string) {
  int counter = 0; //initialize counter to 0
  char delimiter[] = " "; //specify delimiter as space
  char *token = strtok(string, delimiter); //get the first token

  while (token != NULL) {
    counter++; //increment counter
    token = strtok(NULL, delimiter); //get the next token
  }

  return counter; //return the final word count
}

int main() {
  char input_string[1000]; //initialize a string to hold user input
  int count; //initialize an integer to hold the word count

  printf("Enter a sentence: ");
  fgets(input_string, 1000, stdin); //get user input using fgets()

  count = countWords(input_string); //call the countWords function to get the word count

  printf("Word count: %d\n", count); //print the word count to the console

  return 0; //exit the program with success
}