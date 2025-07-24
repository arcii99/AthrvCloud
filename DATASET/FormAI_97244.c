//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *firstName;
  char *lastName;
  char *email;
  char *phone;
  char *education;
  char *experience;
} Resume;

Resume *parseResume(char *resumeText) {
  Resume *newResume = malloc(sizeof(Resume));

  char *line = strtok(resumeText, "\n");

  while (line != NULL) {
    char *attribute = strtok(line, ":");
    char *value = strtok(NULL, "\n");

    if (strcmp(attribute, "First Name") == 0) {
      newResume->firstName = value;
    } else if (strcmp(attribute, "Last Name") == 0) {
      newResume->lastName = value;
    } else if (strcmp(attribute, "Email") == 0) {
      newResume->email = value;
    } else if (strcmp(attribute, "Phone") == 0) {
      newResume->phone = value;
    } else if (strcmp(attribute, "Education") == 0) {
      newResume->education = value;
    } else if (strcmp(attribute, "Experience") == 0) {
      newResume->experience = value;
    }

    line = strtok(NULL, "\n");
  }

  return newResume;
}

int main() {
  // Example resume text
  char *resumeText =
    "First Name: John\n"
    "Last Name: Doe\n"
    "Email: john.doe@example.com\n"
    "Phone: 555-1234\n"
    "Education: B.S. Computer Science, XYZ University\n"
    "Experience: Software Engineer, ABC Corp.";

  Resume *resume = parseResume(resumeText);

  printf("First Name: %s\n", resume->firstName);
  printf("Last Name: %s\n", resume->lastName);
  printf("Email: %s\n", resume->email);
  printf("Phone: %s\n", resume->phone);
  printf("Education: %s\n", resume->education);
  printf("Experience: %s\n", resume->experience);

  return 0;
}