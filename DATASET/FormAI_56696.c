//FormAI DATASET v1.0 Category: File Backup System ; Style: high level of detail
#include <stdio.h>
#include <string.h>

int main()
{
   FILE *file1, *file2;
   char source[100], destination[100], buffer[1024];

   printf("Enter source file path: ");
   scanf("%s", source);

   printf("Enter destination file path: ");
   scanf("%s", destination);

   file1 = fopen(source, "rb");
   file2 = fopen(destination, "wb");

   if (file1 == NULL) {
       printf("Error: Unable to open source file %s.\n", source);
       return 1;
   }

   if (file2 == NULL) {
       printf("Error: Unable to open destination file %s.\n", destination);
       return 1;
   }

   while (fgets(buffer, sizeof(buffer), file1)) {
       fputs(buffer, file2);
   }

   printf("%s copied successfully to %s.\n", source, destination);

   fclose(file1);
   fclose(file2);

   return 0;
}