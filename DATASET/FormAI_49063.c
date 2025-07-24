//FormAI DATASET v1.0 Category: Database querying ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Student
{
   int id;
   char name[20];
   int age;
} Student;

void add_student(Student* student)
{
   FILE *fp;
   fp = fopen("students.dat", "ab");

   if(fp == NULL)
   {
      printf("Error opening file!");
      exit(1);
   }

   fwrite(student, sizeof(Student), 1, fp);
   fclose(fp);
}

void display_student_by_id(int id)
{
   Student student;
   FILE *fp;
   fp = fopen("students.dat", "rb");

   if(fp == NULL)
   {
      printf("Error opening file!");
      exit(1);
   }

   printf("Students with id %d:\n", id);

   while(fread(&student, sizeof(Student), 1, fp))
   {
      if(student.id == id)
      {
         printf("Id: %d\n", student.id);
         printf("Name: %s\n", student.name);
         printf("Age: %d\n", student.age);
      }
   }

   fclose(fp);
}

int main()
{
   Student student;
   student.id = 1001;
   strcpy(student.name, "John");
   student.age = 19;
   add_student(&student);

   student.id = 1002;
   strcpy(student.name, "Alice");
   student.age = 20;
   add_student(&student);

   student.id = 1003;
   strcpy(student.name, "Bob");
   student.age = 18;
   add_student(&student);

   int search_id = 1002;
   display_student_by_id(search_id);

   return 0;
}