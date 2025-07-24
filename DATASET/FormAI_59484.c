//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
   FILE *fptr;
   int row = 0, col = 0;
   char filename[50], buffer[1024];

   printf("\nWelcome to the CSV Reader!\n\n");
   printf("Please enter the file name: ");
   scanf("%s", &filename);

   fptr = fopen(filename, "r");

   if (fptr != NULL) {
       printf("\nOpening file...\n");
       while (fgets(buffer, 1024, fptr)) {
           col = 0;
           row++;
           char* value = strtok(buffer, ",");   // Use strtok to read until a comma is found
           while (value) {
               if (col == 0) {
                   printf("\nIn row#%d, Column#%d, Corrupted data -> %s", row, col, value);
               }
               else {
                   printf("\nIn row#%d, Column#%d, Data -> %s", row, col, value);
               }
               value = strtok(NULL, ",");
               col++;
           }
       }
       printf("\n\nFinished reading the file.\nThe CSV reader program by Mr. Bot has successfully read the file. ");
       fclose(fptr);
   } else {
       printf("Error opening the file! The CSV reader program by Mr. Bot could not read the file!");
   }
   return 0;
}