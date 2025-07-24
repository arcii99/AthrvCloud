//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   int lowercaseLetters = 10, uppercaseLetters = 10, digits = 10, specialCharacters = 10; // initialize counts for each character set
   int totalCharacters = lowercaseLetters + uppercaseLetters + digits + specialCharacters; // calculate total character count
   int passwordLength = 12; // set desired password length
   char password[passwordLength + 1]; // create array to hold password
   password[passwordLength] = '\0'; // terminate password string

   srand(time(NULL)); // seed random number generator with current time

   int i;
   for (i = 0; i < passwordLength; i++) { // loop through each character in password
      int randomCharacterSet = rand() % totalCharacters; // generate random number to choose character set
      char c;
      if (randomCharacterSet < lowercaseLetters) { // if random number indicates lowercase letters
         c = 'a' + (rand() % 26); // choose random lowercase letter
         lowercaseLetters--; // decrement available lowercase letters count
      } else if (randomCharacterSet < lowercaseLetters + uppercaseLetters) { // if random number indicates uppercase letters
         c = 'A' + (rand() % 26); // choose random uppercase letter
         uppercaseLetters--; // decrement available uppercase letters count
      } else if (randomCharacterSet < lowercaseLetters + uppercaseLetters + digits) { // if random number indicates digits
         c = '0' + (rand() % 10); // choose random digit
         digits--; // decrement available digits count
      } else { // if random number indicates special characters
         char specialChars[] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', '-', '=', '{', '}', '[', ']', '|', ':', ';', '<', '>', '?'}; // array of available special characters
         c = specialChars[rand() % 23]; // choose random special character
         specialCharacters--; // decrement available special characters count
      }
      password[i] = c; // add chosen character to password array
      totalCharacters--; // decrement total character count
   }

   printf("Your secure password is: %s\n", password); // display generated password

   return 0; // end program
}