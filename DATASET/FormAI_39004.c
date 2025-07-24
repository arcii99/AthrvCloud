//FormAI DATASET v1.0 Category: Data recovery tool ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

int main() {
   FILE *fp;
   char ch;
   long long size = 0, i = 0;

   // Enter the filename to recover data from
   char filename[100];
   printf("Enter filename to recover data from: ");
   scanf("%s", filename);

   fp = fopen(filename, "rb");
   if (fp == NULL) {
      printf("Error opening file! Please check if the file exists.\n");
      exit(1);
   }

   // Get the size of the file
   fseek(fp, 0L, SEEK_END);
   size = ftell(fp);
   fseek(fp, 0L, SEEK_SET);

   // Allocate memory to store the recovered data
   char *data = (char *)malloc(size);

   // Read the data from the file into memory
   while ((ch = fgetc(fp)) != EOF) {
      data[i++] = ch;
   }

   // Close the file
   fclose(fp);

   // Display the recovered data
   printf("Recovered data: %s\n", data);

   // Free the allocated memory
   free(data);

   return 0;
}