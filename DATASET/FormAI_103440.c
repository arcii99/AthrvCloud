//FormAI DATASET v1.0 Category: String manipulation ; Style: happy
#include <stdio.h>
#include <string.h>

int main() {
   
   char sentence[1000], happyString[1000];
   int i, j = 0;

   printf("Enter a sentence: ");
   fgets(sentence, sizeof(sentence), stdin);

   for (i = 0; i < strlen(sentence); i++) {
      if (sentence[i] == 's' || sentence[i] == 'S') {  //if sentence contains 's' or 'S'
         happyString[j] = '$';  //replace with dollar sign
      } else if (sentence[i] == ' ') { //if sentence contains space
         happyString[j] = '_'; //replace with underscore
      } else if (i % 2 == 0) { //if even indexed character
         happyString[j] = sentence[i] + 1; //increment its ASCII value by 1
      } else { //if odd indexed character
         happyString[j] = sentence[i] - 1; //decrement its ASCII value by 1
      }

      j++; //increment position in happyString
   }

   printf("\nYour Happy String: %s\n", happyString);

   return 0;
}