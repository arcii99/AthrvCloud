//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[20];
  int age;
  char university[50];
  double gpa;
} Student;

void printStudent(Student s) {
  printf("Name: %s\n", s.name);
  printf("Age: %d\n", s.age);
  printf("University: %s\n", s.university);
  printf("GPA: %0.2f\n", s.gpa);
}

void parseResume(char* file) {
  FILE* fp = fopen(file, "r");

  if (fp == NULL) {
    printf("Error: unable to open file\n");
    return;
  }

  char buffer[200];
  int lineCount = 0;
  int studentCount = 0;
  Student students[10];

  while (fgets(buffer, 200, fp)) {
    lineCount++;

    if (strstr(buffer, "Name: ") != NULL) {
      Student s;
      strcpy(s.name, strtok(buffer, ":"));
      s.age = atoi(strtok(NULL, ":"));
      strcpy(s.university, strtok(NULL, ":"));
      s.gpa = atof(strtok(NULL, ":"));
      students[studentCount] = s;
      studentCount++;
    }
  }

  fclose(fp);

  for (int i = 0; i < studentCount; i++) {
    printf("\nStudent %d:\n", i + 1);
    printStudent(students[i]);
  }
}

int main() {
  parseResume("resume.txt");
  return 0;
}