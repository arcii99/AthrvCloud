//FormAI DATASET v1.0 Category: Text processing ; Style: satisfied
#include <stdio.h>
#include <string.h>

int main() {
   char string[1000];
   char search[100];
   int count = 0;

   printf("Enter a string:\n");
   fgets(string, sizeof(string), stdin);

   printf("Enter a word to search:\n");
   scanf("%s", search);

   char *found = strstr(string, search);

   if (found == NULL) {
      printf("%s not found in string.\n", search);
   } else {
      printf("%s found in string:\n", search);
      while (found != NULL) {
         count++;
         printf("Occurence %d: %s\n", count, found);
         found = strstr(found + 1, search);
      }
   }

   return 0;
}