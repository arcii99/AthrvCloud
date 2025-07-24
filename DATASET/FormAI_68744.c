//FormAI DATASET v1.0 Category: Error handling ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

void errorHandler(int errorCode) {
   switch(errorCode) {
      case 0:
         printf("No Error\n");
         break;
      case 1:
         printf("Error: File not found\n");
         exit(0);
         break;
      case 2:
         printf("Error: Memory allocation failed\n");
         exit(0);
         break;
      default:
         printf("Unknown Error\n");
         exit(0);
         break;
   }
}

int main() {
   FILE *fp;
   char *buffer;

   fp = fopen("input.txt", "r");

   if(fp == NULL) {
      errorHandler(1);
   }

   buffer = (char*) malloc(1000 * sizeof(char));

   if(buffer == NULL) {
      errorHandler(2);
   }

   fclose(fp);
   free(buffer);

   errorHandler(0);

   return 0;
}