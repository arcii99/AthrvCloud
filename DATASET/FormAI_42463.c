//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
   char string[100];
   int length, i, flag = 0;
   printf("Enter a string: ");
   fgets(string, sizeof(string), stdin);

   length = strlen(string);

   for (i = 0; i < length; i++) {
      if (!isalpha(string[i])) {
         // remove non-alphabet characters from the string
         memmove(&string[i], &string[i + 1], length - i);
         length--;
         i--;
      } else {
         // convert the character to lowercase
         string[i] = tolower(string[i]);
      }
   }
   
   for (i = 0; i < length/2; i++) {
      if (string[i] != string[length - i - 1]) {
         flag = 1;
         break;
      }
   }

   if (flag == 1) {
      printf("%s is not a palindrome.\n", string);
   } else {
      printf("%s is a palindrome.\n", string);
   }

   return 0;
}