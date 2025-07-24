//FormAI DATASET v1.0 Category: Text processing ; Style: high level of detail
#include <stdio.h>
#include <string.h>

int main() {
   char input[100], output[100];
   int i, j, len;

   printf("Enter a string: ");
   gets(input);

   len = strlen(input);
   j = 0;

   for(i = 0; i < len; i++) {

      if(input[i] == '/') {
         output[j] = '\\';
         j++;
      }

      output[j] = input[i];
      j++;

   }

   output[j] = '\0';

   printf("Output: %s", output);

   return 0;
}