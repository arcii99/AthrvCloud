//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

int main() {

   char input[100];
   printf("Enter your C Cat Language here:\n");
   fgets(input, 100, stdin);

   // Replace meows with semicolons
   char output[100];
   for(int i = 0; i < strlen(input); i++) {
      if(input[i] == 'm' && input[i+1] == 'e' && input[i+2] == 'o' && input[i+3] == 'w') {
         output[i] = ';';
      } else {
         output[i] = input[i];
      }
   }

   printf("\nThe translated C code is:\n%s", output);

   return 0;
}