//FormAI DATASET v1.0 Category: File handling ; Style: energetic
#include <stdio.h>

int main()
{
   FILE *input, *output;
   char data[100];

   // Read data from the input file
   input = fopen("input.txt", "r");
   if (input == NULL)
   {
       printf("Error: Unable to open input file");
       return 1;
   }

   fgets(data, 100, input);

   fclose(input);

   // Write data to the output file
   output = fopen("output.txt", "w");
   if (output == NULL)
   {
       printf("Error: Unable to open output file");
       return 1;
   }

   fputs(data, output);

   fclose(output);

   printf("Data written to file successfully");

   return 0;
}