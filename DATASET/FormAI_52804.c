//FormAI DATASET v1.0 Category: File handling ; Style: cheerful
#include <stdio.h>

int main() 
{
   FILE *fptr; // declaring file pointer variable
   char filename[20], name[20];
   int age;

   printf("Hello there! Welcome to the Happy People Database.\n");
   printf("Please enter the name of the file you would like to create and open:\n");
   scanf("%s", filename);

   // Opening the file with file pointer in write mode
   fptr = fopen(filename, "w");

   if(fptr == NULL) // Checking if file failed to open
   {
      printf("Failed to create and open file. You are not so happy now :(.\n");
      return 1; // Exiting program with status 1
   }

   printf("Great job! You have successfully created the file %s. Woo-hoo!\n", filename);

   // Prompting user for name and age input
   printf("Please enter your name:\n");
   scanf("%s", name);
   printf("Please enter your age:\n");
   scanf("%d", &age);

   // Writing user input to the file
   fprintf(fptr,"%s\n%d\n", name, age);

   // Closing the file
   fclose(fptr);

   printf("Data successfully written to the file %s. Keep being happy!\n", filename);

   return 0; // Exiting program with status 0
}