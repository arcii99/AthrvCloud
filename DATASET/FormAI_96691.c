//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_LENGTH 20
#define MAX_EMAIL_LENGTH 50
#define MAX_UNIVERSITY_LENGTH 50
#define MAX_SKILLS_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char university[MAX_UNIVERSITY_LENGTH];
    char skills[MAX_SKILLS_LENGTH];
} Resume;

void parse_resume(char *input, Resume* output){
  char split_char[] = "|\n";
  char *token;
  token = strtok(input, split_char);
  strcpy(output->name, token);
  token = strtok(NULL, split_char);
  strcpy(output->email, token);
  token = strtok(NULL, split_char);
  strcpy(output->university, token);
  token = strtok(NULL, split_char);
  strcpy(output->skills, token);
}

int main(){
  char input[] = "John Doe|john.doe@email.com|University of California, Berkeley|Java, C++, Python\n";
  Resume output;
  parse_resume(input, &output);
  printf("Name: %s\n", output.name);
  printf("Email: %s\n", output.email);
  printf("University: %s\n", output.university);
  printf("Skills: %s\n", output.skills);
  return 0;
}