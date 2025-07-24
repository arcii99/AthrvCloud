//FormAI DATASET v1.0 Category: Ebook reader ; Style: surprised
#include <stdio.h>

int main() {

  printf("Wow, you're using the Unique C Ebook Reader!\n");

  // Initializing variables
  int pages = 256;
  int current_page = 1;
  char* ebook_title = "The Great Gatsby by F. Scott Fitzgerald";

  // Providing information about the ebook
  printf("You're currently reading \"%s\", which has %d pages.\n", ebook_title, pages);

  // Reading the ebook, page by page
  while (current_page <= pages) {
    printf("You're on page %d.\n", current_page);
    current_page++;
  }

  printf("Congratulations! You've finished reading \"%s\".\n", ebook_title);
  
  return 0;
}