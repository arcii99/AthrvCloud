//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Resume {
  char name[50];
  char email[50];
  char phone[20];
  char skills[200];
  char education[100];
};

int main() {
  int numResumes;
  printf("Enter the number of resumes to parse: ");
  scanf("%d", &numResumes);

  struct Resume* resumes = (struct Resume*)malloc(numResumes * sizeof(struct Resume));
  printf("\nEnter the resumes in format: Name, Email, Phone, Skills, Education\n");

  for(int i = 0; i < numResumes; i++) {
    printf("\nResume #%d: ", i+1);
    scanf("%[^,],%[^,],%[^,],%[^,],%[^\n]",
    &resumes[i].name, &resumes[i].email, &resumes[i].phone, &resumes[i].skills, &resumes[i].education);
  }

  printf("\nParsing Resumes...\n");
  for(int i = 0; i < numResumes; i++) {
    printf("\nResume #%d\nName: %s\nEmail: %s\nPhone: %s\nSkills: %s\nEducation: %s\n", 
    i+1, resumes[i].name, resumes[i].email, resumes[i].phone, resumes[i].skills, resumes[i].education);
  }

  free(resumes);
  return 0;
}