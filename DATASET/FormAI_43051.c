//FormAI DATASET v1.0 Category: Compression algorithms ; Style: shocked
#include <stdio.h>

int main() {
   printf("Wait, what?! A unique C Compression algorithm?!\n");
   printf("I wasn't prepared for this!\n");
   printf("But hey, challenge accepted!\n\n");
   
   char input[] = "This is a test string to be compressed.";
   int length = strlen(input);
   
   printf("Original string: %s\n", input);
   printf("Length before compression: %d\n\n", length);
   
   char output[length];
   int index = 0;
   char current = input[0];
   int count = 1;
   
   for (int i = 1; i < length; i++) {
      if (input[i] == current) {
         count++;
      } else {
         output[index++] = current;
         output[index++] = count + '0';
         current = input[i];
         count = 1;
      }
   }
   
   output[index++] = current;
   output[index++] = count + '0'; // converting integer count to character using ASCII code
   
   printf("Compressed string: %s\n", output);
   printf("Length after compression: %d\n", strlen(output));
   
   printf("\nPhew! That was intense... I actually did it!\n");
   
   return 0;
}