//FormAI DATASET v1.0 Category: Spam Detection System ; Style: mind-bending
#include <stdio.h>
#include <stdbool.h>

int main() {
  char message[1000]; // declare a char array to hold user input
  bool isSpam = false; // initialize the spam flag to false
  int i, j; // declare loop variables

  printf("Please enter your message: ");
  scanf("%[^\n]", message); // read in user input until a newline character is encountered
  
  // loop through each character in the message array
  for(i=0; message[i] != '\0'; i++) {
      
      // check if the current character is a vowel
      if(message[i] == 'a' || message[i] == 'e' || message[i] == 'i' || message[i] == 'o' || message[i] == 'u') {

        // loop through the next 4 characters to see if they are also vowels
        for(j=i+1; j<=i+4; j++) {
          if(message[j] != 'a' && message[j] != 'e' && message[j] != 'i' && message[j] != 'o' && message[j] != 'u') {
            isSpam = true; // if any of the next 4 characters are not vowels, set the spam flag to true
            break; // exit the inner loop
          }
        }

        if(isSpam) {
          printf("This message contains spam.\n"); // if the spam flag is set to true, print a warning message and exit
          return 0;
        }
      }
  }

  printf("This message is not spam.\n"); // if the spam flag is still false, print a message indicating that the message is not spam
  return 0; // exit the program
}