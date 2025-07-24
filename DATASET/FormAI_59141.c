//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct applicant {
   char name[20];
   char education[20];
   int experience;
};

int main() {
   struct applicant john = {"John Smith", "Bachelor's Degree", 3};
   struct applicant alex = {"Alex Johnson", "Master's Degree", 5};
   struct applicant mia = {"Mia Thomas", "Doctorate Degree", 7};
   struct applicant applicants[] = {john, alex, mia};
   int num_applicants = sizeof(applicants) / sizeof(applicants[0]);
   char search_name[20];
   printf("Enter the applicant name you want to search for:\n");
   scanf("%s", search_name);
   int i;
   for (i = 0; i < num_applicants; i++) {
      if (strcmp(search_name, applicants[i].name) == 0) {
         printf("Name: %s\n", applicants[i].name);
         printf("Education: %s\n", applicants[i].education);
         printf("Experience: %d years\n", applicants[i].experience);
         break;
      }
   }
   if (i == num_applicants) {
      printf("Applicant not found.\n");
   }
   return 0;
}