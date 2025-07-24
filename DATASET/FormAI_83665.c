//FormAI DATASET v1.0 Category: Text processing ; Style: minimalist
#include <stdio.h> // import the standard input-output library

int main() { 
  char sentence[1000]; // create a character array to store the sentence
  int i, wordCount = 1; // initialize variables
  
  printf("Enter a sentence: "); // ask the user to enter a sentence
  fgets(sentence, 1000, stdin); // get the input from the user
  
  for (i = 0; sentence[i] != '\0'; i++) { // loop through each character in the sentence
    if (sentence[i] == ' ' && sentence[i+1] != ' ') { // check if a word ends and a new one begins
      wordCount++; // increment the word count
    }
  }
  
  printf("The sentence \"%s\" has %d words.\n", sentence, wordCount); // print the result
  
  return 0; // exit the program
}