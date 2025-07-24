//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

   char catLanguage[] = "MEOAWWwwooOOOWWWW!";
   
   char englishTranslation[] = "Hello, how are you?";
   
   printf("The cat says: %s\n", catLanguage);
   
   // Code to translate cat language to English
   
   char translation[100] = "";
   
   // First, replace 'M' with 'H'
   for(int i = 0; i < strlen(catLanguage); i++) {
      if(catLanguage[i] == 'M') {
         translation[i] = 'H';
      } else {
         translation[i] = catLanguage[i];
      }
   }
   
   // Next, replace 'E' with 'e'
   for(int i = 0; i < strlen(catLanguage); i++) {
      if(catLanguage[i] == 'E') {
         translation[i] = 'e';
      }
   }
   
   // Next, replace 'O' with 'o'
   for(int i = 0; i < strlen(catLanguage); i++) {
      if(catLanguage[i] == 'O') {
         translation[i] = 'o';
      }
   }
   
   // Next, replace 'A' with 'a'
   for(int i = 0; i < strlen(catLanguage); i++) {
      if(catLanguage[i] == 'A') {
         translation[i] = 'a';
      }
   }
   
   // Finally, replace 'W' with 'y'
   for(int i = 0; i < strlen(catLanguage); i++) {
      if(catLanguage[i] == 'W') {
         translation[i] = 'y';
      }
   }
   
   printf("English Translation: %s\n", translation);
}