//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: relaxed
// C Resume Parsing System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUMES 100 // maximum number of resumes

typedef struct {
  char firstName[50];
  char lastName[50];
  char email[100];
  char phone[20];
  char school[100];
  char degree[100];
  char experience[500];
} Resume;

Resume resumes[MAX_RESUMES]; // array of resumes
int numResumes = 0; // current number of resumes in the array

// function to parse a resume and add it to the array
void parseResume(char* resumeText) {
  // split the resume text into tokens
  char* token;
  token = strtok(resumeText, "\n");
  int numLines = 0;
  Resume newResume;
  while (token != NULL) {
    numLines++;
    // set the correct field in the new resume
    switch (numLines) {
      case 1:
        strcpy(newResume.firstName, token);
        break;
      case 2:
        strcpy(newResume.lastName, token);
        break;
      case 3:
        strcpy(newResume.email, token);
        break;
      case 4:
        strcpy(newResume.phone, token);
        break;
      case 5:
        strcpy(newResume.school, token);
        break;
      case 6:
        strcpy(newResume.degree, token);
        break;
      case 7:
        strcpy(newResume.experience, token);
        break;
      default:
        printf("Unrecognized field in resume!\n");
    }
    // get the next token
    token = strtok(NULL, "\n");
  }
  // add the new resume to the array
  resumes[numResumes] = newResume;
  numResumes++;
}

// function to print all the resumes in the array
void printResumes() {
  for (int i = 0; i < numResumes; i++) {
    printf("Resume %d:\n", i+1);
    printf("Name: %s %s\n", resumes[i].firstName, resumes[i].lastName);
    printf("Email: %s\n", resumes[i].email);
    printf("Phone: %s\n", resumes[i].phone);
    printf("School: %s\n", resumes[i].school);
    printf("Degree: %s\n", resumes[i].degree);
    printf("Experience: %s\n", resumes[i].experience);
    printf("==============================\n");
  }
}

// main function to test the resume parsing system
int main() {
  printf("Welcome to the Resume Parsing System!\n");
  while (1) {
    printf("Please enter a resume (or 'q' to quit):\n");
    char input[500];
    fgets(input, 500, stdin);
    if (input[0] == 'q') {
      break;
    }
    parseResume(input);
  }
  printf("Here are all the resumes:\n");
  printResumes();
  return 0;
}