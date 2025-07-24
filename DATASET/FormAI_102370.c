//FormAI DATASET v1.0 Category: File handling ; Style: immersive
#include <stdio.h>

int main() {
   char fileName[50];
   FILE *filePointer;
   int character;
   
   printf("Welcome to File Reader 3000!\n\n");
   printf("Please enter the name of the file you would like to read:\n");
   gets(fileName);
   
   filePointer = fopen(fileName, "r");
   
   if (filePointer == NULL) {
      printf("Error! File not found.\n");
      return -1;
   }
   
   printf("\nThe contents of the file are:\n\n");
   
   while ((character = fgetc(filePointer)) != EOF) {
      printf("%c", character);
   }
   
   fclose(filePointer);
   
   printf("\n\nThank you for using File Reader 3000!");
   
   return 0;
}