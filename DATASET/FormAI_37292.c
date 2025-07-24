//FormAI DATASET v1.0 Category: String manipulation ; Style: futuristic
#include <stdio.h>
#include <string.h>

int main() {
  // Welcome message to the user
  printf("Welcome to the futuristic string manipulation program!\n");

  // Get user input for string manipulation
  printf("Enter a string to manipulate:");
  char input_string[50];
  fgets(input_string, sizeof(input_string), stdin);
  strtok(input_string, "\n"); // removing newline character
  
  // Reverse the input string using a for loop and pointer arithmetic
  char reversed_string[50];
  int length = strlen(input_string);
  for(int i=0; i<length; i++){
    *(reversed_string+i) = *(input_string+length-i-1);
  }
  *(reversed_string+length) = '\0'; // adding null character to end of string
  
  // Print the reversed input string
  printf("Your string reversed is: %s\n", reversed_string);
  
  // Generate new string by removing vowels from the input string using a while loop and switch statement
  char new_string[50] = "";
  int i = 0;
  while(*(input_string+i) != '\0'){
    switch(*(input_string+i)){
      case 'a':
      case 'A':
      case 'e':
      case 'E':
      case 'i':
      case 'I':
      case 'o':
      case 'O':
      case 'u':
      case 'U':
        i++;
        break;
      default:
        strncat(new_string, &*(input_string+i), 1);
        i++;
    }
  }

  // Print the new string without vowels
  printf("Your string without vowels is: %s\n", new_string);

  // Thank the user for using the program
  printf("Thank you for using the futuristic string manipulation program!\n");
  
  return 0;
}