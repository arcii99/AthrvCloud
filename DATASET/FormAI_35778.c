//FormAI DATASET v1.0 Category: Ebook reader ; Style: complex
#include <stdio.h>
#include <string.h>
#define MAX_BOOKS 50
#define MAX_PAGES 500

typedef struct Page {
   int pageNum;
   char text[100];
} Page;

typedef struct Book {
   char title[50];
   char author[50];
   int pageCount;
   Page pages[MAX_PAGES];
} Book;

int numOfBooks = 0;
Book bookList[MAX_BOOKS];

int main() {
   int choice;
   do {
      printf("1. Add a new book\n2. Read a book\n3. Exit\n");
      fflush(stdin);
      scanf("%d", &choice);
      switch(choice) {
         case 1:
            addBook();
            break;
         case 2:
            readBook();
            break;
         case 3:
            break;
         default:
            printf("Invalid choice\n\n");
      }
   } while (choice != 3);
   return 0;
}

void addBook() {
   Book newBook;
   printf("Enter book title: ");
   fflush(stdin);
   fgets(newBook.title, sizeof(newBook.title), stdin);
   newBook.title[strlen(newBook.title)-1] = '\0';
   printf("Enter author name: ");
   fgets(newBook.author, sizeof(newBook.author), stdin);
   newBook.author[strlen(newBook.author)-1] = '\0';
   printf("Enter page count (max %d): ", MAX_PAGES);
   scanf("%d", &newBook.pageCount);
   if (newBook.pageCount <= 0 || newBook.pageCount > MAX_PAGES) {
      printf("Invalid page count\n\n");
      return;
   }
   printf("Enter text for each page:\n");
   for (int i = 0; i < newBook.pageCount; i++) {
      printf("Page %d: ", i+1);
      fflush(stdin);
      fgets(newBook.pages[i].text, sizeof(newBook.pages[i].text), stdin);
      newBook.pages[i].pageNum = i+1;
      newBook.pages[i].text[strlen(newBook.pages[i].text)-1] = '\0';
   }
   bookList[numOfBooks++] = newBook;
   printf("%s added successfully\n\n", newBook.title);
}

void readBook() {
   char title[50];
   Book *bookPtr = NULL;
   printf("Enter title of book to read: ");
   fflush(stdin);
   fgets(title, sizeof(title), stdin);
   title[strlen(title)-1] = '\0';
   for (int i = 0; i < numOfBooks; i++) {
      if (strcmp(bookList[i].title, title) == 0) {
         bookPtr = &bookList[i];
         break;
      }
   }
   if (bookPtr == NULL) {
      printf("No book with that title found\n\n");
      return;
   }
   printf("\n%s by %s\n\n", bookPtr->title, bookPtr->author);
   for (int i = 0; i < bookPtr->pageCount; i++) {
      printf("Page %d:\n%s\n\n", bookPtr->pages[i].pageNum, bookPtr->pages[i].text);
   }
}