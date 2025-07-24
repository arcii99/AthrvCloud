//FormAI DATASET v1.0 Category: Ebook reader ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char* ebook = "The Cat in the Hat";
  char input[50];
  char* current_page = "Chapter 1";
  int ebook_length = 100;
  int current_page_number = 1;
  int num_pages = 10;

  printf("Welcome to the Surreal Ebook Reader!\n");
  printf("Your current book is: %s\n", ebook);

  while (1) {
    printf("You are currently on page %d of %d.\n", current_page_number, num_pages);
    printf("You are reading %s.\n", current_page);
    printf("Enter a command: ");
    fgets(input, 50, stdin);
    input[strcspn(input, "\n")] = 0;

    if (strcmp(input, "next") == 0) {
      if (current_page_number == num_pages) {
        printf("You have reached the end of the book!\n");
        break;
      }
      current_page_number++;
      current_page = "Chapter 2";
      printf("You have turned the page.\n");
    } else if (strcmp(input, "previous") == 0) {
      if (current_page_number == 1) {
        printf("You are already on the first page.\n");
      } else {
        current_page_number--;
        current_page = "Chapter 1";
        printf("You have turned back a page.\n");
      }
    } else if (strcmp(input, "waffles") == 0) {
      printf("You have summoned the surreal waffle dimension!\n");
    } else if (strcmp(input, "exit") == 0) {
      printf("Goodbye!\n");
      break;
    } else {
      printf("I'm sorry, I don't understand that command.\n");
    }
  }

  return 0;
}