//FormAI DATASET v1.0 Category: File Backup System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

int main() {
   char ch, source_file[20], target_file[20];
   FILE *source, *target;
 
   printf("Enter name of file to copy\n");
   gets(source_file);

   source = fopen(source_file, "r");
 
   if (source == NULL) {
      printf("Source file not found\n");
      exit(EXIT_FAILURE);
   }
 
   printf("Enter name of target file\n");
   gets(target_file);
 
   target = fopen(target_file, "w");
 
   if (target == NULL) {
      fclose(source);
      printf("Target file could not be created\n");
      exit(EXIT_FAILURE);
   }
 
   while ((ch = fgetc(source)) != EOF)
      fputc(ch, target);
 
   printf("File copied successfully.\n");
 
   fclose(source);
   fclose(target);
 
   return 0;
}