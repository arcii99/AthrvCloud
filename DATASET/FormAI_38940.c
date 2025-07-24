//FormAI DATASET v1.0 Category: String manipulation ; Style: random
#include <stdio.h>
#include <string.h>

int main() {
   char str1[50], str2[50], str3[100];
   int i, j, k;

   printf("Enter string 1: ");
   fgets(str1, 50, stdin);
   printf("Enter string 2: ");
   fgets(str2, 50, stdin);

   // Reversing string 1
   for (i = strlen(str1)-2, j = 0; i >= 0; i--, j++) {
      str3[j] = str1[i];
   }
   str3[j] = '\0';

   // Concatenating string 2 with reversed string 1
   strcat(str3, str2);
   printf("Concatenated string: %s\n", str3);

   // Replacing vowels with '*'
   for (i = 0; str3[i] != '\0'; i++) {
      if (str3[i] == 'a' || str3[i] == 'e' || str3[i] == 'i' || str3[i] == 'o' || str3[i] == 'u' || str3[i] == 'A' || str3[i] == 'E' || str3[i] == 'I' || str3[i] == 'O' || str3[i] == 'U') {
         str3[i] = '*';
      }
   }
   printf("String after replacing vowels with '*': %s\n", str3);

   // Replacing spaces with underscore
   for (i = 0; str3[i] != '\0'; i++) {
      if (str3[i] == ' ') {
         str3[i] = '_';
      }
   }
   printf("String after replacing spaces with '_': %s\n", str3);

   // Removing non-alphabetic characters
   for (i = 0, k = 0; str3[i] != '\0'; i++) {
      if ((str3[i] >= 'a' && str3[i] <= 'z') || (str3[i] >= 'A' && str3[i] <= 'Z')) {
         str3[k++] = str3[i];
      }
   }
   str3[k] = '\0';
   printf("String after removing non-alphabetic characters: %s\n", str3);

   // Changing all characters to lowercase
   for (i = 0; str3[i] != '\0'; i++) {
      if (str3[i] >= 'A' && str3[i] <= 'Z') {
         str3[i] += 32;
      }
   }
   printf("String after changing all characters to lowercase: %s\n", str3);

   return 0;
}