//FormAI DATASET v1.0 Category: File handling ; Style: high level of detail
#include <stdio.h>

int main() {
   FILE *fp;
   char data[50];

   // Opening file for writing
   fp = fopen("file.txt", "w");

   if (fp == NULL) {
      printf("Error opening file!\n");
      return -1;
   }

   // Writing data to file
   printf("Enter some text to write to the file: ");
   fgets(data, 50, stdin);

   fputs(data, fp);
   fclose(fp);

   // Opening file for reading
   fp = fopen("file.txt", "r");

   if (fp == NULL) {
      printf("Error opening file!\n");
      return -1;
   }

   // Reading data from file
   printf("\nThe contents of the file are:\n");
   fgets(data, 50, fp);

   printf("%s\n", data);

   fclose(fp);

   return 0;
}