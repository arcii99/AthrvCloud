//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Resume {
   char name[50];
   char email[50];
   char address[100];
   char phone[20];
   char education[100];
   char skills[100];
   char experience[500];
};

int main() {
   struct Resume resume;
   char input[500];

   printf("Enter your name: ");
   fgets(input, 50, stdin);
   strcpy(resume.name, input);
   
   printf("Enter your email: ");
   fgets(input, 50, stdin);
   strcpy(resume.email, input);

   printf("Enter your address: ");
   fgets(input, 100, stdin);
   strcpy(resume.address, input);

   printf("Enter your phone number: ");
   fgets(input, 20, stdin);
   strcpy(resume.phone, input);

   printf("Enter your education: ");
   fgets(input, 100, stdin);
   strcpy(resume.education, input);

   printf("Enter your skills: ");
   fgets(input, 100, stdin);
   strcpy(resume.skills, input);

   printf("Enter your experience: ");
   fgets(input, 500, stdin);
   strcpy(resume.experience, input);

   printf("\n\n---PARSED RESUME---\n");
   printf("Name: %s", resume.name);
   printf("Email: %s", resume.email);
   printf("Address: %s", resume.address);
   printf("Phone: %s", resume.phone);
   printf("Education: %s", resume.education);
   printf("Skills: %s", resume.skills);
   printf("Experience: %s", resume.experience);

   return 0;
}