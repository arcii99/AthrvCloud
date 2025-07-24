//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define constants for the maximum length of resume fields */
#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100
#define MAX_EMAIL_LENGTH 50
#define MAX_EDUCATION_LENGTH 100
#define MAX_EXPERIENCE_LENGTH 200

/* Define function prototypes */
void parse_resume(char *name, char *address, char *email, char *education, char *experience);

int main() {
  /* Initialize variables for each resume field */
  char name[MAX_NAME_LENGTH];
  char address[MAX_ADDRESS_LENGTH];
  char email[MAX_EMAIL_LENGTH];
  char education[MAX_EDUCATION_LENGTH];
  char experience[MAX_EXPERIENCE_LENGTH];

  /* Prompt user for resume information */
  printf("Please enter the following information from your resume:\n");
  printf("Name: ");
  fgets(name, MAX_NAME_LENGTH, stdin);
  printf("Address: ");
  fgets(address, MAX_ADDRESS_LENGTH, stdin);
  printf("Email: ");
  fgets(email, MAX_EMAIL_LENGTH, stdin);
  printf("Education: ");
  fgets(education, MAX_EDUCATION_LENGTH, stdin);
  printf("Experience: ");
  fgets(experience, MAX_EXPERIENCE_LENGTH, stdin);

  /* Parse the resume */
  parse_resume(name, address, email, education, experience);

  return 0;
}

void parse_resume(char *name, char *address, char *email, char *education, char *experience) {
  /* Initialize variables for parsing information */
  char *name_tokens[MAX_NAME_LENGTH];
  char *address_tokens[MAX_ADDRESS_LENGTH];
  char *email_tokens[MAX_EMAIL_LENGTH];
  char *education_tokens[MAX_EDUCATION_LENGTH];
  char *experience_tokens[MAX_EXPERIENCE_LENGTH];

  /* Tokenize each field of the resume */
  int name_token_count = 0;
  name_tokens[name_token_count] = strtok(name, " \n");
  while (name_tokens[name_token_count] != NULL) {
    name_token_count++;
    name_tokens[name_token_count] = strtok(NULL, " \n");
  }

  int address_token_count = 0;
  address_tokens[address_token_count] = strtok(address, ",\n");
  while (address_tokens[address_token_count] != NULL) {
    address_token_count++;
    address_tokens[address_token_count] = strtok(NULL, ",\n");
  }

  int email_token_count = 0;
  email_tokens[email_token_count] = strtok(email, "@\n");
  while (email_tokens[email_token_count] != NULL) {
    email_token_count++;
    email_tokens[email_token_count] = strtok(NULL, "@\n");
  }

  int education_token_count = 0;
  education_tokens[education_token_count] = strtok(education, ",\n");
  while (education_tokens[education_token_count] != NULL) {
    education_token_count++;
    education_tokens[education_token_count] = strtok(NULL, ",\n");
  }

  int experience_token_count = 0;
  experience_tokens[experience_token_count] = strtok(experience, ".\n");
  while (experience_tokens[experience_token_count] != NULL) {
    experience_token_count++;
    experience_tokens[experience_token_count] = strtok(NULL, ".\n");
  }

  /* Print out the parsed information */
  printf("\nResume Parsing Results:\n");
  printf("Name: ");
  for (int i = 0; i < name_token_count; i++) {
    printf("%s ", name_tokens[i]);
  }
  printf("\n");

  printf("Address: ");
  for (int i = 0; i < address_token_count; i++) {
    printf("%s ", address_tokens[i]);
  }
  printf("\n");

  printf("Email: ");
  for (int i = 0; i < email_token_count; i++) {
    printf("%s@", email_tokens[i]);
  }
  printf("\n");

  printf("Education: ");
  for (int i = 0; i < education_token_count; i++) {
    printf("%s ", education_tokens[i]);
  }
  printf("\n");

  printf("Experience: ");
  for (int i = 0; i < experience_token_count; i++) {
    printf("%s. ", experience_tokens[i]);
  }
  printf("\n");
}