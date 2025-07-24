//FormAI DATASET v1.0 Category: File handling ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>

int main()
{
   //creating file pointer to read and write files
   FILE *filePointer;

   //opening new file for writing binary data
   filePointer = fopen("newData.bin", "wb");

   //writing binary data to the file
   char data[] = "Hello World";
   fwrite(&data, sizeof(data), 1, filePointer);

   //closing the file pointer
   fclose(filePointer);

   //opening the same file for reading binary data
   filePointer = fopen("newData.bin", "rb");

   //reading binary data from the file and printing it
   char readData[11];
   fread(&readData, sizeof(readData), 1, filePointer);
   printf("Data read from file: %s\n", readData);

   //closing file pointer
   fclose(filePointer);

   //deleting the file
   if (remove("newData.bin") == 0)
      printf("File deleted successfully.\n");
   else
      printf("Error deleting file.\n");

   return 0;
}