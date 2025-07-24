//FormAI DATASET v1.0 Category: Log analysis ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
   // Opening the file for reading
   FILE *fp;
   char *line = NULL;
   size_t len = 0;
   ssize_t read;
   fp = fopen(argv[1], "r");
   if (fp == NULL) {
      printf("Error opening file");
      return 1;
   }

   // Reading each line of the file
   int count = 0;
   while ((read = getline(&line, &len, fp)) != -1) {
       count++;
       printf("Line %d: %s", count, line);
   }

   // Closing the file and freeing memory
   fclose(fp);
   if (line) {
       free(line);
   }
   return 0;
}