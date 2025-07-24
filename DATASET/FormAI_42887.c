//FormAI DATASET v1.0 Category: Data mining ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

struct student {
   char name[50];
   int age;
   int grade;
};

int main() {
   int num_students = 0;
   struct student* students = NULL;

   printf("Enter the number of students to input data for: ");
   scanf("%d", &num_students);

   students = (struct student*)malloc(num_students * sizeof(struct student));

   for(int i = 0; i < num_students; i++) {
      printf("Enter name, age, and grade for student %d: ", i+1);
      scanf("%s %d %d", &students[i].name, &students[i].age, &students[i].grade);
   }

   int sum = 0;
   for(int i = 0; i < num_students; i++) {
      sum += students[i].grade;
   }
   float average_grade = (float)sum / num_students;

   printf("The average grade of the %d students is %.2f", num_students, average_grade);

   free(students);
   return 0;
}