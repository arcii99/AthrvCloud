//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: shocked
#include <stdio.h>
#include <string.h>

void translate(char* word);
char* translateWord(char* word);

int main() {
   char input[1000];
   printf("Enter a sentence in Cat Language: ");
   fgets(input, 1000, stdin);

   char* word = strtok(input, " ,.-\n");

   while (word != NULL) {
      translate(word);
      word = strtok(NULL, " ,.-\n");
   }

   return 0;
}

void translate(char* word) {
   char* translation = translateWord(word);

   if (translation != NULL) {
      printf("%s ", translation);
   } else {
      printf("%s ", word);
   }
}

char* translateWord(char* word) {
   if (strcmp(word, "Meow") == 0) {
      return "Hello";
   } else if (strcmp(word, "Purr") == 0) {
      return "Thank you";
   } else if (strcmp(word, "Hiss") == 0) {
      return "Goodbye";
   } else if (strcmp(word, "Scratch") == 0) {
      return "Help";
   } else {
      return NULL;
   }
}