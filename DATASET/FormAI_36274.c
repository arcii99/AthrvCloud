//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Resume {
  char name[50];
  char email[50];
  char phone_number[15];
  char education[100];
  char experience[200];
  char skills[200];
};

void parse_resume(char* file_name) {
  FILE* file = fopen(file_name, "r");
  if (file == NULL) {
    printf("Failed to open the file.\n");
    return;
  }

  char buffer[100];
  struct Resume resume;
  memset(&resume, 0, sizeof(struct Resume));

  while(fgets(buffer, sizeof(buffer), file)) {
    if (strstr(buffer, "Name:")) {
      sscanf(buffer, "Name: %s", resume.name);
    } else if (strstr(buffer, "Email:")) {
      sscanf(buffer, "Email: %s", resume.email);
    } else if (strstr(buffer, "Phone Number:")) {
      sscanf(buffer, "Phone Number: %s", resume.phone_number);
    } else if (strstr(buffer, "Education:")) {
      sscanf(buffer, "Education: %[^\n]", resume.education);
    } else if (strstr(buffer, "Experience:")) {
      sscanf(buffer, "Experience: %[^\n]", resume.experience);
    } else if (strstr(buffer, "Skills:")) {
      sscanf(buffer, "Skills: %[^\n]", resume.skills);
    }
  }

  fclose(file);

  printf("Name: %s\n", resume.name);
  printf("Email: %s\n", resume.email);
  printf("Phone Number: %s\n", resume.phone_number);
  printf("Education: %s\n", resume.education);
  printf("Experience: %s\n", resume.experience);
  printf("Skills: %s\n", resume.skills);
}

int main() {
  parse_resume("./example_resume.txt");
  return 0;
}