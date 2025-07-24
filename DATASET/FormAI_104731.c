//FormAI DATASET v1.0 Category: Database simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
  char name[20];
  int ID;
  float gpa;
};

int main() {
  // create an array of 10 students
  struct Student students[10];
  
  // add some sample data
  strcpy(students[0].name, "John");
  students[0].ID = 1001;
  students[0].gpa = 3.5;
  
  strcpy(students[1].name, "David");
  students[1].ID = 1002;
  students[1].gpa = 3.8;
  
  strcpy(students[2].name, "Sarah");
  students[2].ID = 1003;
  students[2].gpa = 3.2;
  
  strcpy(students[3].name, "Emily");
  students[3].ID = 1004;
  students[3].gpa = 3.9;
  
  // print out the data for all students
  printf("Name\tID\tGPA\n");
  for (int i = 0; i < 4; i++) {
    printf("%s\t%d\t%.1f\n", students[i].name, students[i].ID, students[i].gpa);
  }
  
  return 0;
}