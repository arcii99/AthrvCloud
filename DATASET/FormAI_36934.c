//FormAI DATASET v1.0 Category: HTML beautifier ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {
   FILE *input_file, *output_file;
   char c;

   // Read in the input file
   input_file = fopen("input.html", "r");
   if (input_file == NULL) {
      printf("Error opening input file\n");
      exit(1);
   }

   // Create the output file
   output_file = fopen("output.html", "w");
   if (output_file == NULL) {
      printf("Error creating output file\n");
      exit(1);
   }

   // Loop through input file, writing formatted code to output file
   while ((c = getc(input_file)) != EOF) {
      // If opening tag found, add new line and increase indentation
      if (c == '<') {
         putc('\n', output_file);
         fprintf(output_file, "  ");
         putc(c, output_file);
      }
      // If closing tag found, decrease indentation and add new line
      else if (c == '>') {
         putc(c, output_file);
         putc('\n', output_file);
      }
      // Otherwise just write to output file
      else {
         putc(c, output_file);
      }
   }

   // Close input and output files
   fclose(input_file);
   fclose(output_file);

   printf("HTML beautified and output to output.html file!");

   return 0;
}