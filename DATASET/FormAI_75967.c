//FormAI DATASET v1.0 Category: Ebook reader ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_PAGES 1000

typedef struct {
  char title[MAX_TITLE_LENGTH];
  int num_pages;
  char** pages;
} Ebook;

Ebook* create_ebook(char* title, int num_pages) {
  Ebook* ebook = (Ebook*)malloc(sizeof(Ebook));
  if (!ebook) {
    printf("Error: unable to allocate memory for Ebook.\n");
    exit(1);
  }
  strncpy(ebook->title, title, MAX_TITLE_LENGTH);
  ebook->num_pages = num_pages;
  ebook->pages = (char**)malloc(num_pages * sizeof(char*));
  if (!ebook->pages) {
    printf("Error: unable to allocate memory for Ebook pages.\n");
    exit(1);
  }
  for (int i = 0; i < num_pages; i++) {
    ebook->pages[i] = (char*)malloc(1024 * sizeof(char));
    if (!ebook->pages[i]) {
      printf("Error: unable to allocate memory for Ebook pages.\n");
      exit(1);
    }
  }
  return ebook;
}

void destroy_ebook(Ebook* ebook) {
  for (int i = 0; i < ebook->num_pages; i++) {
    free(ebook->pages[i]);
  }
  free(ebook->pages);
  free(ebook);
}

void load_ebook(Ebook* ebook, char* filename) {
  FILE* fp = fopen(filename, "r");
  if (!fp) {
    printf("Error: unable to open Ebook file.\n");
    exit(1);
  }
  for (int i = 0; i < ebook->num_pages; i++) {
    if (!fgets(ebook->pages[i], 1024, fp)) {
      printf("Error: unable to load Ebook page.\n");
      exit(1);
    }
  }
  fclose(fp);
}

void print_page(Ebook* ebook, int page_num) {
  if (page_num >= 0 && page_num < ebook->num_pages) {
    printf("%s", ebook->pages[page_num]);
  } else {
    printf("Error: page number %d out of bounds.\n", page_num);
  }
}

int main() {
  Ebook* ebook = create_ebook("My Great Ebook", MAX_PAGES);
  load_ebook(ebook, "ebook.txt");

  int page_num = 0;
  char input[10];
  while (strcmp(input, "quit") != 0) {
    printf("Current Page: %d\n", page_num);
    print_page(ebook, page_num);
    printf("Enter 'next', 'prev', or 'quit': ");
    scanf("%s", input);
    if (strcmp(input, "next") == 0) {
      if (page_num < ebook->num_pages - 1) {
        page_num++;
      } else {
        printf("Error: already on last page.\n");
      }
    } else if (strcmp(input, "prev") == 0) {
      if (page_num > 0) {
        page_num--;
      } else {
        printf("Error: already on first page.\n");
      }
    }
  }

  destroy_ebook(ebook);
  return 0;
}