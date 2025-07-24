//FormAI DATASET v1.0 Category: Log analysis ; Style: creative
#include<stdio.h>
#include<string.h>

int main() {
   char file[50] = "access.log";
   FILE *fp;
   char str[100];
   int GET_count = 0, POST_count = 0, num_of_lines = 0;
   fp = fopen(file, "r");

   if(fp == NULL) {
      printf("\nCould not open file %s\n", file);
      return 1;
   }

   while(fgets(str, 100, fp)) {
       num_of_lines++;

        if(strstr(str, "GET")) {
          GET_count++;
        } else if(strstr(str, "POST")) {
          POST_count++;
        } 

   }

   printf("\nNumber of GET requests: %d", GET_count);
   printf("\nNumber of POST requests: %d", POST_count);
   printf("\nTotal number of lines: %d", num_of_lines);

   fclose(fp);
   return 0;
}