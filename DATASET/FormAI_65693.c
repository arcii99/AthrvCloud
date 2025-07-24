//FormAI DATASET v1.0 Category: File handling ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

int main() {
   char ch, file_name[30];
   FILE *fp;

   printf("Enter the name of file you wish to create\n");
   gets(file_name);

   fp = fopen(file_name, "w"); // open file in write mode

   if(fp == NULL) {
      perror("Error opening the file"); // handling error
      exit(EXIT_FAILURE);
   }

   printf("Type in the text you want to save in the file\n");
   printf("Press 'Ctrl+Z' to stop writing\n");

   while((ch = getchar()) != EOF) {
      putc(ch, fp); // writing input to file
   }

   fclose(fp); //close the file

   printf("\nThe file '%s' was created successfully\n", file_name);

   fp = fopen(file_name, "r"); // opening file in read mode

   if(fp == NULL) {
      perror("Error opening the file");
      exit(EXIT_FAILURE);
   }

   printf("\nThe file '%s' contains the following text\n", file_name);

   while((ch = getc(fp)) != EOF) {
      putchar(ch); // printing file content on stdout
   }

   fclose(fp); // closing the file

   return 0;
}