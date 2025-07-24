//FormAI DATASET v1.0 Category: File handling ; Style: brave
#include <stdio.h>
#include <stdlib.h>

int main() {
   FILE *fptr;
   char ch;

   // open the file in read mode
   fptr = fopen("file.txt", "r");

   if (fptr == NULL) {
      printf("Error opening the file.\n");
      exit(0);
   }

   // read the file character by character
   ch = fgetc(fptr);
   while (ch != EOF) {
      printf("%c", ch);
      ch = fgetc(fptr);
   }

   fclose(fptr);

   // ask the user for input and append it to the file
   char input[100];
   printf("\nEnter some text to append to the file: ");
   fgets(input, 100, stdin);

   fptr = fopen("file.txt", "a");

   if (fptr == NULL) {
      printf("Error opening the file.\n");
      exit(0);
   }

   fprintf(fptr, "\n%s", input);
   fclose(fptr);

   printf("\nText appended to the file successfully.");

   return 0;
}