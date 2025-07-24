//FormAI DATASET v1.0 Category: File handling ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

int main() {
   FILE *file;
   char filename[50], text[100];
   
   printf("Enter the name of the file to be created: ");
   scanf("%s", filename);

   //Creates a new file with the specified name 
   file = fopen(filename, "w"); 
   
   if (file == NULL) {
      printf("File does not exist.\n");
      exit(0);
   }
   
   printf("Type some text. Ctrl + D to end the text input:\n");
   
   //Reads input from user until end of file is reached
   while(fgets(text, 100, stdin) != NULL) {
      //Store the read input in a file
      fputs(text, file);
   }

   printf("\nText has been saved to the file \"%s\".", filename);
   
   //Close file 
   fclose(file);

   printf("\n\n");

   //Reads from the created file and prints its content to the console
   file = fopen(filename, "r");
   
   printf("Printing the content of the file \"%s\":\n", filename);

   while(fgets(text, 100, file) != NULL) {
      //Prints the content of the file
      printf("%s", text);
   }

   //Close file
   fclose(file);

   return 0;
}