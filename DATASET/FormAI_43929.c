//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
  char* educationData[1000];
  char* experienceData[1000];
} Resume;

char* sanitizeString(char* str) {
  int length = strlen(str);
  char* buffer = (char*) malloc(length * sizeof(char));
  
  for (int i = 0; i < length; i++) {
    if (isalpha(str[i])) {
      buffer[i] = tolower(str[i]);
    } else {
      buffer[i] = ' ';
    }
  }
  
  return buffer;
}

void parseResume(Resume* resume, char* data) {
  char* token = strtok(data, ".");
  
  while (token != NULL) {
    char* cleaned = sanitizeString(token);
    
    if (strstr(cleaned, "education")) {
      resume->educationData[strlen(resume->educationData)] = cleaned;
    } else {
      resume->experienceData[strlen(resume->experienceData)] = cleaned;
    }
    
    token = strtok(NULL, ".");
  }
}

int main() {
  Resume resume;
  char* data = "Education: BSc Computer Science. Experience: Software Engineer at Google. Education: Masters in Data Science. Experience: Data Analyst at Netflix.";
  parseResume(&resume, data);
  
  printf("EDUCATION DATA:\n");
  for (int i = 0; i < strlen(*resume.educationData); i++) {
    printf("- %s\n", resume.educationData[i]);
  }
  
  printf("EXPERIENCE DATA:\n");
  for (int i = 0; i < strlen(*resume.experienceData); i++) {
    printf("- %s\n", resume.experienceData[i]);
  }
  
  return 0;
}