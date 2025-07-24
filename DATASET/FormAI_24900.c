//FormAI DATASET v1.0 Category: File handling ; Style: imaginative
#include <stdio.h>

int main() {
   FILE *filePointer;
   char dataToBeWritten[50] = "Hello, this is an example file handling program!";
   
   filePointer = fopen("example.txt", "w");
   
   if (filePointer == NULL) {
      printf("Failed to open the file.\n");
   }
   else {
      printf("The file is now opened.\n");
      if (strlen(dataToBeWritten) > 0) {
         fputs(dataToBeWritten, filePointer);
         fputs("\n", filePointer);
      }
      fclose(filePointer);
      printf("Data has been written to the file successfully.\n");
      printf("Opening the file once again to read the data from it.\n");
      filePointer = fopen("example.txt", "r");
      if (filePointer == NULL) {
         printf("Failed to open the file.\n");
      }
      else {
         printf("The file is now opened.\n");
         char fileContent[200];
         while (fgets(fileContent, 200, filePointer) != NULL)
            printf("%s", fileContent);
         fclose(filePointer);
         printf("\nData has been read from the file successfully.\n");
         printf("Deleting the example file.\n");
         int status = remove("example.txt");
         if (status == 0)
            printf("The file has been deleted successfully.\n");
         else
            printf("Unable to delete the file.\n");
      }
   }
   return 0;
}