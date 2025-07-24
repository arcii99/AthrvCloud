//FormAI DATASET v1.0 Category: File handling ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

struct student {
   char name[50];
   int roll;
   float marks;
};

int main() {
   FILE *filePtr;
   struct student std;

   // Writing to a file
   filePtr = fopen("students.txt", "w");
   if (filePtr == NULL) {
      printf("File cannot be opened.\n");
      exit(1);
   }

   printf("Enter name, roll number and marks respectively:\n");
   scanf("%s %d %f", std.name, &std.roll, &std.marks);
   
   // Using fprintf to write to file
   fprintf(filePtr, "%s %d %.2f\n", std.name, std.roll, std.marks);

   fclose(filePtr);
   
   // Reading from a file
   filePtr = fopen("students.txt", "r");
   if (filePtr == NULL) {
      printf("File cannot be opened.\n");
      exit(1);
   }

   // Using fscanf to read from file
   fscanf(filePtr, "%s %d %f", std.name, &std.roll, &std.marks);
   
   printf("Name: %s\nRoll: %d\nMarks: %.2f\n", std.name, std.roll, std.marks);

   fclose(filePtr);
   
   return 0;
}