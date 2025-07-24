//FormAI DATASET v1.0 Category: File handling ; Style: portable
#include<stdio.h>
#include<stdlib.h>

struct student{
  char name[30];
  int roll;
  float mark;
};

int main(){

  int n, i;

  printf("Enter the number of students: ");
  scanf("%d", &n);

  FILE *fp;
  fp = fopen("student.txt", "w+");

  // Write data to file
  for(i=0; i<n; i++){
    struct student stu;
    printf("\n\nEnter the name of student %d: ", i+1);
    scanf("%s", stu.name);
    printf("Enter the roll no of student %d: ", i+1);
    scanf("%d", &stu.roll);
    printf("Enter the mark of student %d: ", i+1);
    scanf("%f", &stu.mark);
    fwrite(&stu, sizeof(struct student), 1, fp);
  }
  printf("\nData successfully written to file!");

  // Read data from file
  printf("\n\nReading data from file...");
  rewind(fp);
  for(i=0; i<n; i++){
    struct student stu;
    fread(&stu, sizeof(struct student), 1, fp);
    printf("\n\nName: %s", stu.name);
    printf("\nRoll no: %d", stu.roll);
    printf("\nMark: %.2f", stu.mark);
  }
  printf("\nData successfully read from file!");

  fclose(fp);
  return 0;
}