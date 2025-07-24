//FormAI DATASET v1.0 Category: Log analysis ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_MAX 500              /* maximum number of characters per log line */
#define SEARCH_TERM_MAX 50        /* maximum number of characters per search term */
#define LOG_FILE "example.log"    /* name of example file to parse */

int main()
{
   char search_term[SEARCH_TERM_MAX];
   printf("Enter a search term: ");
   scanf("%s", search_term);

   FILE *fp;
   char line[LINE_MAX];
   int line_num = 0;
   int matching_lines = 0;

   fp = fopen(LOG_FILE, "r");
   if (fp == NULL) {
      printf("Error opening file '%s'\n", LOG_FILE);
      exit(EXIT_FAILURE);
   }

   printf("\nLines containing '%s':\n", search_term);

   while (fgets(line, LINE_MAX, fp)) {
      line_num++;
      if (strstr(line, search_term) != NULL) {
         matching_lines++;
         printf("Line %d: %s", line_num, line);
      }
   }

   if (matching_lines == 0)
      printf("\nNo matches found\n");

   fclose(fp);
   return 0;
}