//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Introduction
  printf("Greetings, traveler, and welcome to the C Antivirus scanner!\n\n");

  // File input
  char filename[50];
  printf("Please input the name of the file you wish to scan: ");
  scanf("%s", filename);

  // Virus check
  FILE *file = fopen(filename, "r");
  char line[1024];
  int virus = 0;

  while (fgets(line, 1024, file)) {
    if (strstr(line, "VIRUS") != NULL) {
      printf("Oh ho, it seems as if we have found a VIRUS!\n");
      virus = 1;
      break;
    }
  }

  if (!virus) {
    printf("Congratulations, traveler! Your file is free of any viruses.\n");
  }

  // Farewell
  printf("\nMay your files always be free of harm. Farewell for now, traveler!\n");

  return 0;
}