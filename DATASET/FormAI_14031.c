//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_NUMBER_OF_RESUMES 100

// Define the resume struct
typedef struct resume {
  char *name;
  char *email;
  char *phone;
  char *skills[MAX_BUFFER_SIZE];
  char *experience[MAX_BUFFER_SIZE];
  char *education[MAX_BUFFER_SIZE];
} Resume;

// Define the global array of resumes 
Resume resume_database[MAX_NUMBER_OF_RESUMES];

// Define the function to parse the resume
Resume *parse_resume(char *filename) {
  // Open the file for reading
  FILE *fp = fopen(filename, "r");

  // Allocate memory for the new resume
  Resume *new_resume = (Resume *)malloc(sizeof(Resume));
  char buffer[MAX_BUFFER_SIZE];

  // Read the name, email, and phone number
  fscanf(fp, "%s", buffer);
  new_resume->name = strdup(buffer);

  fscanf(fp, "%s", buffer);
  new_resume->email = strdup(buffer);

  fscanf(fp, "%s", buffer);
  new_resume->phone = strdup(buffer);

  // Read through the rest of the file and parse skills, experience, and education
  while (fgets(buffer, MAX_BUFFER_SIZE, fp)) {
    if (strncmp(buffer, "Skills:", 7) == 0) {
      // Parse the skills section
      char *token = strtok(buffer+8, ",");
      int idx = 0;
      while (token != NULL) {
        new_resume->skills[idx] = strdup(token);
        token = strtok(NULL, ",");
        idx++;
      }
    } else if (strncmp(buffer, "Experience:", 11) == 0) {
      // Parse the experience section
      char *token = strtok(buffer+12, ",");
      int idx = 0;
      while (token != NULL) {
        new_resume->experience[idx] = strdup(token);
        token = strtok(NULL, ",");
        idx++;
      }
    } else if (strncmp(buffer, "Education:", 10) == 0) {
      // Parse the education section
      char *token = strtok(buffer+11, ",");
      int idx = 0;
      while (token != NULL) {
        new_resume->education[idx] = strdup(token);
        token = strtok(NULL, ",");
        idx++;
      }
    }
  }

  // Close the file
  fclose(fp);

  // Return the new resume
  return new_resume;
}

// Define the function to search for a skill in the resume database
int search_for_skill(char *skill) {
  int count = 0;

  for (int i = 0; i < MAX_NUMBER_OF_RESUMES; i++) {
    if (resume_database[i].name != NULL) {
      for (int j = 0; j < MAX_BUFFER_SIZE; j++) {
        if (resume_database[i].skills[j] != NULL) {
          if (strncmp(resume_database[i].skills[j], skill, strlen(skill)) == 0) {
            count++;
          }
        }
      }
    }
  }

  return count;
}

// Define the main function
int main(void) {
  // Parse the resumes and add them to the resume database
  Resume *resume1 = parse_resume("resume1.txt");
  resume_database[0] = *resume1;

  Resume *resume2 = parse_resume("resume2.txt");
  resume_database[1] = *resume2;

  // Search for a specific skill in the resume database
  int count = search_for_skill("Java");

  // Print the number of resumes with the skill
  printf("Number of resumes with Java skill: %d\n", count);

  return 0;
}