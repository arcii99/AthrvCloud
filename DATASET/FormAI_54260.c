//FormAI DATASET v1.0 Category: File handling ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

struct student {
   char name[50];
   int age;
   int id;
   float gpa;
};

int main() {
   struct student s;
   FILE *fp;

   // Writing to file
   fp = fopen("student_data.txt", "w");

   s.id = 1;
   snprintf(s.name, sizeof(s.name), "John Doe");
   s.age = 20;
   s.gpa = 3.5;

   fwrite(&s, sizeof(struct student), 1, fp);

   s.id = 2;
   snprintf(s.name, sizeof(s.name), "Jane Smith");
   s.age = 21;
   s.gpa = 3.9;

   fwrite(&s, sizeof(struct student), 1, fp);

   fclose(fp);

   // Reading from file
   fp = fopen("student_data.txt", "r");

   while(fread(&s, sizeof(struct student), 1, fp) == 1) {
      printf("Name: %s\n", s.name);
      printf("Age: %d\n", s.age);
      printf("ID: %d\n", s.id);
      printf("GPA: %.2f\n", s.gpa);
      printf("\n");
   }

   fclose(fp);

   return 0;
}