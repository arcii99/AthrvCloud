//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20
#define MIN_PASSWORD_LENGTH 8
#define NUM_SPECIAL_CHARS 12

char lowercase_chars[26] = "abcdefghijklmnopqrstuvwxyz";
char uppercase_chars[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char numbers[10] = "0123456789";
char special_chars[NUM_SPECIAL_CHARS] = "!@#$%^&*()";

int main() {
   srand(time(NULL)); // initialize random number generator
   
   char password[MAX_PASSWORD_LENGTH]; // create password array
   int length = rand() % (MAX_PASSWORD_LENGTH - MIN_PASSWORD_LENGTH + 1) + MIN_PASSWORD_LENGTH; // generate random length between 8 and 20 characters
   
   for (int i = 0; i < length; i++) { // iterate through password
      int category = rand() % 4; // generate random category for character
      
      if (category == 0) { // add lowercase character
         int index = rand() % 26;
         password[i] = lowercase_chars[index];
      } 
      else if (category == 1) { // add uppercase character
         int index = rand() % 26;
         password[i] = uppercase_chars[index];
      } 
      else if (category == 2) { // add number
         int index = rand() % 10;
         password[i] = numbers[index];
      } 
      else if (category == 3) { // add special character
         int index = rand() % NUM_SPECIAL_CHARS;
         password[i] = special_chars[index];
      }
   }
   
   password[length] = '\0'; // add null terminator to end of password
   
   printf("Your secure password is: %s\n", password); // print password
   
   return 0;
}