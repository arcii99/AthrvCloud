//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000
#define MAX_WORDS 100

int main(int argc, char** argv) {

  char resume_data[BUFFER_SIZE];
  char *words[MAX_WORDS];
  int word_count = 0;

  // Read the entire resume into memory
  FILE* resume_file = fopen(argv[1], "r");
  if (!resume_file) {
    printf("File not found!\n");
    return -1;
  }

  fseek(resume_file, 0, SEEK_END);
  long file_size = ftell(resume_file);
  rewind(resume_file);

  fread(resume_data, sizeof(char), file_size, resume_file);
  fclose(resume_file);

  // Tokenize the resume data into individual words
  char* word = strtok(resume_data, " \n\r\t");
  while (word != NULL && word_count < MAX_WORDS) {
    words[word_count++] = word;
    word = strtok(NULL, " \n\r\t");
  }

  // Find skills section
  int i;
  for (i = 0; i < word_count; i++) {
    if (strcasecmp(words[i], "Skills") == 0) {
      break;
    }
  }

  if (i == word_count) {
    printf("Skills section not found!\n");
    return -1;
  }

  // Find all skills listed in the skills section
  int skill_count = 0;
  char skills[MAX_WORDS][BUFFER_SIZE];
  while (i < word_count) {
    if (words[i][0] == '-') {
      strcpy(skills[skill_count++], &words[i][1]);
    }
    i++;
  }

  // Print out the skills found
  printf("Skills Found:\n");
  for (i = 0; i < skill_count; i++) {
    printf("- %s\n", skills[i]);
  }

  return 0;
}