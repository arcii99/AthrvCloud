//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Alan Touring
// Alan Turing-style checksum calculator example program in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the input string
#define MAX_LENGTH 1000

// Define the checksum function
int getChecksum(char *str) {
   int i, checksum = 0;

   // Loop through each character in the input string
   for(i = 0; i < strlen(str); i++) {

      // Add the ASCII code of the current character to the checksum value
      checksum += (int)str[i];
   }

   // Return the final checksum value
   return checksum;
}

int main() {
   char input[MAX_LENGTH];
   int checksum;

   // Prompt the user to enter a string
   printf("Enter a string to calculate the checksum: ");
   fgets(input, MAX_LENGTH, stdin);

   // Remove the newline character from the input string
   input[strcspn(input, "\n")] = 0;

   // Calculate the checksum
   checksum = getChecksum(input);

   // Display the checksum value
   printf("The checksum of the input string is: %d\n", checksum);

   return 0;
}