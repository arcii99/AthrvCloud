//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: lively
#include <stdio.h>
#include <string.h>

int main () {
   // Declare variables
   char metadata[] = "/* Program Name: Metadata Extractor\n Author: Jane Doe\n Description: Extracts metadata from C programs\n */";
   char program_name[50];
   char author[50];
   char description[100];

   // Extract program name
   char* start = strstr(metadata, "Program Name:");
   char* end = strstr(start, "\n");
   int length = end - (start + 14);
   strncpy(program_name, start + 14, length);
   program_name[length] = '\0';

   // Extract author
   start = strstr(metadata, "Author:");
   end = strstr(start, "\n");
   length = end - (start + 7);
   strncpy(author, start + 7, length);
   author[length] = '\0';

   // Extract description
   start = strstr(metadata, "Description:");
   end = strstr(start, "\n");
   length = end - (start + 12);
   strncpy(description, start + 12, length);
   description[length] = '\0';

   // Print extracted metadata
   printf("Program Name: %s\n", program_name);
   printf("Author: %s\n", author);
   printf("Description: %s\n", description);
   
   return 0;
}