//FormAI DATASET v1.0 Category: Text processing ; Style: minimalist
#include <stdio.h>
#include <string.h>

int main() {
   // Initialize variables
   char input_string[100], output_string[100];
   int string_length, i, vowels_count = 0;

   // Get input from user
   printf("Enter a string: ");
   fgets(input_string, 100, stdin);

   // Remove newline character from input string
   input_string[strcspn(input_string, "\n")] = 0;

   // Calculate and store string length
   string_length = strlen(input_string);

   // Convert all characters to lowercase and count vowels
   for (i = 0; i < string_length; i++) {
      // Convert character to lowercase
      if (input_string[i] >= 'A' && input_string[i] <= 'Z') {
         input_string[i] += ('a' - 'A');
      }
      // Check if character is a vowel
      if (input_string[i] == 'a' || input_string[i] == 'e' || input_string[i] == 'i' || input_string[i] == 'o' || input_string[i] == 'u') {
         vowels_count++;
      }
   }

   // Copy input string to output string in reverse order
   for (i = 0; i < string_length; i++) {
      output_string[i] = input_string[string_length - i - 1];
   }

   // Print output
   printf("Input string: %s\n", input_string);
   printf("Output string (reversed): %s\n", output_string);
   printf("Number of vowels in input string: %d\n", vowels_count);

   return 0;
}