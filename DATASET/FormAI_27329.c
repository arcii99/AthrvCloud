//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Resume {
   char name[50];
   char email[50];
   char education[100];
   char skills[200];
};

void parseResume(char buffer[], struct Resume *resume);

int main() {
   char buffer[500] = "Name: John Doe\nEmail: john.doe@email.com\nEducation: Bachelor of Science in Computer Science\nSkills: C++, Java, Python";
   struct Resume resume;
   parseResume(buffer, &resume);
   printf("Name: %s\nEmail: %s\nEducation: %s\nSkills: %s", resume.name, resume.email, resume.education, resume.skills);
   return 0;
}

void parseResume(char buffer[], struct Resume *resume) {
   char *token = strtok(buffer, "\n");
   while (token != NULL) {
      if (strstr(token, "Name: ") != NULL) {
         strcpy(resume->name, token + 6);
      }
      else if (strstr(token, "Email: ") != NULL) {
         strcpy(resume->email, token + 7);
      }
      else if (strstr(token, "Education: ") != NULL) {
         strcpy(resume->education, token + 11);
      }
      else if (strstr(token, "Skills: ") != NULL) {
         strcpy(resume->skills, token + 8);
      }
      token = strtok(NULL, "\n");
   }
}