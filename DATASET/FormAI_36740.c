//FormAI DATASET v1.0 Category: File handling ; Style: rigorous
#include <stdio.h>

int main() {
   FILE *fp;
   char name[50], c;

   // opening file for writing
   fp = fopen("example.txt", "w");

   if (fp == NULL) {
      printf("Error opening file\n");
      return 1;
   }

   printf("Enter name: ");
   fgets(name, sizeof(name), stdin);

   // writing name to the file
   fprintf(fp, "Name: %s", name);

   // closing the file
   fclose(fp);

   // opening file for reading
   fp = fopen("example.txt", "r");

   if (fp == NULL) {
      printf("Error opening file\n");
      return 1;
   }

   // reading and printing the name from the file
   printf("Reading name from file:\n");
   while ((c = fgetc(fp)) != EOF) {
      printf("%c", c);
   }

   // closing the file
   fclose(fp);

   return 0;
}