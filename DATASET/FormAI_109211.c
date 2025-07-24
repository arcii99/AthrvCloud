//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: surprised
#include <stdio.h>
#include <string.h>

int main() {
  char resume[] = "John Doe\n\nTechnical Skills:\nC++\nPython\nJava\n\nWork Experience:\nSoftware Engineer at IBM (3 years)\nSoftware Developer at Google (2 years)\n\nEducation:\nBachelor of Science in Computer Science, University of Michigan\n\n";

  // Extract name
  char* name = strtok(resume, "\n");
  printf("Name: %s\n\n", name);

  // Extract technical skills
  printf("Technical Skills:\n");
  char* skillsHeader = "Technical Skills:";
  char* skillsStart = strstr(resume, skillsHeader) + strlen(skillsHeader) + 1;
  char* skillsEnd = strstr(skillsStart, "\n\n");
  char* skills = strtok(skillsStart, "\n");
  while(skills != NULL && skills != skillsEnd) {
    printf("%s\n", skills);
    skills = strtok(NULL, "\n");
  }
  printf("\n");

  // Extract work experience
  printf("Work Experience:\n");
  char* workHeader = "Work Experience:";
  char* workStart = strstr(resume, workHeader) + strlen(workHeader) + 1;
  char* workEnd = strstr(workStart, "\n\n");
  char* work = strtok(workStart, "\n");
  while(work != NULL && work != workEnd) {
    printf("%s\n", work);
    work = strtok(NULL, "\n");
  }
  printf("\n");

  // Extract education
  printf("Education:\n");
  char* eduHeader = "Education:";
  char* eduStart = strstr(resume, eduHeader) + strlen(eduHeader) + 1;
  char* eduEnd = strstr(eduStart, "\n\n");
  char* edu = strtok(eduStart, "\n");
  while(edu != NULL && edu != eduEnd) {
    printf("%s\n", edu);
    edu = strtok(NULL, "\n");
  }
  printf("\n");

  return 0;
}