//FormAI DATASET v1.0 Category: Compression algorithms ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main() {
   char input[50], output[50]; /*initialize input and output arrays*/
   int count = 1, i, j, k = 0;
   printf("Enter the string to be compressed:\n");
   scanf("%s", input); /*read input string from user*/
   int len = strlen(input); /*get the length of input string*/

   for (i = 0; i < len; i++) {
      count = 1;
      for (j = i + 1; j < len; j++) {
         if (input[i] != input[j]) {
            break;
         }
         count++;
      }
      if (count == 1) {
         output[k++] = input[i];
      } else {
         output[k++] = input[i];
         output[k++] = count + '0';
         i = j - 1;
      }
   }
   output[k] = '\0'; /*add '\0' at the end to indicate end of string*/
   printf("Compressed string is %s\n", output);
   return 0;
}