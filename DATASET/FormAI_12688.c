//FormAI DATASET v1.0 Category: Ebook reader ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char title[50];
  char author[50];
  char content[5000];
  int pageCount;
} Book;

void displayBook(Book book) {
  printf("\nTitle:\t\t%s", book.title);
  printf("\nAuthor:\t\t%s", book.author);
  printf("\nPage Count:\t%d\n\n", book.pageCount);
}

void displayContents(Book book, int pageNum) {
  int i, start, end;
  char pageContents[1000];

  start = (pageNum - 1) * 1000;
  end = start + 1000;

  if (start > strlen(book.content))
    printf("\nThat page does not exist.\n");
  else {
    for (i = start; i < end; i++) {
      if (book.content[i] == '\0')
        break;
      else
        pageContents[i - start] = book.content[i];
    }
    printf("\nPage %d:\n%s\n", pageNum, pageContents);
  }
}

int main() {
  int i, choice, pageNum = 1;
  Book books[3];

  strcpy(books[0].title, "The Great Gatsby");
  strcpy(books[0].author, "F. Scott Fitzgerald");
  strcpy(books[0].content, "In my younger and more vulnerable years my father gave me some advice that I’ve been turning over in my mind ever since... (continued)");
  books[0].pageCount = strlen(books[0].content) / 1000 + 1;

  strcpy(books[1].title, "To Kill a Mockingbird");
  strcpy(books[1].author, "Harper Lee");
  strcpy(books[1].content, "When he was nearly thirteen, my brother Jem got his arm badly broken at the elbow... (continued)");
  books[1].pageCount = strlen(books[1].content) / 1000 + 1;

  strcpy(books[2].title, "Pride and Prejudice");
  strcpy(books[2].author, "Jane Austen");
  strcpy(books[2].content, "It is a truth universally acknowledged, that a single man in possession of a good fortune must be in want of a wife... (continued)");
  books[2].pageCount = strlen(books[2].content) / 1000 + 1;

  printf("\nWelcome to the Ebook reader!\n");

  do {
    printf("\nPlease choose a book to display or enter 0 to exit:\n");

    for (i = 0; i < sizeof(books) / sizeof(books[0]); i++)
      printf("%d. %s by %s\n", i + 1, books[i].title, books[i].author);

    scanf("%d", &choice);

    if (choice > 0 && choice <= sizeof(books) / sizeof(books[0])) {
      displayBook(books[choice - 1]);
      printf("\nPlease enter the page number to display or 0 to go back:\n");
      scanf("%d", &pageNum);

      while (pageNum > 0) {
        displayContents(books[choice - 1], pageNum);
        printf("\nPlease enter the page number to display or 0 to go back:\n");
        scanf("%d", &pageNum);
      }
    }
    else if (choice != 0)
      printf("\nThat book does not exist.\n");

  } while (choice != 0);

  printf("\nGoodbye!\n");

  return 0;
}