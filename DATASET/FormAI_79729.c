//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000
#define MAX_FIELDS 10

int countFields(char *line, char *delimiter) {
   int count = 0;
   char *token = strtok(line, delimiter);
   while (token != NULL && count < MAX_FIELDS) {
      count++;
      token = strtok(NULL, delimiter);
   }
   return count;
}

int main() {

   FILE *fp;
   char line[MAX_LINE_SIZE];
   char *field[MAX_FIELDS];
   int numFields;

   fp = fopen("data.csv", "r");
   if (fp == NULL) {
      printf("Error opening file.\n");
      exit(EXIT_FAILURE);
   }

   // Read and print header line
   fgets(line, MAX_LINE_SIZE, fp);
   printf("HEADER: %s", line);

   // Read and print data lines
   while (fgets(line, MAX_LINE_SIZE, fp)) {

      // Parse line into fields
      numFields = countFields(line, ",");
      field[0] = strtok(line, ",");
      for (int i = 1; i < numFields; i++) {
         field[i] = strtok(NULL, ",");
      }

      // Print fields
      for (int i = 0; i < numFields; i++) {
         printf("%s,", field[i]);
      }
      printf("\n");
   }

   fclose(fp);
   return 0;
}