//FormAI DATASET v1.0 Category: Word Count Tool ; Style: irregular
#include <stdio.h>

int main() {
   char str[100];
   int c, count[26]={0};

   printf("Enter a string: ");
   gets(str);

   for (c = 0; str[c] != '\0'; c++) {
      if (str[c] >= 'a' && str[c] <= 'z') {
         count[str[c] - 'a']++;
      }
   }

   for (c = 0; c < 26; c++) {
      if (count[c] != 0) {
         printf("%c occurs %d times in the entered string.\n",c + 'a',count[c]);
      }
   }

   return 0;
}