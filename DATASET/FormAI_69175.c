//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: visionary
#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

int main() {
   char filename[MAX_LEN];
   printf("Enter the name of the CSV file: ");
   scanf("%s", filename);

   FILE* fp = fopen(filename, "r");
   if (fp == NULL) {
      printf("Error opening the file\n");
      return 1;
   }

   char line[MAX_LEN];
   while (fgets(line, MAX_LEN, fp) != NULL) {
      char* token = strtok(line, ",");
      while (token != NULL) {
         printf("%s\n", token);
         token = strtok(NULL, ",");
      }
   }

   fclose(fp);
   return 0;
}