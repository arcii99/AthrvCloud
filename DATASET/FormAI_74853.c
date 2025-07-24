//FormAI DATASET v1.0 Category: File handling ; Style: optimized
#include <stdio.h>

int main() {
   FILE *file_ptr;
   char filename[] = "example.txt";
   int num1 = 10;
   float num2 = 2.5;
   char str[] = "Hello world";
   
   // Write to the file
   file_ptr = fopen(filename, "w");
   if (file_ptr == NULL) {
      printf("Error opening file!");
      return 1;
   }
   fprintf(file_ptr,"%d\n%f\n%s", num1, num2, str);
   fclose(file_ptr);
   
   // Read from the file
   file_ptr = fopen(filename, "r");
   if (file_ptr == NULL) {
      printf("Error opening file!");
      return 1;
   }
   fscanf(file_ptr, "%d %f %s", &num1, &num2, str);
   printf("num1: %d\nnum2: %f\nstr: %s", num1, num2, str);
   fclose(file_ptr);
   
   return 0;
}