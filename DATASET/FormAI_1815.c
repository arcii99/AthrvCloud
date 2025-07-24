//FormAI DATASET v1.0 Category: Log analysis ; Style: satisfied
#include <stdio.h>

int main() {
   FILE *file;
   char file_name[100], line[100];
   int i = 1, total_errors = 0;

   printf("Enter the file name to be analyzed: ");
   scanf("%s", file_name);

   file = fopen(file_name, "r");
   
   if (file == NULL) {
      printf("File %s does not exist\n", file_name);
      return 0;
   }

   printf("\n------------------ LOG ANALYSIS ------------------\n");

   while (fgets(line, sizeof(line), file)) {
      if (strstr(line, "ERROR")) {
         printf("Line %d: %s", i, line);
         total_errors++;
      }
      i++;
   }

   printf("\n--------------------------------------------------\n");
   fclose(file);

   printf("Total number of errors: %d\n", total_errors);

   return 0;
}