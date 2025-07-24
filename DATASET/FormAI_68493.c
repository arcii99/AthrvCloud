//FormAI DATASET v1.0 Category: File handling ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

int main() {
   FILE *fp;
   int i,num;
   float f;
   char str[50];
   
   fp = fopen("example.txt", "w+"); // opens the file for writing and reading
   
   if (fp == NULL) {
      printf("Error opening file.\n");
      exit(1);
   }
   
   printf("Enter an integer: ");
   scanf("%d", &num);
   
   printf("Enter a floating point number: ");
   scanf("%f", &f);
   
   printf("Enter a string: ");
   scanf("%s", str);
   
   fprintf(fp, "%d %f %s", num, f, str); // writes the data to the file
   
   rewind(fp); // moves the file pointer back to the beginning of the file
   
   fscanf(fp, "%d %f %s", &i, &f, str); // reads the data from the file
   
   printf("Data read from file:\n");
   printf("%d\n%f\n%s\n", i, f, str); // prints the data to the console
   
   fclose(fp);
   return 0;
}