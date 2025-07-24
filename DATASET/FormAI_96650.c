//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: careful
#include <stdio.h>
#include <string.h>

#define MAX_RESUME_SIZE 10000
#define MAX_KEYWORDS 20

char resume[MAX_RESUME_SIZE];
char keywords[MAX_KEYWORDS][50] = {"C++", "Java", "Python", "Ruby", "JavaScript", "PHP", "HTML", "CSS", "Node.js", "AngularJS", "React", "Redux", "SQL", "MongoDB", "Git", "GitHub", "Agile", "Scrum", "RESTful", "API"};

int main() {
  printf("Welcome to the Resume Parsing System!\n");
  printf("Please paste your resume below:\n");

  // Read in the entire resume
  fgets(resume, MAX_RESUME_SIZE, stdin);

  // Convert entire resume to lowercase
  for(int i = 0; i < strlen(resume); i++) {
    resume[i] = tolower(resume[i]);
  }

  printf("Here are the keywords detected in your resume:\n");

  // Check for each keyword in the resume and print if found
  for(int i = 0; i < MAX_KEYWORDS; i++) {
    if(strstr(resume, keywords[i]) != NULL) {
      printf("- %s\n", keywords[i]);
    }
  }

  printf("Thank you for using the Resume Parsing System!\n");

  return 0;
}