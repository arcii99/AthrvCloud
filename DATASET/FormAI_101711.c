//FormAI DATASET v1.0 Category: Text processing ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
   char str[100], res[100], X;
   int i, j = 0, cnt = 0;

   printf("Enter a string: ");
   fgets(str, sizeof(str), stdin);
   printf("Enter a character to remove: ");
   scanf("%c", &X);

   for(i = 0; i < strlen(str); i++) {
      if(str[i] != X) {
         res[j] = str[i];
         j++;
      } else {
         cnt++;
      }
   }

   if(cnt == 0) {
      printf("The character '%c' was not found.", X);
   } else {
      printf("The character '%c' was found %d times and was removed from the string.\n", X, cnt);
      printf("The new string is: %s", res);
   }

   return 0;
}