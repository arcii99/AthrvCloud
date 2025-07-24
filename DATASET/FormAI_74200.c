//FormAI DATASET v1.0 Category: Text processing ; Style: calm
#include <stdio.h>
#include <string.h>

// function to count the number of words in a string
int countWords(char *str) {

  int count = 0, space = 1;
  char c;

  // iterate through the string
  for(int i = 0; i < strlen(str); i++) {
    c = str[i];

    // check for space or newline characters
    if(c == ' ' || c == '\n') {
      space = 1;
    }
    else {
      if(space) {
        count++;
        space = 0;
      }
    }
  }

  return count;
}

int main() {

  char text[100]; // define a char array to store input text
  int wordCount; // variable to store the word count

  printf("Enter some text:\n");
  fgets(text, 100, stdin); // read input text from user

  wordCount = countWords(text); // call function to count words in the text

  printf("The text you entered is:\n%s", text);
  printf("The text contains %d words.\n", wordCount);

  return 0;
}