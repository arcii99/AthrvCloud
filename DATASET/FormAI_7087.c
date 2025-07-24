//FormAI DATASET v1.0 Category: HTML beautifier ; Style: all-encompassing
#include <stdio.h>
#include <stdbool.h>

// Function to check if the character is a whitespace
bool is_whitespace(char c) {
   if (c == ' ' || c == '\t' || c == '\n')
      return true;
   return false;
}

// Function to output a whitespace character
void output_space(bool* space) {
   if (!(*space)) {
      printf(" ");
      *space = true;
   }
}

int main() {
   // Open the input file for reading
   FILE* input_file = fopen("input.html", "r");

   // Open the output file for writing
   FILE* output_file = fopen("output.html", "w");

   // Initialize the state variables
   bool inside_tag = false;
   bool space = false;

   // Process each character in the input file
   char c = fgetc(input_file);
   while (c != EOF) {
      // Determine if we are inside a tag
      if (c == '<') {
         inside_tag = true;
         output_space(&space);
      } else if (c == '>') {
         inside_tag = false;
      }

      // Output the character
      if (inside_tag) {
         printf("%c", c);
      } else {
         if (!is_whitespace(c)) {
            output_space(&space);
            printf("%c", c);
         }
      }

      // Read the next character from the input file
      c = fgetc(input_file);
   }

   // Close the input and output files
   fclose(input_file);
   fclose(output_file);

   return 0;
}