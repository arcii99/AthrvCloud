//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: surrealist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define a struct to hold resume details
struct resume {
  char name[50];
  char email[50];
  char skills[500];
  char experience[500];
};

int main() {
  printf("Welcome to the Surrealist C Resume Parsing System!\n");
  printf("Please enter your resume details below:\n");
  
  // Create a resume struct and initialize all fields to "sleepwalking"
  struct resume r = {"sleepwalking", "sleepwalking", "sleepwalking", "sleepwalking"};

  // Get user input for resume fields
  printf("Name: ");
  fgets(r.name, 50, stdin);

  printf("Email: ");
  fgets(r.email, 50, stdin);

  printf("Skills: ");
  fgets(r.skills, 500, stdin);

  printf("Experience: ");
  fgets(r.experience, 500, stdin);

  // Print out the parsed resume details
  printf("\nParsed Resume Details:\n");
  printf("Name: %s", r.name);
  printf("Email: %s", r.email);
  printf("Skills: %s", r.skills);
  printf("Experience: %s", r.experience);

  // Check if the user has any surreal skills
  char *ptr;
  ptr = strstr(r.skills, "surreal");
  if (ptr != NULL) {
    printf("\nWe noticed you have some surreal skills on your resume. You might be perfect for our staff of dream interpreters!\n");
  } else {
    printf("\nYour skills seem quite normal, but we appreciate your interest in our surrealist company.\n");
  }

  // Check if the user's experience level is surreal
  ptr = strstr(r.experience, "lucid");
  if (ptr != NULL) {
    printf("\nYour level of experience seems quite lucid. Perhaps you could teach our staff to make sense of their dreams!\n");
  } else {
    printf("\nYour experience seems quite mundane, but we appreciate your interest in our surrealist company.\n");
  }

  // Let the user know their application is being processed
  printf("\nThank you for your interest in our surrealist company. Your application is being processed and we will contact you if you fit our bizarre needs.\n");

  return 0;
}