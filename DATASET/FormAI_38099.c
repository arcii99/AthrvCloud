//FormAI DATASET v1.0 Category: Ebook reader ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Ebook {
  char title[50];
  char author[50];
  int year;
  float price;
} Ebook;

void displayBook(Ebook book)
{
  printf("Title: %s\n", book.title);
  printf("Author: %s\n", book.author);
  printf("Year: %d\n", book.year);
  printf("Price: %.2f\n", book.price);
}

void printMenu()
{
  printf("\n");
  printf("1. Add a new book\n");
  printf("2. Display all books\n");
  printf("3. Search for a book by title\n");
  printf("4. Exit\n");
  printf("\n");
}

int main(void) {

  Ebook books[50];
  int bookCount = 0;
  int choice;

  do {
    printMenu();
    printf("Enter an option: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter book title: ");
        scanf("%s", books[bookCount].title);
        printf("Enter book author: ");
        scanf("%s", books[bookCount].author);
        printf("Enter book year: ");
        scanf("%d", &books[bookCount].year);
        printf("Enter book price: ");
        scanf("%f", &books[bookCount].price);
        bookCount++;
        break;
      case 2:
        if (bookCount == 0) {
          printf("No books added yet.\n");
        } else {
          for (int i = 0; i < bookCount; i++) {
            displayBook(books[i]);
          }
        }
        break;
      case 3:
        char titleSearch[50];
        int found = 0;
        printf("Enter book title to search: ");
        scanf("%s", titleSearch);
        for (int i = 0; i < bookCount; i++) {
          if (strcmp(titleSearch, books[i].title) == 0) {
            displayBook(books[i]);
            found = 1;
          }
        }
        if (!found) {
          printf("No books found with that title.\n");
        }
        break;
      case 4:
        printf("Exiting...\n");
        break;
      default:
        printf("Invalid input. Try again.\n");
        break;
    }
  } while (choice != 4);

  return 0;
}