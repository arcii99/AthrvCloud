//FormAI DATASET v1.0 Category: Text processing ; Style: careful
#include <stdio.h>
#include <string.h>

int main() {
   char text[100];
   int i, j, count = 0;

   printf("Enter some text: ");
   fgets(text, sizeof(text), stdin);

   for(i=0; i<strlen(text); i++) {
     
     // check for letter "a"
     if(text[i] == 'a') {
       count++;
       // remove the letter "a"
       for(j=i; j<strlen(text); j++) {
         text[j] = text[j+1];
       }
       i--;
     }
     
     // check for letter "e"
     if(text[i] == 'e') {
       count++;
       // replace the letter "e" with "o"
       text[i] = 'o';
     }
     
     // check for letter "i"
     if(text[i] == 'i') {
       count++;
       // change the letter "i" to uppercase
       text[i] = toupper(text[i]);
     }
     
     // check for letter "u"
     if(text[i] == 'u') {
       count++;
       // change the letter "u" to lowercase
       text[i] = tolower(text[i]);
     }
   }

   printf("After processing, the text is: %s\n", text);
   printf("Total number of vowels removed/changed: %d\n", count);

   return 0;
}