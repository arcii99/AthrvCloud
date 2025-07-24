//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: cheerful
// Welcome to our User Input Sanitizer program!
// This program will help ensure that your user input is clean and safe.
// Let's get started!

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {

  char input[100]; // create a character array to hold our user input
  printf("Please enter some text: "); // prompt the user to enter some text
  fgets(input, sizeof(input), stdin); // read in the user input

  // now let's sanitize the user input
  for (int i = 0; input[i]; i++) {
    if (isalpha(input[i])) { // if the character is a letter
      input[i] = tolower(input[i]); // convert it to lowercase
    }
    else if (input[i] == ' ') { // if the character is a space
      input[i] = '_'; // replace it with an underscore
    }
    else if (ispunct(input[i])) { // if the character is punctuation
      input[i] = '.'; // replace it with a period
    }
  }

  // now let's print out the sanitized input
  printf("\nYour sanitized input is: %s\n", input);

  return 0; // we're done!
}