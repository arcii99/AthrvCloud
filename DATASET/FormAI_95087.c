//FormAI DATASET v1.0 Category: Ebook reader ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PAGES 2000
#define MAX_PAGE_SIZE 500

int main() {

  char ebook[MAX_PAGES][MAX_PAGE_SIZE]; // Array to store pages of ebook
  int num_pages = 0; // Number of pages in ebook
  int cur_page = 0; // Current page being displayed

  // Read ebook from file
  FILE *fp;
  fp = fopen("ebook.txt", "r");

  if (fp == NULL) {
    printf("Error: Could not open file for reading!");
    return 1;
  }

  while(fgets(ebook[num_pages], MAX_PAGE_SIZE, fp) != NULL) {
    num_pages++;
  }

  fclose(fp);

  // Begin ebook reader interface
  printf("Welcome to My Ebook Reader 1.0!\n");
  printf("Press 'n' for next page, 'p' for previous page, or 'q' to quit.\n");

  while(1) {
    printf("\nPage %d:\n", cur_page+1);

    for (int i = 0; i < strlen(ebook[cur_page]); i++) {
      if (ebook[cur_page][i] == '\n') {
        printf("\n");
      } else {
        printf("%c", ebook[cur_page][i]);
      }
    }

    char input = getchar();

    if (input == 'n') {
      if (cur_page == num_pages-1) {
        printf("End of book reached. Press 'q' to quit.\n");
      } else {
        cur_page++;
      }
    } else if (input == 'p') {
      if (cur_page == 0) {
        printf("This is the first page!\n");
      } else {
        cur_page--;
      }
    } else if (input == 'q') {
      printf("Thanks for reading!\n");
      break;
    } else {
      printf("Invalid input. Please try again.\n");
    }
  }

  return 0;
}