//FormAI DATASET v1.0 Category: Ebook reader ; Style: complete
#include<stdio.h>

// function to read the ebook file
void readEbook(char fileName[]) {
   FILE *file;

   // opening the ebook file
   file = fopen(fileName, "r");
   
   if (file == NULL) {
      printf("Error in opening file %s\n", fileName);
      return;
   }
   
   // reading the ebook content from the file
   char ch;
   while ((ch = fgetc(file)) != EOF)
      printf("%c", ch);

   // closing the file
   fclose(file);
}

int main() {
   char fileName[100];

   // Get filename from user
   printf("Enter the filename of the ebook:");
   scanf("%s", fileName);

   // call readEbook function to read and display ebook content
   readEbook(fileName);

   return 0;
}