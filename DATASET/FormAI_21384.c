//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define constants
#define MAX_RESUMES 100
#define MAX_NAME_LENGTH 100
#define MAX_SKILLS 10
#define MAX_SKILL_LENGTH 20

// define struct for resume
typedef struct {
  char name[MAX_NAME_LENGTH];
  char skills[MAX_SKILLS][MAX_SKILL_LENGTH];
  int num_skills;
} Resume;

// function declarations
void addResume(Resume resumes[], int *num_resumes);
void printResumes(Resume resumes[], int num_resumes);
int findResume(Resume resumes[], int num_resumes, char name[]);

// main function
int main() {
  Resume resumes[MAX_RESUMES];
  int num_resumes = 0;
  int choice;

  do {
    printf("\n");
    printf("1. Add a resume\n");
    printf("2. Print all resumes\n");
    printf("3. Find a resume\n");
    printf("4. Exit\n");
    printf("\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        addResume(resumes, &num_resumes);
        break;
      case 2:
        printResumes(resumes, num_resumes);
        break;
      case 3: {
        char name[MAX_NAME_LENGTH];
        printf("Enter the name you want to find: ");
        scanf("%s", name);
        int index = findResume(resumes, num_resumes, name);
        if (index == -1) {
          printf("Resume not found.\n");
        } else {
          printf("Found resume at index %d.\n", index);
        }
        break;
      }
      case 4:
        printf("Goodbye.\n");
        break;
      default:
        printf("Invalid choice.\n");
        break;
    }
  } while (choice != 4);

  return 0;
}

// function for adding a resume
void addResume(Resume resumes[], int *num_resumes) {
  if (*num_resumes >= MAX_RESUMES) {
    printf("Maximum number of resumes reached.\n");
  } else {
    Resume r;
    printf("Enter name: ");
    scanf("%s", r.name);
    printf("Enter number of skills: ");
    scanf("%d", &r.num_skills);
    printf("Enter skills (separated by spaces): ");
    for (int i = 0; i < r.num_skills; i++) {
      scanf("%s", r.skills[i]);
    }
    resumes[*num_resumes] = r;
    (*num_resumes)++;
  }
}

// function for printing all resumes
void printResumes(Resume resumes[], int num_resumes) {
  if (num_resumes == 0) {
    printf("No resumes.\n");
  } else {
    printf("Resumes:\n");
    for (int i = 0; i < num_resumes; i++) {
      printf("%d. %s:", i + 1, resumes[i].name);
      for (int j = 0; j < resumes[i].num_skills; j++) {
        printf(" %s", resumes[i].skills[j]);
      }
      printf("\n");
    }
  }
}

// function for finding a resume by name
int findResume(Resume resumes[], int num_resumes, char name[]) {
  for (int i = 0; i < num_resumes; i++) {
    if (strcmp(resumes[i].name, name) == 0) {
      return i;
    }
  }
  return -1;
}