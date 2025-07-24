//FormAI DATASET v1.0 Category: Educational ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

// Define struct of student
struct Student {
   char name[50];
   int age;
   int id;
   float mark;
};

// Function to display student data
void display_data(int n, struct Student students[]) {
   printf("Name\tAge\tID\tMark\n");
   for (int i = 0; i < n; i++) {
       printf("%s\t%d\t%d\t%.2f\n", students[i].name, students[i].age, students[i].id, students[i].mark);
   }
}

int main() {
   int number_of_students;
   printf("Enter total number of students: ");
   scanf("%d", &number_of_students);

   // Allocate memory for students
   struct Student *students = (struct Student *) malloc(number_of_students * sizeof(struct Student));
   
   // Get student information
   for (int i = 0; i < number_of_students; i++) {
       printf("Enter details for student %d\n", i + 1);
       printf("Name: ");
       scanf("%s", students[i].name);
       printf("Age: ");
       scanf("%d", &students[i].age);
       printf("ID: ");
       scanf("%d", &students[i].id);
       printf("Mark: ");
       scanf("%f", &students[i].mark);
   }
   
   // Display student data
   display_data(number_of_students, students);

   // Free allocated memory
   free(students);
   return 0;
}