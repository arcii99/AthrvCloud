//FormAI DATASET v1.0 Category: Data mining ; Style: lively
#include <stdio.h>

struct Student {
  int id;
  char name[50];
  float physicsMarks, mathMarks, englishMarks;
  float totalMarks, average;
};

void calculateTotalMarks(struct Student *student);
void calculateAverage(struct Student *student);

int main() {
  int n;
  printf("Enter the number of students: ");
  scanf("%d", &n);

  // create an array of n students
  struct Student students[n];

  // take input from the user for each student
  for(int i=0; i<n; i++) {
    printf("\nEnter the details for student %d:", i+1);

    printf("\nID: ");
    scanf("%d", &students[i].id);

    printf("Name: ");
    scanf("%s", &students[i].name);

    printf("Physics Marks: ");
    scanf("%f", &students[i].physicsMarks);

    printf("Math Marks: ");
    scanf("%f", &students[i].mathMarks);

    printf("English Marks: ");
    scanf("%f", &students[i].englishMarks);

    calculateTotalMarks(&students[i]);
    calculateAverage(&students[i]);
  }

  // print the details of all students
  printf("\nStudent Details:\n");
  for(int i=0; i<n; i++) {
    printf("\nStudent %d:\n", i+1);
    printf("ID: %d\n", students[i].id);
    printf("Name: %s\n", students[i].name);
    printf("Physics Marks: %.2f\n", students[i].physicsMarks);
    printf("Math Marks: %.2f\n", students[i].mathMarks);
    printf("English Marks: %.2f\n", students[i].englishMarks);
    printf("Total Marks: %.2f\n", students[i].totalMarks);
    printf("Average: %.2f\n", students[i].average);
  }

  return 0;
}

void calculateTotalMarks(struct Student *student) {
  student->totalMarks = student->physicsMarks + student->mathMarks + student->englishMarks;
}

void calculateAverage(struct Student *student) {
  student->average = student->totalMarks / 3.0;
}