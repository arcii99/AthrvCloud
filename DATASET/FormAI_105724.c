//FormAI DATASET v1.0 Category: Syntax parsing ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

int main() {
   char* input[MAX_SIZE];
   char line[MAX_SIZE];
   int i = 0;
   printf("Enter C Syntax code: \n");

   while (fgets(line, MAX_SIZE, stdin) != NULL) {
      // Strip newline character
      line[strcspn(line, "\n")] = 0;
      if (strcmp(line, "exit") == 0) {
         break;
      }
      input[i] = malloc(strlen(line) + 1);
      strcpy(input[i], line);
      i++;
   }
   printf("\nParsing C Syntax code...\n");

   // Do syntax parsing here!
   printf("Parsing complete.\n");
   return 0;
}