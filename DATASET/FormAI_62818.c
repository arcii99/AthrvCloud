//FormAI DATASET v1.0 Category: String manipulation ; Style: energetic
#include <stdio.h>
#include <string.h>

int main() {
   char string1[50], string2[50];
   int i, j;

   printf("Enter the first string: ");
   scanf("%s", string1);
   printf("Enter the second string: ");
   scanf("%s", string2);

   // Concatenation
   strcat(string1, string2);
   printf("Concatenated string: %s\n", string1);

   // Length calculation
   printf("Length of string1: %d\n", strlen(string1));
   printf("Length of string2: %d\n", strlen(string2));

   // Reversing string1
   j = strlen(string1) - 1;
   for (i = 0; i < j; i++, j--) {
      char temp = string1[i];
      string1[i] = string1[j];
      string1[j] = temp;
   }
   printf("Reversed string1: %s\n", string1);

   // Comparison
   if (strcmp(string1, string2) == 0) {
      printf("String1 and String2 are equal.\n");
   } else {
      printf("String1 and String2 are not equal.\n");
   }

   // Copying
   strcpy(string1, string2);
   printf("Copied string: %s\n", string1);

   return 0;
}