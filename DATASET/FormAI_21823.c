//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: lively
#include <stdio.h>
#include <string.h>

#define MAX_RESUME_SIZE 1000
#define MAX_KEYWORDS 100
#define MAX_MATCHES 100

void parse_resume(char* resume, char** keywords, int num_keywords) {
  char* matches[MAX_MATCHES];
  int num_matches = 0;
  
  for (int i = 0; i < num_keywords; i++) {
    char* keyword = keywords[i];
    char* location = strstr(resume, keyword);
    while (location != NULL) {
      matches[num_matches++] = location;
      location = strstr(location + 1, keyword);
    }
  }
  
  printf("MATCHED KEYWORDS:\n");
  
  for (int i = 0; i < num_matches; i++) {
    char* match = matches[i];
    for (int j = 0; j < strlen(match); j++) {
      if (match[j] == '\n') {
        match[j] = ' ';
      }
    }
    printf("%s\n", match);
  }
}

int main() {
  char resume[MAX_RESUME_SIZE];
  char* keywords[MAX_KEYWORDS];

  keywords[0] = "C";
  keywords[1] = "C++";
  keywords[2] = "Java";
  int num_keywords = 3;

  printf("Enter resume (max %d characters):\n", MAX_RESUME_SIZE);
  fgets(resume, MAX_RESUME_SIZE, stdin);
  
  parse_resume(resume, keywords, num_keywords);
  
  return 0;
}