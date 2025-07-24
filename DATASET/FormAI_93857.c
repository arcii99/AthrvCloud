//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: complete
#include <stdio.h>

int main() {
   char input[80]; // Input string
   int i, j; // Loop iterators
   printf("Enter a string (max 80 chars): ");
   fgets(input, 80, stdin); // Read input from user
   for (i = 0; i < strlen(input); i++) { // Loop through all characters in input
      int ascii = (int)input[i]; // Get ASCII code of current character
      for (j = 0; j < 8; j++) { // Loop through all 8 bits of the ASCII code
         if (ascii & 0x80) { // Current bit is a 1
            printf("*"); // Print asterisk
         } else { // Current bit is a 0
            printf(" "); // Print space
         }
         ascii <<= 1; // Shift the bits to the left by 1
      }
      printf("\n"); // Move to the next line
   }
   return 0;
}