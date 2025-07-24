//FormAI DATASET v1.0 Category: File handling ; Style: content
#include <stdio.h>

int main() {
   //Create a file pointer
   FILE *file_ptr;
   char text[100];

   //Open file in write mode
   file_ptr = fopen("example.txt", "w");

   //Check if file was opened successfully
   if (file_ptr == NULL) {
      printf("Error opening file.");
      return 1;
   }

   //Get user input
   printf("Enter text to write to file: ");
   fgets(text, sizeof(text), stdin);

   //Write input to file
   fprintf(file_ptr, "%s", text);

   //Close file
   fclose(file_ptr);

   //Open file in read mode
   file_ptr = fopen("example.txt", "r");

   //Check if file was opened successfully
   if (file_ptr == NULL) {
      printf("Error opening file.");
      return 1;
   }

   //Read and display file contents
   printf("\nFile contents:\n");
   while (fgets(text, sizeof(text), file_ptr)) {
      printf("%s", text);
   }

   //Close file
   fclose(file_ptr);

   return 0;
}