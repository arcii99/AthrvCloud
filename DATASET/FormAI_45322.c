//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for storing resume data
typedef struct resume {
  char name[100];
  char email[100];
  char phone[20];
  char education[100];
  char skills[1000];
} Resume;

// Define the function for parsing the resume data
void parseResume(char* file) {
  FILE* fp;
  fp = fopen(file, "r");

  if (fp == NULL) {
    printf("Error: cannot open file\n");
    exit(1);
  }

  Resume r;
  char line[1000];

  while (fgets(line, sizeof(line), fp)) {
    if (strstr(line, "Name:")) {
      char* token = strtok(line, " ");
      token = strtok(NULL, "");
      strcpy(r.name, token);
    } else if (strstr(line, "Email:")) {
      char* token = strtok(line, " ");
      token = strtok(NULL, "");
      strcpy(r.email, token);
    } else if (strstr(line, "Phone:")) {
      char* token = strtok(line, " ");
      token = strtok(NULL, "");
      strcpy(r.phone, token);
    } else if (strstr(line, "Education:")) {
      char* token = strtok(line, " ");
      token = strtok(NULL, "");
      strcpy(r.education, token);
    } else if (strstr(line, "Skills:")) {
      char* token = strtok(line, " ");
      token = strtok(NULL, "");
      strcpy(r.skills, token);

      while (fgets(line, sizeof(line), fp)) { // Continue to add skills until the end of the file
        if (strstr(line, "Name:") || strstr(line, "Email:") || strstr(line, "Phone:") || strstr(line, "Education:")) {
          fseek(fp, -strlen(line), SEEK_CUR); // Go back to the beginning of the next field
          break;
        } else {
          strcat(r.skills, line);
        }
      }
    }
  }

  fclose(fp);

  // Print out the resume data
  printf("Name: %s\n", r.name);
  printf("Email: %s\n", r.email);
  printf("Phone: %s\n", r.phone);
  printf("Education: %s\n", r.education);
  printf("Skills: %s\n", r.skills);
}

int main() {
  parseResume("resume.txt");

  return 0;
}