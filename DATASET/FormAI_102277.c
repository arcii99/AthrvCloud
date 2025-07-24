//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
  char name[30];
  int rollno;
  float marks;
};

int main() {
  FILE *fp;
  char filename[30], line[100];
  char *token;
  int i = 0;
  struct student s[50];

  printf("Enter the filename to open: ");
  scanf("%s", filename);

  fp = fopen(filename, "r");

  if (fp == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  while (fgets(line, 100, fp)) {
    // split string by commas
    token = strtok(line, ",");
    strcpy(s[i].name, token);
    token = strtok(NULL, ",");
    s[i].rollno = atoi(token);
    token = strtok(NULL, ",");
    s[i].marks = atof(token);
    i++;
  }

  fclose(fp);

  // print the contents of the struct array
  printf("Name\tRoll No\tMarks\n");
  for (int j = 0; j < i; j++) {
    printf("%s\t%d\t%.1f\n", s[j].name, s[j].rollno, s[j].marks);
  }

  return 0;
}