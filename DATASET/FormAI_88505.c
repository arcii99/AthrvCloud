//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct resume {
  char name[50];
  char address[100];
  char email[50];
  char phone[20];
  char education[100];
  char experience[100];
};

int main() {
  printf("Welcome to the Resume Parsing System! \n");

  printf("Please enter the applicant's name: \n");
  char name[50];
  fgets(name, 50, stdin);
  strtok(name, "\n"); // remove trailing newline

  printf("Please enter the applicant's address: \n");
  char address[100];
  fgets(address, 100, stdin);
  strtok(address, "\n"); // remove trailing newline

  printf("Please enter the applicant's email: \n");
  char email[50];
  fgets(email, 50, stdin);
  strtok(email, "\n"); // remove trailing newline

  printf("Please enter the applicant's phone number: \n");
  char phone[20];
  fgets(phone, 20, stdin);
  strtok(phone, "\n"); // remove trailing newline

  printf("Please enter the applicant's education: \n");
  char education[100];
  fgets(education, 100, stdin);
  strtok(education, "\n"); // remove trailing newline

  printf("Please enter the applicant's experience: \n");
  char experience[100];
  fgets(experience, 100, stdin);
  strtok(experience, "\n"); // remove trailing newline

  struct resume applicant;
  strcpy(applicant.name, name);
  strcpy(applicant.address, address);
  strcpy(applicant.email, email);
  strcpy(applicant.phone, phone);
  strcpy(applicant.education, education);
  strcpy(applicant.experience, experience);

  printf("Thank you for entering the applicant's information. \n");
  printf("Now parsing the resume... \n\n");

  if (strcmp(applicant.name, "") == 0 || strcmp(applicant.address, "") == 0 || strcmp(applicant.email, "") == 0 || strcmp(applicant.phone, "") == 0 || strcmp(applicant.education, "") == 0 || strcmp(applicant.experience, "") == 0) {
    printf("Error: One or more fields are empty. Please try again. \n");
    return 1;
  }

  printf("========================\n");
  printf("Name: %s \n", applicant.name);
  printf("Address: %s \n", applicant.address);
  printf("Email: %s \n", applicant.email);
  printf("Phone: %s \n", applicant.phone);
  printf("Education: %s \n", applicant.education);
  printf("Experience: %s \n", applicant.experience);
  printf("========================\n");

  printf("Resume parsed successfully! \n");

  return 0;
}