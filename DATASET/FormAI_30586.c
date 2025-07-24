//FormAI DATASET v1.0 Category: Text processing ; Style: Romeo and Juliet
#include <stdio.h> //include standard input/output library

int main() {
  char message[100]; //a character array to hold user input

  printf("Oh, Romeo, Romeo where art thou?\n"); //output text to prompt user input
  printf("Prithee, enter a line of text: "); //output text to prompt user input

  fgets(message, 100, stdin); //read user input from keyboard

  printf("\nAlack, what %d characters hast thou writ!\n", strlen(message)); //output the length of the user input

  for(int i = 0; i < strlen(message); i++){ //iterate through each character in the input
    if(i % 2 == 0){ //if the index is even
      printf("%c ", message[i]); //print the character
    }
    else{ //if the index is odd
      printf("pale-hearted "); //print alternative word
    }
  }

  printf("\nFarewell, dear Romeo!"); //output farewell message
  return 0; //end program
}