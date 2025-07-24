//FormAI DATASET v1.0 Category: Data recovery tool ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

int main() {
   FILE *fptr;
   char path[100];
   char ch;

   printf("Enter the path of the file to be recovered: ");
   scanf("%s", path);

   fptr = fopen(path, "r");

   if (fptr == NULL) {
      printf("Error: Unable to open the file.\n");
      exit(1);
   }

   printf("The original data in the file:\n\n");
   while ((ch = fgetc(fptr)) != EOF) {
      printf("%c", ch);
   }

   fclose(fptr);

   printf("\nCopying the data to a new file...\n");

   fptr = fopen("recovered_data.txt", "w");

   if (fptr == NULL) {
      printf("Error: Unable to create a new file.\n");
      exit(1);
   }

   fptr = fopen(path, "r");

   while ((ch = fgetc(fptr)) != EOF) {
      fputc(ch, fptr);
   }

   fclose(fptr);

   printf("\nThe data has been successfully recovered and copied to the file 'recovered_data.txt'.\n");

   return 0;
}