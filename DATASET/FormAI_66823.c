//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_CHARS 1000

int main() {
   char file_name[100];
   char buffer[MAX_CHARS], meta_data[MAX_LINES][MAX_CHARS];

   printf("Enter the file name: ");
   scanf("%s", file_name);

   FILE *file_ptr = fopen(file_name, "r");
   if (file_ptr == NULL) {
       printf("File does not exist");
       exit(EXIT_FAILURE);
   }

   char *line_ptr;
   int i = 0;
   while(fgets(buffer, MAX_CHARS, file_ptr)) { 
        line_ptr = strstr(buffer, "//");
        if(line_ptr != NULL) {
            strcpy(meta_data[i++], line_ptr+2);
        }
   }

   printf("Meta Data Extracted:\n");
   for(int j=0; j<i; j++) {
        printf("%s", meta_data[j]);
   }

   fclose(file_ptr);
   return 0;
}