//FormAI DATASET v1.0 Category: Log analysis ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>

int main() {
   FILE *fp;
   char ch;
   int noc = 0, nost = 0, nol = 0, now = 0;

   fp = fopen("sample.log","r"); 

   if(fp == NULL) {
      printf("File does not exist!\n");
      exit(0);
   }

   while((ch = fgetc(fp)) != EOF) {
      noc++; // Counting number of characters

      if(ch == ' ') // Counting number of spaces
         nost++;

      if(ch == '\n') // Counting number of lines
         nol++;

      if((ch == ' ' || ch == '\n') && now == 1) // Counting number of words
         now = 0;

      else if(ch != ' ' && ch != '\n')
         now = 1;

         }
   fclose(fp);

   printf("\nTotal number of characters: %d", noc);
   printf("\nTotal number of spaces: %d", nost);
   printf("\nTotal number of lines: %d", nol);
   printf("\nTotal number of words: %d", nol);

   return 0;
}