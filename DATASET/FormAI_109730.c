//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: peaceful
#include <stdio.h>
#include <string.h>

// Function to translate words from Alien language to English
void translate(char *word) {
  if (strcmp(word, "meep") == 0) { // if the word is "meep"
    printf("Greetings!\n"); // translate to "Greetings!"
  }
  else if (strcmp(word, "flep") == 0) { // if the word is "flep"
    printf("Goodbye!\n"); // translate to "Goodbye!"
  }
  else if (strcmp(word, "zorp") == 0) { // if the word is "zorp"
    printf("Thank you!\n"); // translate to "Thank you!"
  }
  else { // for any other word
    printf("I'm sorry, I don't understand.\n"); // translate to "I'm sorry, I don't understand."
  }
}

int main() {
  char word[10]; // variable to store the word entered by the user
  printf("Welcome to the Alien Language Translator!\n");
  printf("Please enter a word in Alien Language: "); 
  scanf("%s", word); // read the word entered by the user
  translate(word); // call the translate function to translate the word
  return 0;
}