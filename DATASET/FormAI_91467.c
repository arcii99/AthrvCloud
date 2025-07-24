//FormAI DATASET v1.0 Category: Data mining ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_STUDENTS 100
#define NUM_EXAMS 5

int main(void) {

  // Create an array of students
  struct student {
    char name[20];
    int grades[NUM_EXAMS];
    float gpa;
  };
  struct student students[NUM_STUDENTS];

  // Seed random number generator for generating student grades
  srand(time(NULL));

  // Generate random grades for each student and calculate their GPA
  for (int i = 0; i < NUM_STUDENTS; i++) {
    int total = 0;
    for (int j = 0; j < NUM_EXAMS; j++) {
      students[i].grades[j] = rand() % 100;
      total += students[i].grades[j];
    }
    students[i].gpa = total / (float)NUM_EXAMS;
  }

  // Find the student(s) with the highest GPA
  float highest_gpa = 0;
  printf("Student(s) with the highest GPA:\n");
  for (int i = 0; i < NUM_STUDENTS; i++) {
    if (students[i].gpa > highest_gpa) {
      highest_gpa = students[i].gpa;
    }
  }
  for (int i = 0; i < NUM_STUDENTS; i++) {
    if (students[i].gpa == highest_gpa) {
      printf("%s\n", students[i].name);
    }
  }

  // Find the exam(s) with the highest average grade
  float highest_avg_grade = 0;
  printf("Exam(s) with the highest average grade:\n");
  for (int j = 0; j < NUM_EXAMS; j++) {
    int total = 0;
    for (int i = 0; i < NUM_STUDENTS; i++) {
      total += students[i].grades[j];
    }
    float avg_grade = total / (float)NUM_STUDENTS;
    if (avg_grade > highest_avg_grade) {
      highest_avg_grade = avg_grade;
    }
  }
  for (int j = 0; j < NUM_EXAMS; j++) {
    int total = 0;
    for (int i = 0; i < NUM_STUDENTS; i++) {
      total += students[i].grades[j];
    }
    float avg_grade = total / (float)NUM_STUDENTS;
    if (avg_grade == highest_avg_grade) {
      printf("Exam %d\n", j+1);
    }
  }

  return 0;
}