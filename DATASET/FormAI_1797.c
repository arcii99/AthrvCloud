//FormAI DATASET v1.0 Category: Data recovery tool ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

int main() {
   FILE *fp;
   char *filename;
   int filesize;

   filename = (char *)malloc(sizeof(char)*100); // Allocate memory for filename

   printf("Enter the name of the file to recover: ");
   scanf("%s",filename);
   
   fp = fopen(filename,"rb"); // Open file for binary read

   if(fp == NULL) { // Check if file exists
      printf("File not found.\n");
      exit(0);
   }

   fseek(fp,0,SEEK_END); // Move file pointer to the end of file
   filesize = ftell(fp); // Get file size
   fseek(fp,0,SEEK_SET); // Move file pointer back to the begining

   char *buffer = (char *)malloc(sizeof(char)*filesize); // Allocate buffer to store data
   fread(buffer,1,filesize,fp); // Read data from file

   printf("Data recovered successfully: \n%s\n",buffer);

   fclose(fp); // Close file
   free(buffer); // Free buffer memory
   free(filename); // Free filename memory

   return 0;
}