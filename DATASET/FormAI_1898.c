//FormAI DATASET v1.0 Category: Data mining ; Style: curious
#include<stdio.h>
#include<stdlib.h>

struct student {
  int id;
  char name[50];
  float gpa;
};

int main() {

  int num_students = 5;
  
  struct student *students = (struct student*) malloc(num_students * sizeof(struct student));

  students[0].id = 101;
  strcpy(students[0].name, "John");
  students[0].gpa = 3.5;

  students[1].id = 102;
  strcpy(students[1].name, "Mary");
  students[1].gpa = 3.8;

  students[2].id = 103;
  strcpy(students[2].name, "Tom");
  students[2].gpa = 3.2;

  students[3].id = 104;
  strcpy(students[3].name, "Samantha");
  students[3].gpa = 4.0;

  students[4].id = 105;
  strcpy(students[4].name, "Mike");
  students[4].gpa = 2.9;

  float sum = 0.0, average = 0.0;

  for(int i=0; i<num_students; i++) {
    sum += students[i].gpa;
  }

  average = sum / num_students;

  printf("The average GPA of the %d students is: %.2f\n", num_students, average);

  free(students);

  return 0;
}