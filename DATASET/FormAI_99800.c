//FormAI DATASET v1.0 Category: Educational ; Style: satisfied
#include <stdio.h>

// Declare a struct
struct student {
  char name[50];
  int age;
  float gpa;
};

int main() {
  // Declare an array of structs
  struct student students[3];

  // Loop through each struct in the array to get input from the user
  for(int i = 0; i < 3; i++) {
    printf("Enter name, age, and GPA for student %d: ", i+1);
    scanf("%s %d %f", students[i].name, &students[i].age, &students[i].gpa);
  }

  // Loop through each struct in the array to print out the student's info
  printf("Student Info:\n");
  for(int i = 0; i < 3; i++) {
    printf("Name: %s\nAge: %d\nGPA: %.2f\n", students[i].name, students[i].age, students[i].gpa);
  }

  return 0;
}