//FormAI DATASET v1.0 Category: File handling ; Style: calm
#include <stdio.h>

int main() {
   FILE *fp;
   char data[50];

   // Opening file to write
   fp = fopen("example.txt", "w");

   if (fp) {
       printf("File opened successfully for writing!\n");

       // Writing data to file
       fputs("Hello World!", fp);

       // Closing the file
       fclose(fp);
       printf("Data has been written to file!\n\n");

       // Opening the same file to read
       fp = fopen("example.txt", "r");

       if (fp) {
           printf("File opened successfully for reading!\n");

           // Reading data from file
           fgets(data, 50, fp);
           printf("Data in file: %s\n\n", data);

           // Closing the file
           fclose(fp);
       } else {
           printf("Error opening file for reading!");
       }
   } else {
       printf("Error opening file for writing!");
   }

   return 0;
}