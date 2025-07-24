//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: medieval
/* Welcome to the Medieval C Resume Parsing System! */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define structure for resume data */
typedef struct {
  char* name;
  int age;
  char* skills;
  char* experience;
} Resume;

/* Function to parse resume data */
Resume* parseResume(char* file_contents) {
  /* Create new resume object */
  Resume* resume = malloc(sizeof(Resume));

  /* Extract name from file_contents */
  char* name_start = strstr(file_contents, "Name:");
  char* name_end = strstr(name_start, "\n");
  int name_length = name_end - (name_start + 6);
  resume->name = malloc(name_length + 1);
  strncpy(resume->name, name_start + 6, name_length);
  resume->name[name_length] = '\0';

  /* Extract age from file_contents */
  char* age_start = strstr(file_contents, "Age:");
  char* age_end = strstr(age_start, "\n");
  char age_string[3];
  strncpy(age_string, age_start + 4, age_end - (age_start + 4));
  resume->age = atoi(age_string);

  /* Extract skills from file_contents */
  char* skills_start = strstr(file_contents, "Skills:");
  char* skills_end = strstr(skills_start, "\nExperience:");
  int skills_length = skills_end - (skills_start + 8);
  resume->skills = malloc(skills_length + 1);
  strncpy(resume->skills, skills_start + 8, skills_length);
  resume->skills[skills_length] = '\0';

  /* Extract experience from file_contents */
  char* experience_start = skills_end + 12;
  char* experience_end = strstr(experience_start, "\n\n");
  int experience_length = experience_end - experience_start;
  resume->experience = malloc(experience_length + 1);
  strncpy(resume->experience, experience_start, experience_length);
  resume->experience[experience_length] = '\0';

  /* Return parsed resume data */
  return resume;
}

/* Function to display resume data */
void displayResume(Resume* resume) {
  printf("Name: %s\n", resume->name);
  printf("Age: %d\n", resume->age);
  printf("Skills: %s\n", resume->skills);
  printf("Experience: %s\n", resume->experience);
}

int main() {
  /* Load resume data from file */
  FILE* file_pointer = fopen("resume.txt", "r");
  int file_length = fseek(file_pointer, 0L, SEEK_END);
  file_length = ftell(file_pointer);
  fseek(file_pointer, 0L, SEEK_SET);
  char* file_contents = malloc(file_length + 1);
  fread(file_contents, 1, file_length, file_pointer);
  fclose(file_pointer);

  /* Parse resume data */
  Resume* resume = parseResume(file_contents);

  /* Display resume data */
  displayResume(resume);

  /* Free allocated memory */
  free(resume->name);
  free(resume->skills);
  free(resume->experience);
  free(resume);
  free(file_contents);

  return 0;
}