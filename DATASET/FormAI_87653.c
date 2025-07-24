//FormAI DATASET v1.0 Category: Online Examination System ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student {
  int stud_id;
  char name[40];
  float marks;
};

int main() {
  int num_students, i;
  printf("Enter the number of students: ");
  scanf("%d", &num_students);

  struct student *students = (struct student*)malloc(num_students * sizeof(struct student));

  for(i = 0; i < num_students; i++) {
    printf("\nEnter the student ID: ");
    scanf("%d", &students[i].stud_id);

    printf("Enter the student name: ");
    scanf("%s", &students[i].name);

    printf("Enter the student marks: ");
    scanf("%f", &students[i].marks);
  }

  printf("\n\nRESULTS\n");
  printf("---------------------------------------------------------\n");
  printf("|  ID  |                  NAME                  |  MARKS  |\n");
  printf("---------------------------------------------------------\n");

  for(i = 0; i < num_students; i++) {
    printf("| %4d | %36s |    %.2f |\n", students[i].stud_id, students[i].name, students[i].marks);
  }

  printf("---------------------------------------------------------\n");

  free(students);
  
  return 0;
}