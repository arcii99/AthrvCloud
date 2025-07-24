//FormAI DATASET v1.0 Category: File handling ; Style: minimalist
#include <stdio.h>

int main() {
   FILE *fp;
   char str[60];
  
   // Writing to a file
   fp = fopen("outFile.txt", "w");
  
   if(fp == NULL) {
      printf("File could not be opened or does not exist.\n");
      return -1;
   }
  
   fprintf(fp, "Hello world! I am a minimalist C program for file handling.\n");
   fputs("This is another line of text.", fp);
  
   fclose(fp);
  
   // Reading from a file
   fp = fopen("outFile.txt", "r");
  
   if(fp == NULL) {
      printf("File could not be opened or does not exist.\n");
      return -1;
   }
  
   while(fgets(str, sizeof(str), fp) != NULL) {
      printf("%s", str);
   }
  
   fclose(fp);
  
   return 0;
}