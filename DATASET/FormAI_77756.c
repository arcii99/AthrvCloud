//FormAI DATASET v1.0 Category: File handling ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

int main() {
   FILE *filePointer;
   char content[50];

   filePointer = fopen("example.txt", "w");

   if(filePointer != NULL) {
      fputs("This is an example sentence.\n", filePointer);
      fputs("This is another example sentence.\n", filePointer);
      fputs("This is the last example sentence.", filePointer);
      fclose(filePointer);
      printf("The data was written to the file.\n\n");
   }

   filePointer = fopen("example.txt", "r");

   if(filePointer != NULL) {
      while(fgets(content, 50, filePointer)) {
         printf("%s", content);
      }
      fclose(filePointer);
   }

   return 0;
}