//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: futuristic
// Welcome to the C Cat Language Translator program 
// This program will translate human language to C Cat language
// Let's get started!

#include <stdio.h>
#include <string.h>

int main() {

   char humanLanguage[1000], cCatLanguage[1000], word[1000];
   int i, j = 0, len;
   
   // Prompt user to enter a sentence in human language
   printf("Enter a sentence in human language: ");
   fgets(humanLanguage, 1000, stdin);
   
   // Splitting the input sentence into words using strtok() function
   char *token = strtok(humanLanguage, " ");
   
   while(token != NULL) {
      strncpy(word, token, sizeof(word));
      len = strlen(word);
      
      // Converting human language word to C Cat language word
      for(i=0; i<len; i++) {
         if(i%2 == 0)
            word[i] = tolower(word[i]);
         else
            word[i] = toupper(word[i]);
      }
      cCatLanguage[j++] = word;
      cCatLanguage[j++] = " ";
      token = strtok(NULL, " ");
   }
   cCatLanguage[j] = "\0";
   
   // Printing the C Cat language sentence
   printf("In C Cat language: %s", cCatLanguage);
   
   return 0;
}