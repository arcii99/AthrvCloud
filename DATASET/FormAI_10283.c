//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

struct resume_details {
  char name[50];
  int age;
  char email[50];
  char phone[15];
  char experience[100];
  char education[100];
  char skills[100];
};

int main() {
  struct resume_details resume;

  printf("Enter your name: ");
  fgets(resume.name, 50, stdin);

  printf("Enter your age: ");
  scanf("%d", &resume.age);

  printf("Enter your email: ");
  scanf("%s", resume.email);

  printf("Enter your phone number: ");
  scanf("%s", resume.phone);

  printf("Enter your work experience: ");
  scanf("%s", resume.experience);

  printf("Enter your educational background: ");
  scanf("%s", resume.education);

  printf("Enter your skills: ");
  scanf("%s", resume.skills);

  printf("\n\nName: %s", resume.name);
  printf("Age: %d\n", resume.age);
  printf("Email: %s\n", resume.email);
  printf("Phone: %s\n", resume.phone);
  printf("Experience: %s\n", resume.experience);
  printf("Education: %s\n", resume.education);
  printf("Skills: %s\n", resume.skills);
  
  return 0;
}