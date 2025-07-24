//FormAI DATASET v1.0 Category: Error handling ; Style: complete
#include<stdio.h>
#include<stdlib.h> 

int main() {
   FILE *fp;
   int num;

   fp = fopen("input.txt", "r");
   if(fp == NULL) {
      printf("Error: File not found");
      exit(1);
   }

   fscanf(fp, "%d", &num);
   if(ferror(fp)) {
      printf("Error reading file");
      exit(1);
   }

   if(num > 100) {
      printf("Error: Number exceeds limit");
      exit(1);
   }

   printf("Number read from file: %d", num);

   fclose(fp);

   return 0;
}