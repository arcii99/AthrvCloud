//FormAI DATASET v1.0 Category: Educational ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Define a struct for holding student data
typedef struct {
  char name[50];
  int age;
  float gpa;
} Student;

// Define a struct for holding teacher data
typedef struct {
  char name[50];
  int age;
  char subject[50];
} Teacher;

// Define a function for printing student details
void printStudentDetails(Student student) {
  printf("Name: %s\n", student.name);
  printf("Age: %d\n", student.age);
  printf("GPA: %.2f\n", student.gpa);
}

// Define a function for printing teacher details
void printTeacherDetails(Teacher teacher) {
  printf("Name: %s\n", teacher.name);
  printf("Age: %d\n", teacher.age);
  printf("Subject: %s\n", teacher.subject);
}

int main() {
  // Create an array of students
  Student students[3] = {
    {"Alice", 20, 3.5},
    {"Bob", 19, 3.7},
    {"Charlie", 21, 3.9}
  };

  // Create a teacher
  Teacher teacher = {"Ms. Smith", 30, "Computer Science"};

  // Print out the student and teacher details
  printf("Students:\n");
  for (int i = 0; i < 3; i++) {
    printStudentDetails(students[i]);
    printf("\n");
  }

  printf("Teacher:\n");
  printTeacherDetails(teacher);
  
  return 0;
}