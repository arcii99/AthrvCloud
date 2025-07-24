//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: inquisitive
#include <stdio.h>
#include <string.h>

int main() {
  char cCatMessage[100]; // Declare an array to store the message in C Cat Language
  char englishMessage[100] = ""; // Declare an array to store the translated message
  int cCatIndex = 0; // Declare an integer to keep track of the current position in the C Cat message
  
  printf("Welcome to the C Cat Language Translator!\n");
  printf("Please enter your message in C Cat Language: ");
  fgets(cCatMessage, 100, stdin); // Get input from the user
 
  while(cCatMessage[cCatIndex] != '\0') {
    switch(cCatMessage[cCatIndex]) {
      case 'm':
        strcat(englishMessage, "eow");
        break;
      case 'r':
        strcat(englishMessage, "rrr");
        break;
      case 'a':
        strcat(englishMessage, "nn");
        break;
      case 'w':
        strcat(englishMessage, "oww");
        break;
      default:
        strcat(englishMessage, " "); // add a space if the character is not recognized
        break;
    }
    cCatIndex++;
  }
  
  printf("Here is your message translated into English: %s\n", englishMessage);
  
  return 0;
}