//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100

int main() {
   FILE* fp = fopen("data.csv", "r");
   if (fp == NULL) {
      printf("Cannot open file \n");
      exit(0);
   }

   char line[1024];
   char* token;
   int row = 0;
   int col = 0;
   char* data[MAX_ROWS][MAX_COLS];
   while (fgets(line, 1024, fp)) {
      col = 0;
      token = strtok(line, ",");
      while (token != NULL) {
         data[row][col] = strdup(token);
         token = strtok(NULL, ",");
         col++;
      }
      row++;
   }

   for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++)
         printf("%s\t", data[i][j]);
      printf("\n");
   }

   fclose(fp);
   return 0;
}