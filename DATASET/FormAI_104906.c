//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: ultraprecise
#include <stdio.h>
#include <string.h>
 
int main() {
   char input[100], output[100], temp[100];
   int i, j, k, l;
 
   // Getting the user input
   printf("Enter a sentence in C Cat Language: ");
   fgets(input, sizeof(input), stdin);
 
   // Removing the spaces at the beginning and end of the input
   while(input[0] == ' ')
      strcpy(&input[0], &input[1]);
 
   while(input[strlen(input) - 1] == ' ')
      strcpy(&input[strlen(input) - 1], "\0");
 
   // Handling the words in the input
   j = 0;
   for(i = 0; i <= strlen(input); i++) {
      if(input[i] == ' ' || input[i] == '\0') {
         strncpy(temp, &input[j], i - j);
         temp[i-j] = '\0';
         j = i+1;

         // Translating the word to English
         if(strcmp(temp, "meow") == 0)
            strcpy(temp, "cat");
         else if(strcmp(temp, "purr") == 0)
            strcpy(temp, "happy");
         else if(strcmp(temp, "hiss") == 0)
            strcpy(temp, "angry");
         else if(strcmp(temp, "scratch") == 0)
            strcpy(temp, "claw");
         else if(strcmp(temp, "biscuit") == 0)
            strcpy(temp, "treat");
         
         // Adding the translated word to the output string
         if(strlen(output) != 0)
            strcat(output, " ");
         strcat(output, temp);
      }
   }

   printf("Translated sentence: %s\n", output);

   return 0;
}