//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[50];
  char email[50];
  char phone[15];
  char skills[100];
  char education[100];
  char work_history[200];
} Resume;

void print_resume(Resume r);
void parse_resume(Resume *r, char *filename);

int main() {
  Resume my_resume;
  char file_name[] = "my_resume.txt";

  parse_resume(&my_resume, file_name);
  print_resume(my_resume);

  return 0;
}

/* 
 * This function prints out the contents of a Resume struct
 */
void print_resume(Resume r) {
  printf("Name: %s\n", r.name);
  printf("Email: %s\n", r.email);
  printf("Phone: %s\n", r.phone);
  printf("Skills: %s\n", r.skills);
  printf("Education: %s\n", r.education);
  printf("Work History: %s\n", r.work_history);
}

/* 
 * This function reads in a resume file and populates a Resume struct
 */
void parse_resume(Resume *r, char *filename) {
  FILE *file = fopen(filename, "r");

  if (file == NULL) {
    printf("Error opening file!\n");
    exit(1);
  }

  char buffer[200];

  fgets(buffer, 200, file);
  buffer[strcspn(buffer, "\n")] = 0; // remove newline character
  strcpy(r->name, buffer);

  fgets(buffer, 200, file);
  buffer[strcspn(buffer, "\n")] = 0;
  strcpy(r->email, buffer);

  fgets(buffer, 200, file);
  buffer[strcspn(buffer, "\n")] = 0;
  strcpy(r->phone, buffer);

  fgets(buffer, 200, file);
  buffer[strcspn(buffer, "\n")] = 0;
  strcpy(r->skills, buffer);

  fgets(buffer, 200, file);
  buffer[strcspn(buffer, "\n")] = 0;
  strcpy(r->education, buffer);

  fgets(buffer, 200, file);
  buffer[strcspn(buffer, "\n")] = 0;
  strcpy(r->work_history, buffer);

  fclose(file);
}