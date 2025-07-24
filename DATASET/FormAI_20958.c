//FormAI DATASET v1.0 Category: Educational ; Style: protected
#include <stdio.h>

// define a struct to represent a student record
typedef struct {
  int id; // student id
  char name[40]; // student name
  int age; // student age
  float gpa; // student gpa
} Student;

int main() {
  // create an array of student records
  Student students[10];

  printf("Enter information for 10 students:\n");

  // read in information for each student
  for(int i = 0; i < 10; i++) {
    printf("Student %d:\n", i+1);
    printf("ID: ");
    scanf("%d", &students[i].id);
    printf("Name: ");
    scanf("%s", students[i].name);
    printf("Age: ");
    scanf("%d", &students[i].age);
    printf("GPA: ");
    scanf("%f", &students[i].gpa);
  }

  // print out all student records
  printf("\nAll student records:\n\n");
  printf("ID\tName\tAge\tGPA\n");
  printf("--------------------------------\n");
  for(int i = 0; i < 10; i++) {
    printf("%d\t%s\t%d\t%.2f\n", students[i].id, students[i].name,
           students[i].age, students[i].gpa);
  }

  return 0;
}