//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: irregular
#include <stdio.h>
#include <string.h>

// Define the Alien Language Dictionary
char alienLanguageDict[3][10] = {
   {"GALAXY"},
   {"STAR"},
   {"PLANET"}
};

int main() {
   char userInput[10]; // User input string
   int i;

   printf("Enter a word in Alien Language: ");
   scanf("%s", &userInput);

   // Check if the user input is in the dictionary
   for(i = 0; i < 3; i++) {
      if(strcmp(userInput, alienLanguageDict[i]) == 0) {
         printf("The translation of your word is: ");
         // Print out the corresponding translation
         switch(i) {
            case 0:
               printf("XEROX\n");
               break;
            case 1:
               printf("YODA\n");
               break;
            case 2:
               printf("ZEUS\n");
               break;
         }
         return 0; // Exit program after successful translation
      }
   }

   // If user input is not in dictionary
   printf("Sorry, I cannot translate your word to Earth language.\n");
   return 0;
}