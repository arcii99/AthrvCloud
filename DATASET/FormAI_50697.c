//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Resume {
  char name[50];
  char email[50];
  char phone_num[20];
  char education[100];
  char skills[200];
} Resume;

void parseResume(char* filename) {
  Resume applicant;
  FILE *file = fopen(filename, "r");

  if (file == NULL) {
    printf("Unable to open file.\n");
    return;
  }

  char line[200];
  while (fgets(line, sizeof(line), file)) {
    // parse name
    if (strstr(line, "Name:")) {
      char* p = strtok(line, ":");
      p = strtok(NULL, "\n");
      strcpy(applicant.name, p);
    }

    // parse email
    if (strstr(line, "Email:")) {
      char* p = strtok(line, ":");
      p = strtok(NULL, "\n");
      strcpy(applicant.email, p);
    }

    // parse phone number
    if (strstr(line, "Phone:")) {
      char* p = strtok(line, ":");
      p = strtok(NULL, "\n");
      strcpy(applicant.phone_num, p);
    }

    // parse education
    if (strstr(line, "Education:")) {
      char* p = strtok(line, ":");
      p = strtok(NULL, "\n");
      strcpy(applicant.education, p);
    }

    // parse skills
    if (strstr(line, "Skills:")) {
      char* p = strtok(line, ":");
      p = strtok(NULL, "\n");
      strcpy(applicant.skills, p);
    }
  }

  fclose(file);

  // print parsed information
  printf("\nApplicant Name: %s\n", applicant.name);
  printf("Email: %s\n", applicant.email);
  printf("Phone Number: %s\n", applicant.phone_num);
  printf("Education: %s\n", applicant.education);
  printf("Skills: %s\n", applicant.skills);
}

int main() {
  parseResume("resume.txt");
  return 0;
}