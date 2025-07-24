//FormAI DATASET v1.0 Category: Database simulation ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
   int roll_no;
   char name[50];
   int marks;
};

void display_student(struct student stud);

int main(){

   int students_count;
   
   printf("Enter the number of students: ");
   scanf("%d", &students_count);

   struct student* students = (struct student*)malloc(students_count*sizeof(struct student));

   printf("\nEnter the details of the students:\n");
   for(int i=0; i<students_count; i++){
      printf("\nEnter the details of student %d\n", i+1);
      printf("Enter the roll number: ");
      scanf("%d", &students[i].roll_no);
      printf("Enter the student name: ");
      scanf("%s", students[i].name);
      printf("Enter the marks: ");
      scanf("%d", &students[i].marks);
   }

   printf("\nDetails of all students:\n");
   for(int i=0; i<students_count; i++){
      printf("\nDetails of student %d\n", i+1);
      display_student(students[i]);
   }

   free(students);
   
   return 0;
}

void display_student(struct student stud){
   printf("Roll number: %d\n", stud.roll_no);
   printf("Name: %s\n", stud.name);
   printf("Marks: %d\n", stud.marks);
}