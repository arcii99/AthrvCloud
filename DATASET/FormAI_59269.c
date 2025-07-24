//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCHAR 1000

int main() {
   FILE *fp;
   char str[MAXCHAR];
   char* filename = "example.csv";
   char* token;

   fp = fopen(filename, "r");
   if (fp == NULL){
       printf("Could not open file %s",filename);
       return 1;
   }

   while (fgets(str, MAXCHAR, fp) != NULL){
       token = strtok(str, ",");
       while (token != NULL){
           printf("%s\n", token);
           token = strtok(NULL, ",");
       }
   }
   fclose(fp);
   return 0;
}