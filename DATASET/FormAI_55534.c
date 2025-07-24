//FormAI DATASET v1.0 Category: Text processing ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 void removeComments(char input_file[], char output_file[]) {
   FILE* input_fp = fopen(input_file, "r");
   FILE* output_fp = fopen(output_file,"w");
   char curr = fgetc(input_fp);
   char next = fgetc(input_fp);

   while(curr != EOF) {
     if(curr == '/') {
       if(next == '/') {
         while(curr != '\n') {
           curr = next;
           next = fgetc(input_fp);
         }
         curr = next;
         next = fgetc(input_fp);
       }
       else if(next == '*') {
         curr = fgetc(input_fp);
         next = fgetc(input_fp);
         while(curr != '*' && next != '/') {
           curr = next;
           next = fgetc(input_fp);
         }
         curr = fgetc(input_fp);
         next = fgetc(input_fp);
       }
       else {
         fputc(curr, output_fp);
         curr = next;
         next = fgetc(input_fp);
       }
     }
     else {
       fputc(curr, output_fp);
       curr = next;
       next = fgetc(input_fp);
     }
   }
   fclose(input_fp);
   fclose(output_fp);
 }

int main() {
   char input_file[] = "input_file.txt";
   char output_file[] = "output_file.txt";
   removeComments(input_file, output_file);
   printf("Comments removed successfully!");
   return 0;
 }