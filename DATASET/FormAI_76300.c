//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
  Secure Password Generator
  Generates a random password consisting of uppercase and lowercase letters, digits, and special characters
*/

int main()
{
  srand(time(NULL)); // Seed the random number generator
  
  int length = 12; // Set the length of the password
  char password[length+1]; // Array to store the password
  
  // Define the character sets
  char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
  char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char digits[] = "0123456789";
  char special[] = "!@#$%^&*()_+-={}[]\\|;:'\"<>,.?/~`";
  
  // Generate the password
  for (int i = 0; i < length; i++) {
    int rand_num = rand() % 4; // Generate a random number between 0 and 3
    switch (rand_num) {
      case 0: // Lowercase letter
        password[i] = lowercase[rand() % 26];
        break;
      case 1: // Uppercase letter
        password[i] = uppercase[rand() % 26];
        break;
      case 2: // Digit
        password[i] = digits[rand() % 10];
        break;
      case 3: // Special character
        password[i] = special[rand() % 29];
        break;
    }
  }
  
  password[length] = '\0'; // Add null terminator to the end of the password
  
  printf("Random Password: %s", password);
  
  return 0;
}