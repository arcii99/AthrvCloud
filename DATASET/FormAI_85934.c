//FormAI DATASET v1.0 Category: Database simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
   int id;
   char name[50];
   float percentage;
};

int main() {
   struct student s;
   FILE *fptr;
   fptr = fopen("students.txt","w");

   if(fptr == NULL) {
      printf("Error!");
      exit(1);
   }

   printf("Enter student id: ");
   scanf("%d", &s.id);

   fflush(stdin);
   printf("Enter student name: ");
   gets(s.name);

   printf("Enter student percentage: ");
   scanf("%f", &s.percentage);

   fprintf(fptr,"\nStudent ID     : %d \n", s.id);
   fprintf(fptr,"Student Name   : %s \n", s.name);
   fprintf(fptr,"Student Percent: %f \n", s.percentage);

   fclose(fptr);
   return 0;
}