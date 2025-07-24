//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Metadata {
  char title[50];
  char author[50];
  char description[100];
  int year;
};

int main() {
  struct Metadata data;

  printf("Let's extract metadata from a file!\n");
  printf("Enter the title of the file: ");
  fgets(data.title, 50, stdin);
  data.title[strcspn(data.title, "\n")] = 0;

  printf("Enter the author of the file: ");
  fgets(data.author, 50, stdin);
  data.author[strcspn(data.author, "\n")] = 0;

  printf("Enter a brief description of the file: ");
  fgets(data.description, 100, stdin);
  data.description[strcspn(data.description, "\n")] = 0;

  printf("Enter the year of publication: ");
  scanf("%d", &data.year);

  printf("\n\nMetadata for the file '%s':\n", data.title);
  printf("Author: %s\n", data.author);
  printf("Description: %s\n", data.description);
  printf("Year: %d\n", data.year);

  return 0;
}