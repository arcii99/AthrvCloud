//FormAI DATASET v1.0 Category: String manipulation ; Style: cheerful
/* Welcome to my C String Manipulation Program! */
#include <stdio.h>
#include <string.h>

int main() {
  char greeting[40] = "Hello, world!"; // A cheerful greeting
  char name[20]; // Declare a string to store user input
  
  printf("%s\n", greeting); // Display the greeting
  
  printf("What's your name?\n"); // Ask the user for their name
  scanf("%s", name); // Read in their response
  
  int len = strlen(name); // Get the length of the user's name
  
  if (len < 1) { // Check if the user didn't enter anything
    printf("Oh no, you forgot to enter your name!\n");
    return 1; // Exit the program with an error code
  }
  
  char excitedName[40]; // Declare a new string to store the modified name
  
  for (int i = 0; i < len; i++) { // Loop through each character in the name
    char c = name[i];
    excitedName[i] = c + 1; // Increment the ASCII value of each character by 1
  }
  
  excitedName[len] = '\0'; // Add the null terminator to the end of the string
  
  printf("Hey there, %s! Your name is so exciting now!\n", excitedName); // Display the modified name
  
  return 0; // Exit the program with a success code
}