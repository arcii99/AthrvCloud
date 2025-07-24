//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: minimalist
#include <stdio.h>
#include <string.h>

struct Resume {
  char name[50];
  char email[50];
  char phone[20];
  char experience[200];
  char skills[200];
} resume;

int main() {
  char resume_text[1000];
  printf("Paste your resume text here:\n");
  fgets(resume_text, 1000, stdin);
  
  // Extract name from resume text
  char *name_start = strstr(resume_text, "Name:");
  strcpy(resume.name, strtok(name_start+6, "\n"));

  // Extract email from resume text
  char *email_start = strstr(resume_text, "Email:");
  strcpy(resume.email, strtok(email_start+7, "\n"));

  // Extract phone number from resume text
  char *phone_start = strstr(resume_text, "Phone:");
  strcpy(resume.phone, strtok(phone_start+7, "\n"));

  // Extract experience from resume text
  char *experience_start = strstr(resume_text, "Experience:");
  strcpy(resume.experience, strtok(experience_start+12, "\n"));

  // Extract skills from resume text
  char *skills_start = strstr(resume_text, "Skills:");
  strcpy(resume.skills, strtok(skills_start+8, "\n"));

  // Print the parsed resume
  printf("Name: %s\n", resume.name);
  printf("Email: %s\n", resume.email);
  printf("Phone: %s\n", resume.phone);
  printf("Experience: %s\n", resume.experience);
  printf("Skills: %s\n", resume.skills);

  return 0;
}