//FormAI DATASET v1.0 Category: File Backup System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 256
#define MAX_FILE_SIZE 1048576

int main(void) {
   char filename[MAX_FILENAME_LEN], backup_filename[MAX_FILENAME_LEN];
   char file_data[MAX_FILE_SIZE];
   FILE *fp, *backup_fp;
   long file_size;
   int i;

   /* prompt user for filename and open file */
   printf("Enter filename to backup: ");
   fgets(filename, MAX_FILENAME_LEN, stdin);
   filename[strcspn(filename, "\n")] = '\0';  /* remove newline character */
   fp = fopen(filename, "r");

   /* check if file exists */
   if (fp == NULL) {
      printf("Could not open file. Exiting...\n");
      exit(EXIT_FAILURE);
   }

   /* read file contents into buffer */
   fseek(fp, 0L, SEEK_END);
   file_size = ftell(fp);
   rewind(fp);
   fread(file_data, file_size, 1, fp);

   /* close original file */
   fclose(fp);

   /* prompt user for backup filename and create backup file */
   printf("Enter backup filename: ");
   fgets(backup_filename, MAX_FILENAME_LEN, stdin);
   backup_filename[strcspn(backup_filename, "\n")] = '\0';  /* remove newline character */
   backup_fp = fopen(backup_filename, "w");

   /* write file contents to backup file */
   fwrite(file_data, file_size, 1, backup_fp);

   /* close backup file */
   fclose(backup_fp);

   /* print confirmation message */
   printf("File backed up successfully.\n");

   return 0;
}