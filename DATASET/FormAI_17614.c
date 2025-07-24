//FormAI DATASET v1.0 Category: Database simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
  int id;
  char name[50];
  int age;
} Student;

int main() {
  FILE *fp;

  // Open file for writing
  fp = fopen("students.bin", "wb");
  if (fp == NULL) {
    printf("Error opening file!\n");
    exit(1);
  }

  // Create 5 student records
  Student stu1, stu2, stu3, stu4, stu5;

  stu1.id = 1001;
  strcpy(stu1.name, "John Doe");
  stu1.age = 20;

  stu2.id = 1002;
  strcpy(stu2.name, "Jane Smith");
  stu2.age = 21;

  stu3.id = 1003;
  strcpy(stu3.name, "Bob Johnson");
  stu3.age = 19;

  stu4.id = 1004;
  strcpy(stu4.name, "Mary Brown");
  stu4.age = 22;

  stu5.id = 1005;
  strcpy(stu5.name, "Tom Jones");
  stu5.age = 20;

  // Write student records to file
  fwrite(&stu1, sizeof(Student), 1, fp);
  fwrite(&stu2, sizeof(Student), 1, fp);
  fwrite(&stu3, sizeof(Student), 1, fp);
  fwrite(&stu4, sizeof(Student), 1, fp);
  fwrite(&stu5, sizeof(Student), 1, fp);

  fclose(fp);

  // Open file for reading
  fp = fopen("students.bin", "rb");
  if (fp == NULL) {
    printf("Error opening file!\n");
    exit(1);
  }

  // Read student records from file
  printf("List of students:\n");
  Student stu;
  while (fread(&stu, sizeof(Student), 1, fp) == 1) {
    printf("ID: %d, Name: %s, Age: %d\n", stu.id, stu.name, stu.age);
  }

  fclose(fp);

  return 0;
}