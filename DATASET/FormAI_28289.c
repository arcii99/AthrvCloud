//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

  printf("Welcome to the C Checksum Calculator!\n");
  printf("Please enter the string you'd like to calculate the checksum for:\n");

  char input[100];
  fgets(input, 100, stdin);

  int checksum = 0;

  for(int i = 0; i < strlen(input); i++){

    if(input[i] == ' '){
      continue;
    }

    checksum += (int)input[i];

  }

  printf("\n\n");

  printf("The checksum for the string you entered is: %d\n", checksum);

  printf("\n\n");

  printf("Are you puzzled by how this program works? Let's break it down:\n\n");

  printf("First, we prompt the user for the input string. We limit the input to 100 characters to avoid overflow errors.\n\n");

  printf("After we receive the input, we create a variable called 'checksum' which will hold the final calculated checksum.\n\n");

  printf("Next, we loop through each character in the input string using a for loop.\n\n");

  printf("If the current character is a space, we skip it using the 'continue' keyword.\n\n");

  printf("If the current character is not a space, we add its ASCII value to the checksum using the '+= ' operator.\n\n");

  printf("Once we have looped through all the characters, we print out the final calculated checksum and some explanation as to how the program works!\n\n");

  printf("Thanks for using the C Checksum Calculator. Happy coding!");

  return 0;
}