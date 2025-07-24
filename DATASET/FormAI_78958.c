//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct resume {
  char name[50];
  char email[50];
  char education[50];
  char experience[100];
}resume;

int main() {
  FILE *fresume;
  fresume = fopen("resume.txt", "r");
  
  if (fresume == NULL) {
    printf("Sorry, the file could not be opened.");
    return 1;
  } else {
    char line[100];
    int count = 0;
    while(fgets(line, sizeof(line), fresume)) {
      if(count == 0) {
        strcpy(resume.name, line);
      } else if(count == 1) {
        strcpy(resume.email, line);
      } else if(count == 2) {
        strcpy(resume.education, line);
      } else {
        strcat(resume.experience, line);
      }
      count++;
    }
    
    printf("Name: %s", resume.name);
    printf("Email: %s", resume.email);
    printf("Education: %s", resume.education);
    printf("Experience: %s", resume.experience);
    
    fclose(fresume);
  }

  return 0;
}