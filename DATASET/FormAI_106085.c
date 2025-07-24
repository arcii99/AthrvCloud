//FormAI DATASET v1.0 Category: File handling ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

int main() {
   FILE *filePointer;

   char fileContent[50][100];

   filePointer = fopen("grateful.txt", "r");

   if (filePointer == NULL) {
      printf("Cannot open file \n");
      exit(0);
   }

   int lineCount = 0;
   while(fgets(fileContent[lineCount], 100, filePointer)) {
      lineCount++;
   };

   fclose(filePointer);

   // Writing to the file
   char *grateful[] = {"I am grateful for this code project",
                       "I am grateful for the opportunity to learn",
                       "I am grateful for my family",
                       "I am grateful for the beauty in nature",
                       "I am grateful for my health",
                       "I am grateful for my friends",
                       "I am grateful for the ability to create"};

   filePointer = fopen("grateful.txt", "w");

   for (int i = 0; i < sizeof(grateful)/sizeof(*grateful); i++) {
      fputs(grateful[i], filePointer);
      fputs("\n", filePointer);
   }

   fclose(filePointer);

   // Read and display the contents of the file on terminal
   filePointer = fopen("grateful.txt", "r");
   lineCount = 0;

   while(fgets(fileContent[lineCount], 100, filePointer)) {
      printf("%s", fileContent[lineCount]);
      lineCount++;
   };

   fclose(filePointer);

   return 0;
}