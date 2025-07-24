//FormAI DATASET v1.0 Category: Database simulation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

struct student {
  int id;
  char name[MAX_SIZE];
  int age;
};

int main() {
  struct student students[10];
  int count = 0;

  printf("| %-4s | %-20s | %-3s |\n", "ID", "NAME", "AGE");
  printf("=============================================\n");

  // add new student
  struct student student1 = {1, "John Doe", 20};
  students[count] = student1;
  count++;

  // display all students
  for (int i = 0; i < count; i++) {
    printf("| %-4d | %-20s | %-3d |\n", students[i].id, students[i].name, students[i].age);
  }

  return 0;
}