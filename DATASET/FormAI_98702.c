//FormAI DATASET v1.0 Category: File handling ; Style: happy
#include <stdio.h>

int main() {
   FILE *filePointer = fopen("happy_file.txt", "w"); // opening file in write mode

   if (filePointer == NULL) {
      printf("Error: Unable to create file.");
      return 1;
   }

   printf("Hey there! Let's create a happy file!\n");

   fprintf(filePointer, "Creating a file fills me with joy!\n");

   printf("What makes you happy? Please share :) \n");

   char userInput[100];
   fgets(userInput, 100, stdin);

   fprintf(filePointer, "You said that %s makes you happy! That's wonderful!\n", userInput);

   fprintf(filePointer, "I am so happy to be able to write in this file!\n");

   printf("Now let's read the happy file! \n");

   fclose(filePointer);
   filePointer = fopen("happy_file.txt", "r"); // opening file in read mode

   char fileContent[200];

   while(fgets(fileContent, 200, filePointer)) {
      printf("%s", fileContent);
   }

   fclose(filePointer);

   printf("\nThe end! Thanks for creating a happy file with me!\n");

   return 0;
}