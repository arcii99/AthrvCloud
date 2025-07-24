//FormAI DATASET v1.0 Category: Word Count Tool ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
   int wordCount = 0, charCount = 0;
   char c;
   FILE *fp;

   fp = fopen("input.txt", "r"); // Replace "input.txt" with your input file name

   if(fp == NULL) {
      printf("Unable to open file.\n");
      exit(0);
   }

   while((c = fgetc(fp)) != EOF) {
      if(isalnum(c)) { // Check if character is alphanumeric
         charCount++;
      }
      if(isspace(c)) { // Check if character is whitespace
         wordCount++;
      }
   }

   fclose(fp);

   printf("Total words: %d\n", wordCount);
   printf("Total characters: %d\n", charCount);

   return 0;
}