//FormAI DATASET v1.0 Category: Educational ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for a student record
struct student {
   char name[30];
   int id;
   float grades[5]; // Assuming each student has 5 courses
};

// Define a function to display a student record
void displayStudent(struct student s) {
   printf("Name: %s\n", s.name);
   printf("ID: %d\n", s.id);
   printf("Grades: ");
   for (int i = 0; i < 5; i++) {
      printf("%.2f ", s.grades[i]);
   }
   printf("\n");
}

int main() {
   int n;
   printf("Enter the number of students: ");
   scanf("%d", &n);

   struct student students[n]; // Create an array of n student records

   for (int i = 0; i < n; i++) {
      printf("Enter student %d's name: ", i+1);
      scanf("%s", students[i].name);

      printf("Enter student %d's ID: ", i+1);
      scanf("%d", &students[i].id);

      printf("Enter student %d's grades (5 separated by spaces): ", i+1);
      for (int j = 0; j < 5; j++) {
         scanf("%f", &students[i].grades[j]);
      }
   }

   // Display all the student records
   for (int i = 0; i < n; i++) {
      displayStudent(students[i]);
   }

   return 0;
}