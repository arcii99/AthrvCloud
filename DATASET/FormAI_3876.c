//FormAI DATASET v1.0 Category: String manipulation ; Style: mathematical
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to convert a string to all uppercase
void string_to_upper(char *str) {
   while (*str) {
      *str = toupper((unsigned char) *str);
      str++;
   }
}

int main() {
   char input_str[1024];
   printf("Enter a string: ");
   scanf("%[^\n]", input_str);
   getchar(); // clear input buffer

   // convert string to uppercase
   string_to_upper(input_str);

   printf("\n");

   // perform various mathematical operations on the string
   int str_len = strlen(input_str);
   int num_vowels = 0;
   int num_consonants = 0;
   int num_digits = 0;
   int num_spaces = 0;

   for (int i = 0; i < str_len; i++) {
      // count vowels
      if (input_str[i] == 'A' || input_str[i] == 'E' || input_str[i] == 'I' || input_str[i] == 'O' || input_str[i] == 'U') {
         num_vowels++;
      }

      // count consonants
      if ((input_str[i] >= 'B' && input_str[i] <= 'D') || (input_str[i] >= 'F' && input_str[i] <= 'H') ||
          (input_str[i] >= 'J' && input_str[i] <= 'N') || (input_str[i] >= 'P' && input_str[i] <= 'T') ||
          (input_str[i] >= 'V' && input_str[i] <= 'Z')) {
         num_consonants++;
      }

      // count digits
      if (isdigit(input_str[i])) {
         num_digits++;
      }

      // count spaces
      if (isspace(input_str[i])) {
         num_spaces++;
      }
   }

   int total_chars = num_vowels + num_consonants;
   float vowel_percentage = ((float)num_vowels / (float)total_chars) * 100;
   float consonant_percentage = ((float)num_consonants / (float)total_chars) * 100;

   printf("Statistics for string: %s\n", input_str);
   printf("Number of characters: %d\n", total_chars);
   printf("Number of vowels: %d (%.2f%%)\n", num_vowels, vowel_percentage);
   printf("Number of consonants: %d (%.2f%%)\n", num_consonants, consonant_percentage);
   printf("Number of digits: %d\n", num_digits);
   printf("Number of spaces: %d\n", num_spaces);

   return 0;
}