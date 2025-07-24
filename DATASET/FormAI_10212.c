//FormAI DATASET v1.0 Category: HTML beautifier ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

int main() {
   FILE *input_file = fopen("input.html", "r");
   FILE *output_file = fopen("output.html", "w");
   
   if (input_file == NULL) {
      printf("Error opening input file!\n");
      exit(1);
   }
   if (output_file == NULL) {
      printf("Error opening output file!\n");
      exit(1);
   }

   char c, last_c = ' ';
   while ((c = fgetc(input_file)) != EOF) {
      if (c == '<' && last_c != ' ') {
         fputc('\n', output_file);
      }
      fputc(c, output_file);
      last_c = c;
   }

   fclose(input_file);
   fclose(output_file);
   printf("Successfully beautified input.html to output.html!\n");
   return 0;
}