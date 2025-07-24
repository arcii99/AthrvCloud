//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: innovative
#include <stdio.h>

int main() {
   // Define variables
   char input[100];
   int checksum = 0;
   int i;
   
   // Get input from the user
   printf("Enter input: ");
   fgets(input, sizeof(input), stdin);
   
   // Calculate the checksum
   for(i = 0; input[i] != '\0'; i++) {
      checksum ^= (int)input[i];
   }
   
   // Print the result
   printf("Checksum: %d", checksum);
   
   return 0;
}