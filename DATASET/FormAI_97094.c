//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct resume {
  char name[50];
  char email[50];
  char phone[20];
  char skills[100];
  char experience[100];
};

int main() {
  int num_resumes;
  printf("Enter the number of resumes to be parsed: ");
  scanf("%d", &num_resumes);

  struct resume* resume_list = malloc(num_resumes * sizeof(struct resume));
  printf("Please enter each resume on a new line, with the following format:\n");
  printf("[Name], [Email], [Phone], [Skills], [Experience]\n");

  for (int i = 0; i < num_resumes; i++) {
    printf("Resume %d: ", i+1);
    char buffer[500];
    fgets(buffer, 500, stdin);
    sscanf(buffer, "%[^,], %[^,], %[^,], %[^,], %s",
            resume_list[i].name,
            resume_list[i].email,
            resume_list[i].phone,
            resume_list[i].skills,
            resume_list[i].experience);
  }

  printf("\n\nParsed Resumes:\n");
  for (int i = 0; i < num_resumes; i++) {
    printf("Name: %s\n", resume_list[i].name);
    printf("Email: %s\n", resume_list[i].email);
    printf("Phone: %s\n", resume_list[i].phone);
    printf("Skills: %s\n", resume_list[i].skills);
    printf("Experience: %s\n", resume_list[i].experience);
    printf("\n\n");
  }
  free(resume_list);
  return 0;
}