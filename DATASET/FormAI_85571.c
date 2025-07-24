//FormAI DATASET v1.0 Category: Ebook reader ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define a struct for the book
struct book {
  char title[100];
  char author[50];
  int year;
  float price;
};

int main() {
  int numBooks, choice;

  printf("Enter the number of books in your library: ");
  scanf("%d", &numBooks);

  // allocate memory for the array of books
  struct book *library = (struct book*) malloc(numBooks * sizeof(struct book));

  // populate the library with books
  for (int i = 0; i < numBooks; i++) {
    printf("Book %d\n", i+1);
    printf("Title: ");
    scanf(" %[^\n]", library[i].title);
    printf("Author: ");
    scanf(" %[^\n]", library[i].author);
    printf("Year of publication: ");
    scanf("%d", &library[i].year);
    printf("Price: ");
    scanf("%f", &library[i].price);
    printf("\n");
  }

  // display the library menu
  do {
    printf("Library menu\n");
    printf("1. View all books\n");
    printf("2. Search for a book\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        // view all books in the library
        for (int i = 0; i < numBooks; i++) {
          printf("%d. %s by %s, %d ($%.2f)\n", i+1, library[i].title, library[i].author, library[i].year, library[i].price);
        }
        printf("\n");
        break;

      case 2:
        // search for a book by title or author
        char searchQuery[100];
        printf("Enter the title or author to search for: ");
        scanf(" %[^\n]", searchQuery);

        for (int i = 0; i < numBooks; i++) {
          if (strstr(library[i].title, searchQuery) || strstr(library[i].author, searchQuery)) {
            printf("%d. %s by %s, %d ($%.2f)\n", i+1, library[i].title, library[i].author, library[i].year, library[i].price);
          }
        }
        printf("\n");
        break;

      case 3:
        // exit the program
        printf("Goodbye!\n");
        break;

      default:
        printf("Invalid choice. Please try again.\n");
        break;
    }
  } while (choice != 3);

  // free the memory allocated for the library array
  free(library);

  return 0;
}