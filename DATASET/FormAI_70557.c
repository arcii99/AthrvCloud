//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 15 // maximum characters allowed in the generated password
#define MIN_PASSWORD_LENGTH 8 // minimum characters allowed in the generated password
#define MAX_CHAR_LIMIT 126 // maximum ASCII value
#define MIN_CHAR_LIMIT 33 // minimum ASCII value
#define NUM_SPECIAL_CHARS 15 // number of special characters allowed
#define NUM_NUMBERS 10 // number of numeric characters allowed

int main(){
   char passwordArray[MAX_PASSWORD_LENGTH + 1]; // array to hold generated password
   int charLimit = MAX_CHAR_LIMIT + 1 - MIN_CHAR_LIMIT; // total number of characters allowed
   
   int passwordLength = rand() % (MAX_PASSWORD_LENGTH - MIN_PASSWORD_LENGTH + 1) + MIN_PASSWORD_LENGTH; // random password length
   
   srand(time(NULL)); // set random seed
   
   for(int i=0; i<passwordLength; i++){
       int randomChar = rand() % charLimit + MIN_CHAR_LIMIT; // generate a random ASCII character value
       passwordArray[i] = (char)randomChar; // cast ASCII value to a character and add to password array 
   }
   
   // add special characters and numbers to the password array
   for(int i=0; i<NUM_SPECIAL_CHARS; i++){
       int randomIndex = rand() % passwordLength; // generate a random index to insert special character
       int randomSpecial = rand() % 15 + 33; // generate a random special character
       passwordArray[randomIndex] = (char)randomSpecial; // add special character to password array
   }
   for(int i=0; i<NUM_NUMBERS; i++){
       int randomIndex = rand() % passwordLength; // generate a random index to insert number
       int randomNumber = rand() % 10 + 48; // generate a random number
       passwordArray[randomIndex] = (char)randomNumber; // add number to password array
   }
   
   passwordArray[passwordLength] = '\0'; // add null terminator to password array
   
   printf("Generated password: %s", passwordArray); // print generated password
   return 0;
}