//FormAI DATASET v1.0 Category: File handling ; Style: portable
#include <stdio.h>

int main() {
   FILE *fp;
   char data[1000];

   fp = fopen("example.txt", "r"); 
   if (fp == NULL) {
      printf("Failed to open file.\n");   
      return -1;
   }

   printf("File contents:\n");

   while (fgets(data, 1000, fp) != NULL) {
      printf("%s", data);
   }

   fclose(fp);
   return 0;
}