//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: ephemeral
#include <stdio.h>
#include <string.h>

#define MAX_RESUME_LENGTH 2000
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_SKILLS_LENGTH 500

typedef struct {
  char name[MAX_NAME_LENGTH];
  char email[MAX_EMAIL_LENGTH];
  char skills[MAX_SKILLS_LENGTH];
} Resume;

Resume parseResume(char resumeText[]) {
  Resume resume = {"", "", ""};
  int i = 0;
  
  // parse name
  int j = 0;
  while (resumeText[i] != '\n') {
    resume.name[j] = resumeText[i];
    i++; j++;
  }
  resume.name[j] = '\0';
  i++;
  
  // parse email
  j = 0;
  while (resumeText[i] != '\n') {
    resume.email[j] = resumeText[i];
    i++; j++;
  }
  resume.email[j] = '\0';
  i++;
  
  // parse skills
  j = 0;
  while (resumeText[i] != '\0') {
    resume.skills[j] = resumeText[i];
    i++; j++;
  }
  resume.skills[j] = '\0';
  
  return resume;
}

int main() {
  char resumeText[MAX_RESUME_LENGTH] = "John Doe\njohndoe@example.com\nProgramming: Java, Python\nWeb Development: HTML, CSS, JavaScript";
  
  Resume resume = parseResume(resumeText);
  
  printf("Name: %s\n", resume.name);
  printf("Email: %s\n", resume.email);
  printf("Skills:\n%s\n", resume.skills);
  
  return 0;
}