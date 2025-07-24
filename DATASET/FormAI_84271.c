//FormAI DATASET v1.0 Category: Ebook reader ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE* ebook = fopen("ebook.txt", "r");

  if (ebook == NULL) {
    printf("Error: Failed to open ebook\n");
    exit(1);
  }

  printf("Welcome to Ken's Ebook Reader!\n");
  printf("Press any key to start reading.\n");
  getchar();

  char page[256];
  int page_num = 1;
  int c = getc(ebook);

  while (c != EOF) {
    int i = 0;
    while (i < 255 && c != '\n') {
      page[i] = c;
      c = getc(ebook);
      i++;
    }
    page[i] = '\0';

    printf("Page %d:\n", page_num);
    printf("%s\n", page);

    printf("Press 'n' for next page, 'q' to quit.\n");

    char input = getchar();
    if (input == 'n') {
      page_num++;
    } else if (input == 'q') {
      printf("Exiting Ebook Reader.\n");
      break;
    } else {
      printf("Invalid input. Please try again.\n");
    }

    c = getc(ebook);
  }

  fclose(ebook);

  return 0;
}