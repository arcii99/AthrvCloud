//FormAI DATASET v1.0 Category: Log analysis ; Style: puzzling
#include <stdio.h>

int main() {
   char filename[100], ch;
   FILE *fp;
   int lines = 0, words = 0, chars = 0;
   printf("Enter the filename: ");
   scanf("%s", filename);
   fp = fopen(filename, "r");
   if (fp == NULL) {
      printf("Error: cannot open file %s\n", filename);
      return 1;
   }
   while ((ch = fgetc(fp)) != EOF) {
      chars++;
      if (ch == '\n') {
         lines++;
      }
      if (ch == ' ' || ch == '\n' || ch == '\t') {
         words++;
      }
   }
   if (chars > 0) {
      words++;
      lines++;
   }
   printf("Lines: %d\n", lines);
   printf("Words: %d\n", words);
   printf("Characters: %d\n", chars);
   fclose(fp);
   return 0;
}