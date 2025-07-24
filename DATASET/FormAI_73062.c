//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_RESUME_LENGTH 5000
#define MAX_KEYWORD_LENGTH 20
#define NUM_KEYWORDS 5

const char *KEYWORDS[NUM_KEYWORDS] = {"C", "Java", "Python", "JavaScript", "Ruby"};

bool isKeyword(const char *word) {
  for (int i = 0; i < NUM_KEYWORDS; i++) {
    if (!strcmp(word, KEYWORDS[i])) {
      return true;
    }
  }
  return false;
}

int main() {
  char resume[MAX_RESUME_LENGTH];
  printf("Please paste your resume below:\n");
  fgets(resume, MAX_RESUME_LENGTH, stdin);

  char buffer[MAX_KEYWORD_LENGTH];
  int i = 0;
  int num_keywords_found = 0;
  bool inside_word = false;

  for (int j = 0; j < MAX_RESUME_LENGTH; j++) {
    char c = resume[j];
    if (c == '\0' || c == '\n' || num_keywords_found == NUM_KEYWORDS) {
      buffer[i] = '\0';
      if (isKeyword(buffer)) {
        printf("FOUND KEYWORD: %s\n", buffer);
        num_keywords_found++;
      }
      i = 0;
      inside_word = false;
      if (c == '\n' || num_keywords_found == NUM_KEYWORDS) {
        break;
      }
    } else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
      if (i < MAX_KEYWORD_LENGTH) {
        buffer[i++] = c;
        inside_word = true;
      } else {
        // Keyword found that is too long!
        printf("PARSING ERROR: Keyword exceeded maximum length limit of %d characters\n", MAX_KEYWORD_LENGTH);
        exit(1);
      }
    } else {
      if (inside_word) {
        // End of keyword
        buffer[i] = '\0';
        if (isKeyword(buffer)) {
          printf("FOUND KEYWORD: %s\n", buffer);
          num_keywords_found++;
        }
      }
      i = 0;
      inside_word = false;
    }
  }

  if (num_keywords_found == NUM_KEYWORDS) {
    printf("PARSING SUCCESS: All keywords found!\n");
  } else {
    printf("PARSING FAILED: Missing keywords\n");
  }

  return 0;
}