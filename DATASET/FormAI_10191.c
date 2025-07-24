//FormAI DATASET v1.0 Category: Log analysis ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUF_SIZE 512

// function to convert a string to lowercase
void strtolower(char* str) {
   for(int i = 0; str[i]; i++) {
      str[i] = tolower(str[i]);
   }
}

int main() {
   char* log_file_name = "logfile.txt";
   char* search_term = "ERROR";
   
   // open the log file for reading
   FILE* log_file = fopen(log_file_name, "r");
   
   if(log_file == NULL) {
      printf("Error opening file %s\n", log_file_name);
      exit(-1);
   }
   
   char buf[BUF_SIZE];
   int line_number = 0;
   int search_count = 0;
   
   // read each line of the log file
   while(fgets(buf, BUF_SIZE, log_file) != NULL) {
      line_number++;
      char* ptr = strstr(buf, search_term);
      
      if(ptr != NULL) {
         search_count++;
         // convert the line to lowercase so the search is case-insensitive
         strtolower(buf);
         printf("Line %d: %s\n", line_number, buf);
      }
   }
   
   // close the log file
   fclose(log_file);
   
   printf("Found %d instances of '%s' in %s\n", search_count, search_term, log_file_name);
   
   return 0;
}