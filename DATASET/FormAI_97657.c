//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Resume {
  char name[100];
  char email[100];
  char phone[20];
  char skills[500];
  char experience[500];
  char education[500];
};

void readResumeFromFile(char filename[], struct Resume *resume);
void parseResume(struct Resume *resume);
void printResume(struct Resume *resume);

int main() {
  char filename[] = "resume.txt";
  struct Resume resume;
  readResumeFromFile(filename, &resume);
  parseResume(&resume);
  printResume(&resume);
  return 0;
}

void readResumeFromFile(char filename[], struct Resume *resume) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Could not open file %s\n", filename);
    exit(1);
  }
  char line[500];
  while (fgets(line, 500, fp) != NULL) {
    if (strstr(line, "Name")) {
      sscanf(line, "Name: %s", resume->name);
    } else if (strstr(line, "Email")) {
      sscanf(line, "Email: %s", resume->email);
    } else if (strstr(line, "Phone")) {
      sscanf(line, "Phone: %s", resume->phone);
    } else if (strstr(line, "Skills")) {
      sscanf(line, "Skills: %[^\n]", resume->skills);
    } else if (strstr(line, "Experience")) {
      sscanf(line, "Experience: %[^\n]", resume->experience);
    } else if (strstr(line, "Education")) {
      sscanf(line, "Education: %[^\n]", resume->education);
    }
  }
  fclose(fp);
}

void parseResume(struct Resume *resume) {
  char *p, *q;
  p = strchr(resume->skills, ',');
  while (p != NULL) {
    q = p;
    while (*q == ' ') {
      q++;
    }
    memmove(p + 1, q, strlen(q) + 1);
    *p++ = ',';
    while (*p == ' ') {
      p++;
    }
    p = strchr(p, ',');
  }
  p = strchr(resume->experience, '.');
  if (p != NULL) {
    *p = '\0';
  }
}

void printResume(struct Resume *resume) {
  printf("Name: %s\n", resume->name);
  printf("Email: %s\n", resume->email);
  printf("Phone: %s\n", resume->phone);
  printf("Skills: %s\n", resume->skills);
  printf("Experience: %s\n", resume->experience);
  printf("Education: %s\n", resume->education);
}