//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: retro
#include <stdio.h>
#include <string.h>

struct Resume {
   char name[50];
   char email[50];
   char phone[20];
   char education[100];
   char experience[500];
   char skills[200];
} resume;

int main() {
   char input[1000];

   // Prompt user to enter resume details
   printf("Please enter your full name:\n");
   fgets(input, sizeof(input), stdin);
   strncpy(resume.name, input, sizeof(resume.name));

   printf("Please enter your email address:\n");
   fgets(input, sizeof(input), stdin);
   strncpy(resume.email, input, sizeof(resume.email));

   printf("Please enter your phone number:\n");
   fgets(input, sizeof(input), stdin);
   strncpy(resume.phone, input, sizeof(resume.phone));

   printf("Please enter your educational history:\n");
   fgets(input, sizeof(input), stdin);
   strncpy(resume.education, input, sizeof(resume.education));

   printf("Please enter your work experience:\n");
   fgets(input, sizeof(input), stdin);
   strncpy(resume.experience, input, sizeof(resume.experience));

   printf("Please enter your skills and qualifications:\n");
   fgets(input, sizeof(input), stdin);
   strncpy(resume.skills, input, sizeof(resume.skills));

   // Print out parsed resume details
   printf("\n--- Resume Parsing Results ---\n");
   printf("Name: %s", resume.name);
   printf("Email: %s", resume.email);
   printf("Phone: %s", resume.phone);
   printf("Education: %s", resume.education);
   printf("Experience: %s", resume.experience);
   printf("Skills: %s\n", resume.skills);

   return 0;
}