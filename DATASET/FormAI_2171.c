//FormAI DATASET v1.0 Category: Compression algorithms ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Main program starts here
int main() {
   char uncompressed_data[100] = "this is some uncompressed data";
   printf("Uncompressed data: %s\n", uncompressed_data);

   char compressed_data[100] = "";

   int count = 1;
   char current_char = uncompressed_data[0];

   // Loop through each character in the uncompressed data
   for (int i = 1; i < strlen(uncompressed_data); i++) {

      // If the current character is the same as the previous one, increment the count
      if (uncompressed_data[i] == current_char) {
         count++;
      } 
      // If they're not the same, add the current character and count to the compressed data string
      else {
         char count_str[10];
         sprintf(count_str, "%d", count);
         strcat(compressed_data, count_str);
         strcat(compressed_data, &current_char);
         current_char = uncompressed_data[i];
         count = 1;
      }
   }

   // Add the last character and count to the compressed data string
   char count_str[10];
   sprintf(count_str, "%d", count);
   strcat(compressed_data, count_str);
   strcat(compressed_data, &current_char);

   printf("Compressed data: %s\n", compressed_data);

   return 0;
}