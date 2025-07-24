//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: lively
#include <stdio.h>
#include <string.h>

/* Function to convert C Cat language to human language */
void CCTranslator(char *phrase) {
   char humanWord[30], CCTranslated[200] = "";

   /* Splitting the C Cat phrase into words */
   char *word = strtok(phrase, " ");

   while (word != NULL) {
      if (strcmp(word, "meow") == 0) {
         strcat(CCTranslated, "Hello ");
      } else if (strcmp(word, "purr") == 0) {
         strcat(CCTranslated, "Thank you ");
      } else if (strcmp(word, "hiss") == 0) {
         strcat(CCTranslated, "Goodbye ");
      } else if (strcmp(word, "scratch") == 0) {
         strcat(CCTranslated, "I do not like this ");
      } else {
         /* Converting C Cat word to human word */
         strcpy(humanWord, word);
         humanWord[0] = toupper(humanWord[0]);
         strcat(CCTranslated, humanWord);
         strcat(CCTranslated, " ");
      }

      /* Fetching next word */
      word = strtok(NULL, " ");
   }

   /* Printing the translated phrase */
   printf("\nC Cat Language: %s\nTranslated: %s\n", phrase, CCTranslated);
}

int main() {
   char phrase[200];

   /* Initializing the C Cat language translator */
   printf("\n---------------------------------------");
   printf("\nWELCOME TO THE C CAT TRANSLATOR");
   printf("\n---------------------------------------");

   do {
      printf("\nEnter a C Cat phrase to translate (or enter 'exit' to quit): ");

      /* Fetching user input */
      fgets(phrase, sizeof(phrase), stdin);
      phrase[strcspn(phrase, "\n")] = '\0';

      /* Exiting the program if user enters 'exit' */
      if (strcmp(phrase, "exit") == 0) {
         printf("\nGoodbye!\n");
         break;
      }

      CCTranslator(phrase);
   } while(1);

   return 0;
}