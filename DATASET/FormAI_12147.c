//FormAI DATASET v1.0 Category: Compression algorithms ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

int main() {
   FILE *input, *output;
   char ch, last_ch;
   int count;

   // Opening input and output files
   input = fopen("input.txt", "r");
   output = fopen("output.txt", "w");

   // Error handling
   if (input == NULL) {
      printf("Unable to open file input.txt");
      exit(EXIT_FAILURE);
   }

   // Initializing variables
   last_ch = fgetc(input);
   count = 1;

   // Reading input file and compressing
   while ((ch = fgetc(input)) != EOF) {
      if (ch == last_ch) {
         count++;
      } else {
         fprintf(output, "%c%d", last_ch, count);
         last_ch = ch;
         count = 1;
      }
   }

   // Printing last compressed sequence and closing files
   fprintf(output, "%c%d", last_ch, count);
   fclose(input);
   fclose(output);

   return 0;
}