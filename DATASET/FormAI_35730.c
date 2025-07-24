//FormAI DATASET v1.0 Category: String manipulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

int main() {
   char str1[50], str2[50];
   int i, j = 0;

   printf("Enter first string: ");
   gets(str1);

   printf("Enter second string: ");
   gets(str2);

   strcat(str1, str2);

   printf("Concatenated string: %s\n", str1);

   printf("Length of string: %d\n", strlen(str1));

   for (i = 0; str1[i] != '\0'; i++) {
      if (str1[i] != ' ') {
         str1[j++] = str1[i];
      }
   }
   str1[j] = '\0';

   printf("String without spaces: %s\n", str1);

   return 0;
}