//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Linus Torvalds
#include <stdio.h>
 
int main() 
{
   char c, prev_c = ' ';
   int commentType = 0; // 0 for no comment, 1 for single-line comment, 2 for multi-line comment
 
   FILE *filep = fopen("test.c", "r"); // open the file
 
   if (filep == NULL) { // error if the file cannot be opened
      printf("Error opening file!");   
      return 0;
   }
 
   while ((c = fgetc(filep)) != EOF) {
      // single-line comment starts with //
      if (prev_c == '/' && c == '/') {
         commentType = 1;
      }
      // multi-line comment starts with /*
      else if (prev_c == '/' && c == '*') {
         commentType = 2;
      }
      // Check for end of multi-line comments */
      else if (prev_c == '*' && c == '/') {
         commentType = 0;
      }
      // print the characters inside the comment
      if (commentType != 0) {
         printf("%c", c);
      }
      prev_c = c;
   }
 
   fclose(filep); // close the file
 
   return 0;
}