//FormAI DATASET v1.0 Category: File Encyptor ; Style: curious
#include <stdio.h>
#include <stdlib.h>

void main()
{
   char filepath[100], password[20];
   long int size;
   FILE *fp;

   printf("Enter the file path: ");
   scanf("%s", filepath);

   fp = fopen(filepath, "rb"); // Open file in binary mode

   if (fp == NULL)
   {
      printf("Error: Cannot open file!");
      exit(1);
   }

   fseek(fp, 0, SEEK_END); // Seek to end of file
   size = ftell(fp); // Get current position (size of file)
   fseek(fp, 0, SEEK_SET); // Seek back to beginning of file

   printf("Enter the password: ");
   scanf("%s", password);

   // Encrypt file with password
   for (int i = 0; i < size; i++)
   {
      char byte = fgetc(fp);
      byte = byte ^ password[i % strlen(password)];
      fseek(fp, -1, SEEK_CUR);
      fputc(byte, fp);
   }

   fclose(fp);
   printf("File encrypted successfully!");
}