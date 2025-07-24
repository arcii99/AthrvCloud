//FormAI DATASET v1.0 Category: Log analysis ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main() {
   FILE *fp;
   char ch;
   int characters = 0, lines = 0, words = 0;

   fp = fopen("log_file.txt", "r");

   if (fp == NULL) {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }

   while ((ch = fgetc(fp)) != EOF) {
      characters++;

      if (ch == '\n' || ch == '\0') {
         lines++;
      }

      if (ch == ' ' || ch == '\n' || ch == '\t' || ch == '\0') {
         words++;
      }
   }

   printf("Total characters: %d\n", characters);
   printf("Total lines: %d\n", lines);
   printf("Total words: %d\n", words);

   fclose(fp);

   return 0;
}