//FormAI DATASET v1.0 Category: File Encyptor ; Style: shocked
#include <stdio.h>
#include <string.h>

#define MAX_FILE_LEN 10000

int main()
{
   char file_name[50], key[50]; // variables for file name and encryption key
   FILE *file;  // File pointer (handles input and output files)
   char file_buffer[MAX_FILE_LEN]; // A buffer to hold the input file contents
   int file_len; // Length of the input file

   printf("Enter the file name to encrypt: \n");
   scanf("%s", file_name);
   printf("Enter the encryption key: \n");
   scanf("%s", key);

   // Open the input file and read its contents to a buffer
   file = fopen(file_name, "rb");
   if (!file)
   {
        printf("Failed to open %s for reading.", file_name);
        exit(1);
   }
   file_len = fread(file_buffer, sizeof(char), MAX_FILE_LEN, file);
   fclose(file);

   // Encrypt the file contents using the provided encryption key
   for(int i = 0; i < file_len; i++){
        file_buffer[i] ^= key[i % strlen(key)]; 
   }

   // Write the encrypted file contents back to the same file name
   file = fopen(file_name, "wb");
   if (!file)
   {
        printf("Failed to open %s for writing.", file_name);
        exit(1);
   }
   fwrite(file_buffer, sizeof(char), file_len, file);
   fclose(file);

   printf("The file %s has been successfully encrypted!\n", file_name);

   return 0;
}