//FormAI DATASET v1.0 Category: String manipulation ; Style: thoughtful
#include <stdio.h>
#include <string.h>

int main() {
   char str1[50], str2[50];
   int len1, len2, i, j, flag = 0;
   
   // Getting input from user
   printf("Enter first string: ");
   gets(str1);
   printf("Enter second string: ");
   gets(str2);
   
   // Calculating length of both strings
   len1 = strlen(str1);
   len2 = strlen(str2);
   
   // Checking if strings are of equal length
   if (len1 != len2) {
      printf("Strings are not of equal length\n");
   }
   else {
      // Reversing the second string
      for (i = 0, j = len2 - 1; i < j; i++, j--) {
         char temp = str2[i];
         str2[i] = str2[j];
         str2[j] = temp;
      }
      
      // Comparing both strings character by character
      for (i = 0; i < len1; i++) {
         if (str1[i] != str2[i]) {
            flag = 1;
            break;
         }
      }
      
      // Displaying output
      if (flag == 0)
         printf("Strings are palindrome of each other\n");
      else
         printf("Strings are not palindrome of each other\n");
   }
   
   return 0;
}