//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct resume {
  char name[30];
  char email[30];
  char education[50];
  char skills[100];
  char experience[200];
};

int main() {
  struct resume r;
  printf("Enter your name: ");
  scanf("%[^\n]%*c", r.name);
  printf("Enter your email: ");
  scanf("%[^\n]%*c", r.email);
  printf("Enter your education: ");
  scanf("%[^\n]%*c", r.education);
  printf("Enter your skills: ");
  scanf("%[^\n]%*c", r.skills);
  printf("Enter your experience: ");
  scanf("%[^\n]%*c", r.experience);
  
  // Parsing the resume
  char *token;
  printf("\nParsing your resume...\n");
  printf("Name: %s\n", r.name);
  printf("Email: %s\n", r.email);
  printf("Education: ");
  token = strtok(r.education, ",");
  while(token != NULL) {
    printf("%s\n\t\t", token);
    token = strtok(NULL, ",");
  }
  printf("\nSkills: ");
  token = strtok(r.skills, ",");
  while(token != NULL) {
    printf("%s\n\t\t", token);
    token = strtok(NULL, ",");
  }
  printf("\nExperience: ");
  token = strtok(r.experience, ",");
  while(token != NULL) {
    printf("%s\n\t\t", token);
    token = strtok(NULL, ",");
  }
  
  return 0;
}