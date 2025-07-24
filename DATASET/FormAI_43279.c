//FormAI DATASET v1.0 Category: Log analysis ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[]) {
   FILE *fp;
   char *line = NULL;
   size_t len = 0;
   ssize_t read;
   char *search = argv[1];

   if (argc < 3) {
       printf("Usage: ./log_analyzer search_string logfile.log\n");
       return 1;
   }

   fp = fopen(argv[2], "r");
   if (fp == NULL) {
       printf("Error opening file %s\n", argv[2]);
       return 1;
   }

   int count=0;
   while ((read = getline(&line, &len, fp)) != -1) {
       if (strstr(line, search) != NULL) {
           count++;
       }
   }

   printf("The search string %s appeared %d times in the log file.\n", search, count);

   fclose(fp);
   if (line) {
       free(line);
   }
   
   return 0;
}