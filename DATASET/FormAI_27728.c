//FormAI DATASET v1.0 Category: String manipulation ; Style: satisfied
#include <stdio.h>
#include <string.h>

int main() {
   char str1[100], str2[100], temp;
   int choice, i, j;

   printf("Enter first string: ");
   fgets(str1, 100, stdin);
   str1[strcspn(str1, "\n")] = '\0'; // remove trailing newline character
   
   printf("Enter second string: ");
   fgets(str2, 100, stdin);
   str2[strcspn(str2, "\n")] = '\0'; // remove trailing newline character

   printf("Choose an operation:\n");
   printf("1) Concatenate two strings\n");
   printf("2) Reverse a string\n");
   scanf("%d", &choice);

   switch (choice) {
      case 1: // concatenate two strings
         strcat(str1, str2);
         printf("Concatenated string: %s\n", str1);
         break;

      case 2: // reverse a string
         for (i = 0, j = strlen(str1)-1; i < j; i++, j--) {
            temp = str1[i];
            str1[i] = str1[j];
            str1[j] = temp;
         }
         printf("Reversed string: %s\n", str1);
         break;

      default:
         printf("Invalid choice!\n");
         break;
   }

   return 0;
}