//FormAI DATASET v1.0 Category: Data mining ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

struct student {
  int id;
  char name[50];
  float gpa;
};

int main() {
  FILE *fp;
  struct student s;
  fp = fopen("students.dat","r");
  
  if(fp == NULL) {
    printf("Error opening file");
    exit(1);
  }
  
  printf("ID\tName\tGPA\n");
  
  while(fread(&s, sizeof(s), 1, fp)) {
    printf("%d\t%s\t%.2f\n", s.id, s.name, s.gpa);
  }
  
  fclose(fp);
  
  return 0;
}