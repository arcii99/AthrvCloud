//FormAI DATASET v1.0 Category: Ebook reader ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 50
#define MAX_BOOKS_COUNT 100
#define MAX_PAGES_COUNT 1000
#define MAX_BOOKMARKS_COUNT 50

typedef struct {
  char title[MAX_TITLE_LENGTH];
  char author[MAX_AUTHOR_LENGTH];
  int pagesCount;
  char pages[MAX_PAGES_COUNT][MAX_PAGES_COUNT];
} Book;

typedef struct {
  int bookIndex;
  int pageIndex;
} Bookmark;

void loadBooks(Book books[], int* booksCount) {
  // Load books from database or file system
}

void saveBooks(const Book books[], int booksCount) {
  // Save books to database or file system
}

void addBook(Book books[], int* booksCount) {
  if (*booksCount == MAX_BOOKS_COUNT) {
    printf("Maximum books count reached");
    return;
  }
  
  printf("Enter book title:");
  scanf("%s", books[*booksCount].title);
  
  printf("Enter book author:");
  scanf("%s", books[*booksCount].author);
  
  printf("Enter book pages count:");
  scanf("%d", &books[*booksCount].pagesCount);
  
  for (int i = 1; i <= books[*booksCount].pagesCount; i++) {
    char pageContent[MAX_PAGES_COUNT];
    
    printf("Enter content of page %d:", i);
    scanf("%s", pageContent);
    
    strcpy(books[*booksCount].pages[i], pageContent);
  }
  
  *booksCount++;
  
  printf("Book added successfully");
}

void deleteBook(Book books[], int* booksCount, int bookIndex) {
  if (bookIndex < 0 || bookIndex >= *booksCount) {
    printf("Invalid book index");
    return;
  }
  
  for (int i = bookIndex; i < *booksCount - 1; i++) {
    books[i] = books[i + 1];
  }
  
  *booksCount--;
  
  printf("Book deleted successfully");
}

void listBooks(const Book books[], int booksCount) {
  for (int i = 0; i < booksCount; i++) {
    printf("%d) %s by %s\n", i + 1, books[i].title, books[i].author);
  }
}

void addBookmark(Bookmark bookmarks[], int* bookmarksCount, int bookIndex, int pageIndex) {
  if (*bookmarksCount == MAX_BOOKMARKS_COUNT) {
    printf("Maximum bookmarks count reached");
    return;
  }
  
  bookmarks[*bookmarksCount] = (Bookmark){ bookIndex, pageIndex };
  
  *bookmarksCount++;
  
  printf("Bookmark added successfully");
}

void deleteBookmark(Bookmark bookmarks[], int* bookmarksCount, int bookmarkIndex) {
  if (bookmarkIndex < 0 || bookmarkIndex >= *bookmarksCount) {
    printf("Invalid bookmark index");
    return;
  }
  
  for (int i = bookmarkIndex; i < *bookmarksCount - 1; i++) {
    bookmarks[i] = bookmarks[i + 1];
  }
  
  *bookmarksCount--;
  
  printf("Bookmark deleted successfully");
}

void goToPage(const Book* book, int pageIndex) {
  if (pageIndex < 1 || pageIndex > book->pagesCount) {
    printf("Invalid page index");
    return;
  }
  
  printf("Page %d:\n%s", pageIndex, book->pages[pageIndex]);
}

void showBook(Book books[], int booksCount, int bookIndex, Bookmark bookmarks[], int bookmarksCount) {
  if (bookIndex < 0 || bookIndex >= booksCount) {
    printf("Invalid book index");
    return;
  }
  
  Book book = books[bookIndex];
  
  printf("%s by %s\n", book.title, book.author);
  
  int choice;
  
  do {
    printf("1) List bookmarks\n");
    printf("2) Add bookmark\n");
    printf("3) Delete bookmark\n");
    printf("4) Go to page\n");
    printf("5) Exit book\n");
    printf("Enter choice:");
    scanf("%d", &choice);
    
    switch (choice) {
      case 1:
        for (int i = 0; i < bookmarksCount; i++) {
          if (bookmarks[i].bookIndex == bookIndex) {
            printf("%d) Page %d\n", i + 1, bookmarks[i].pageIndex);
          }
        }
        break;
        
      case 2:
        int pageIndex;
        printf("Enter page index:");
        scanf("%d", &pageIndex);
        addBookmark(bookmarks, &bookmarksCount, bookIndex, pageIndex);
        break;
        
      case 3:
        int bookmarkIndex;
        printf("Enter bookmark index:");
        scanf("%d", &bookmarkIndex);
        deleteBookmark(bookmarks, &bookmarksCount, bookmarkIndex - 1);
        break;
        
      case 4:
        int pageNumber;
        printf("Enter page number:");
        scanf("%d", &pageNumber);
        goToPage(&book, pageNumber);
        break;
    }
  } while (choice != 5);
}

int main() {
  Book books[MAX_BOOKS_COUNT];
  int booksCount = 0;
  Bookmark bookmarks[MAX_BOOKMARKS_COUNT];
  int bookmarksCount = 0;
  
  loadBooks(books, &booksCount);
  
  int choice;
  
  do {
    printf("1) List books\n");
    printf("2) Add book\n");
    printf("3) Delete book\n");
    printf("4) Show book\n");
    printf("5) Exit\n");
    printf("Enter choice:");
    scanf("%d", &choice);
    
    switch (choice) {
      case 1:
        listBooks(books, booksCount);
        break;
        
      case 2:
        addBook(books, &booksCount);
        saveBooks(books, booksCount);
        break;
        
      case 3:
        int bookIndex;
        printf("Enter book index:");
        scanf("%d", &bookIndex);
        deleteBook(books, &booksCount, bookIndex - 1);
        saveBooks(books, booksCount);
        break;
        
      case 4:
        int bookNumber;
        printf("Enter book number:");
        scanf("%d", &bookNumber);
        showBook(books, booksCount, bookNumber - 1, bookmarks, bookmarksCount);
        break;
    }
  } while (choice != 5);
  
  return 0;
}