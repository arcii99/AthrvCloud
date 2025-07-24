//FormAI DATASET v1.0 Category: Text processing ; Style: peaceful
#include <stdio.h>
#include <string.h>

int main() {

   char text[1000], peacefulText[1000], vowels[] = "AEIOUaeiou";
   int i, j, k = 0;

   printf("Enter some text: ");
   fgets(text, sizeof(text), stdin);

   for(i = 0; text[i] != '\0'; i++) {
   
      if(text[i] == '.' || text[i] == ',' || text[i] == '?' || text[i] == '!') {
         continue; // ignore punctuation marks
      }
      
      for(j = 0; vowels[j] != '\0'; j++) {
         if(text[i] == vowels[j]) {
            peacefulText[k] = '*'; // replace vowel with an asterisk
            break;
         }
      }
      
      if(vowels[j] == '\0') { // if vowel not found
         peacefulText[k] = text[i]; // add original character to new string
      }
      
      k++;
   }

   peacefulText[k] = '\0'; // make sure new string is null-terminated

   printf("\nOriginal Text: %s", text);
   printf("Peaceful Text: %s", peacefulText);

   return 0;
}