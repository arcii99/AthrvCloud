//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50

// Define a struct to hold information about a resume
struct Resume {
  char name[MAX_NAME_LENGTH];
  char email[MAX_EMAIL_LENGTH];
  char* experience;
  char* education;
};

// Declare a function to parse a line of the input file
struct Resume parseResumeLine(char line[]);

int main(int argc, char *argv[]) {
  // Ensure that the user has provided a filename as a command line argument
  if (argc < 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    exit(1);
  }

  // Open the input file for reading
  FILE* inputFile = fopen(argv[1], "r");
  if (inputFile == NULL) {
    perror("Error opening file");
    exit(1);
  }

  // Declare an array to hold the resumes
  const int MAX_RESUMES = 100;
  struct Resume resumes[MAX_RESUMES];
  int numResumes = 0;

  // Parse each line of the input file
  char line[MAX_LINE_LENGTH];
  while (fgets(line, MAX_LINE_LENGTH, inputFile)) {
    // Parse the current line and add the resulting Resume to the array
    struct Resume resume = parseResumeLine(line);
    resumes[numResumes] = resume;
    numResumes++;
  }

  // Close the input file
  fclose(inputFile);

  // Print out the resumes that were parsed
  printf("Parsed %d resumes:\n", numResumes);
  for (int i = 0; i < numResumes; i++) {
    struct Resume r = resumes[i];
    printf("%s <%s>\nExperience:\n%s\nEducation:\n%s\n\n", r.name, r.email, r.experience, r.education);
    free(r.experience);
    free(r.education);
  }

  return 0;
}

struct Resume parseResumeLine(char line[]) {
  // Declare a Resume struct to hold the data we parse from the line
  struct Resume resume;

  // Use strtok to split the line by commas
  char* name = strtok(line, ",");
  char* email = strtok(NULL, ",");
  char* experience = strtok(NULL, ",");
  char* education = strtok(NULL, ",");

  // Copy each value into the appropriate field of the Resume struct
  if (name != NULL) {
    strncpy(resume.name, name, MAX_NAME_LENGTH);
    resume.name[MAX_NAME_LENGTH - 1] = '\0';
  }
  if (email != NULL) {
    strncpy(resume.email, email, MAX_EMAIL_LENGTH);
    resume.email[MAX_EMAIL_LENGTH - 1] = '\0';
  }
  if (experience != NULL) {
    resume.experience = malloc(strlen(experience) + 1);
    strncpy(resume.experience, experience, strlen(experience));
    resume.experience[strlen(experience)] = '\0';
  }
  if (education != NULL) {
    resume.education = malloc(strlen(education) + 1);
    strncpy(resume.education, education, strlen(education));
    resume.education[strlen(education)] = '\0';
  }

  // Return the Resume struct
  return resume;
}