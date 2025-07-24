//FormAI DATASET v1.0 Category: File handling ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

int main() {
   FILE *file;
   char text[100];

   // write to file
   file = fopen("example.txt", "w");

   if (file == NULL) {
      printf("Error opening file!\n");
      exit(1);
   }

   printf("Enter text to write to file: ");
   fgets(text, sizeof(text), stdin);

   fprintf(file, "%s", text);
   fclose(file);
   printf("Text successfully written to file!\n");

   // read from file
   file = fopen("example.txt", "r");

   if (file == NULL) {
      printf("Error opening file!\n");
      exit(1);
   }

   printf("Contents of file:\n");
   while (fgets(text, sizeof(text), file) != NULL) {
      printf("%s", text);
   }

   fclose(file);
   printf("\nEnd of file.\n");

   return 0;
}