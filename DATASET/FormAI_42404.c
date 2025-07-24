//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Claude Shannon
#include <stdio.h>

// Define a struct to represent a student
struct Student {
  int id;
  char name[50];
  float gpa;
};

int main() {
  int num_students = 5;
  // Initialize an array of students
  struct Student students[] = {
    {1, "Alice", 3.2},
    {2, "Bob", 3.5},
    {3, "Charlie", 3.9},
    {4, "David", 2.8},
    {5, "Eve", 3.7}
  };

  // Print out the students' information
  printf("Students:\n");
  printf("    ID | NAME             | GPA\n");
  printf("-------|-----------------|------\n");
  for (int i = 0; i < num_students; i++) {
    printf(" %5d | %-15s | %4.1f\n", students[i].id, students[i].name, students[i].gpa);
  }
  printf("\n");

  // Calculate the average GPA
  float avg_gpa = 0;
  for (int i = 0; i < num_students; i++) {
    avg_gpa += students[i].gpa;
  }
  avg_gpa /= num_students;

  // Print out the average GPA
  printf("Average GPA: %.2f\n", avg_gpa);
  
  return 0;
}