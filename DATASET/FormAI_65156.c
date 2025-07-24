//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 16

// Function to generate a random integer between given range
int generateRandomIntInRange(int start, int end) {
   return (rand() % (end - start + 1)) + start;
}

// Function to generate a random uppercase letter
char generateRandomUpperCase() {
   return (char)generateRandomIntInRange(65, 90); // ASCII values for A-Z
}

// Function to generate a random lowercase letter
char generateRandomLowerCase() {
   return (char)generateRandomIntInRange(97, 122); // ASCII values for a-z
}

// Function to generate a random digit
char generateRandomDigit() {
   return (char)generateRandomIntInRange(48, 57); // ASCII values for 0-9
}

// Function to generate a random special character
char generateRandomSpecialChar() {
   const char specialChars[] = "@#%!*";
   int index = generateRandomIntInRange(0,4);
   return specialChars[index];
}

// Function to generate a secure password
void generateSecurePassword(char* password) {
   int length = generateRandomIntInRange(MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
   int charType; // 1 - uppercase, 2 - lowercase, 3 - digit, 4 - special char
   for (int i = 0; i < length; i++) {
      charType = generateRandomIntInRange(1, 4);
      switch(charType) {
         case 1: // Uppercase Letter
            password[i] = generateRandomUpperCase();
            break;
         case 2: // Lowercase Letter
            password[i] = generateRandomLowerCase();
            break;
         case 3: // Digit
            password[i] = generateRandomDigit();
            break;
         case 4: // Special Character
            password[i] = generateRandomSpecialChar();
            break;
      }
   }
   password[length] = '\0'; // Adding null character at the end
}

// Driver function
int main() {
   srand(time(0)); // Setting seed for random number generation
   char password[MAX_PASSWORD_LENGTH+1];
   generateSecurePassword(password);
   printf("Generated Password: %s", password);
   return 0;
}