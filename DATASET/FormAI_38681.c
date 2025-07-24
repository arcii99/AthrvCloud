//FormAI DATASET v1.0 Category: File handling ; Style: satisfied
#include <stdio.h>

int main() {
   FILE *file_pointer;
   char file_content[100];

   // opening file in read mode
   file_pointer = fopen("example.txt", "r");

   // checking if file exists and is accessible
   if (file_pointer == NULL) {
      printf("Error opening file.\n");
      return -1;
   }

   // reading file content
   fgets(file_content, 100, file_pointer);

   // printing file content on screen
   printf("The content of the file is: %s\n", file_content);

   // closing the file
   fclose(file_pointer);

   // creating a new file
   file_pointer = fopen("newfile.txt", "w");

   // checking if file has been created successfully
   if (file_pointer == NULL) {
      printf("Error creating file.\n");
      return -1;
   }

   // writing to the new file
   fprintf(file_pointer, "This is a new file created by the program.");

   // closing the new file
   fclose(file_pointer);

   printf("New file created successfully.\n");

   return 0;
}