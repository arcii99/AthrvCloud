//FormAI DATASET v1.0 Category: String manipulation ; Style: satisfied
#include <stdio.h>
#include <string.h>

int main() {
   char str1[50], str2[50], temp[50];
   int i, j, len1, len2, flag = 0;

   printf("Enter first string: ");
   scanf("%s", str1);

   printf("Enter second string: ");
   scanf("%s", str2);

   len1 = strlen(str1);
   len2 = strlen(str2);

   for (i = 0; i < len1; i++) {
      for (j = i; j < len2; j++) {
         if (str1[i] == str2[j]) {
            flag = 1;
            break;
         }
      }
   }

   if (flag == 1) {
      printf("After swapping the first half of the string 1 with second half of string 2, the string becomes: ");
      strncpy(temp, str1, len1/2);
      strncpy(str1, &str2[len2/2], len2 - len2/2);
      strncpy(&str1[len2 - len2/2], temp, len1/2);
      printf("%s", str1);
   }

   else {
      printf("Strings are not compatible for swapping!");
   }

   return 0;
}