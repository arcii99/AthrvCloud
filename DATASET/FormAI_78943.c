//FormAI DATASET v1.0 Category: File handling ; Style: inquisitive
#include <stdio.h>

int main() {
   FILE *filePointer; //declare file pointer variable
   char data[50]; //declare character array for data
   
   //open file for writing
   filePointer = fopen("example.txt", "w"); 

   //check if file opened successfully
   if (filePointer == NULL) {
       printf("Unable to open file for writing");
       return 0;
   }
   
   //write data to file
   printf("Enter data to write to file:\n");
   fgets(data, 50, stdin);
   fprintf(filePointer, "%s", data); 

   //close file
   fclose(filePointer);

   //open file for reading
   filePointer = fopen("example.txt", "r"); 

   //check if file opened successfully
   if (filePointer == NULL) {
       printf("Unable to open file for reading");
       return 0;
   }

   //read data from file and display on console
   printf("\nData read from file:\n");
   while (fgets(data, 50, filePointer) != NULL) {
       printf("%s", data); 
   }

   //close file
   fclose(filePointer);

   return 0;
}