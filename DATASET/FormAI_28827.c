//FormAI DATASET v1.0 Category: File handling ; Style: lively
#include <stdio.h>

int main() {
   int num;
   char filename[20];
   printf("Enter the file name you want to create: ");
   scanf("%s", filename);

   // Create a file for writing
   FILE *f = fopen(filename, "w");

   if (f == NULL) {
      printf("Error creating file!");
      return 1;
   }

   printf("Enter how many numbers you want to write to the file: ");
   scanf("%d", &num);

   printf("Enter %d numbers: ", num);

   // Write the numbers to the file
   for(int i=0; i<num; i++) {
      int x;
      scanf("%d", &x);
      fprintf(f, "%d ", x);
   }

   fclose(f);

   // Open the file for reading
   f = fopen(filename, "r");
   
   if(f == NULL) {
      printf("Error opening file!");
      return 1;
   }

   printf("The numbers in the file are: ");

   // Read and display the numbers in the file
   int x;
   while(fscanf(f, "%d", &x) != EOF) {
      printf("%d ", x);
   }

   fclose(f);
   return 0;
}