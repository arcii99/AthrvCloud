//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Resume {
   char name[50];
   char email[50];
   char phone[20];
   char education[100];
   char experience[200];
   char skills[200];
};

struct Resume parseResume(char *resumeString) {
   struct Resume resume;
   char *token;

   token = strtok(resumeString, "\n");
   while (token != NULL) {
      if (strstr(token, "Name: ")) {
         strcpy(resume.name, token+6); 
      }
      else if (strstr(token, "Email: ")) {
         strcpy(resume.email, token+7); 
      }
      else if (strstr(token, "Phone: ")) {
         strcpy(resume.phone, token+7); 
      }
      else if (strstr(token, "Education: ")) {
         strcpy(resume.education, token+11); 
      }
      else if (strstr(token, "Experience: ")) {
         strcpy(resume.experience, token+12);
      }
      else if (strstr(token, "Skills: ")) {
         strcpy(resume.skills, token+8); 
      }
      token = strtok(NULL, "\n");
   }
   return resume;
}

void printResume(struct Resume resume) {
   printf("Name: %s\n", resume.name);
   printf("Email: %s\n", resume.email);
   printf("Phone: %s\n", resume.phone);
   printf("Education: %s\n", resume.education);
   printf("Experience: %s\n", resume.experience);
   printf("Skills: %s\n", resume.skills);
}

int main() {
   char resumeString[600] = "Name: John Doe\nEmail: john.doe@email.com\nPhone: 123-456-7890\nEducation: Bachelor's degree in Computer Science\nExperience: Software Engineer with 3 years of experience\nSkills: Java, C++, Python, SQL";

   struct Resume resume = parseResume(resumeString);
   printResume(resume);

   return 0;
}