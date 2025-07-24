//FormAI DATASET v1.0 Category: Ebook reader ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 10
#define MAX_TITLE_LENGTH 1000
#define MAX_PAGES 10000

typedef struct {
  char title[MAX_TITLE_LENGTH];
  int num_pages;
  char *pages[MAX_PAGES];
} Ebook;

typedef struct {
  Ebook library[MAX_BOOKS];
  int num_books;
} EbookReader;

void clear_input_buffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {}
}

int read_int() {
  int num;
  scanf("%d", &num);
  clear_input_buffer();
  return num;
}

char* read_string(char* buffer, int size) {
  fgets(buffer, size, stdin);
  int len = strlen(buffer);
  if (len > 0 && buffer[len-1] == '\n') {
    buffer[len-1] = '\0';
  }
  return buffer;
}

void display_ebook(Ebook ebook) {
  printf("Title: %s\n", ebook.title);
  printf("Number of pages: %d\n", ebook.num_pages);
  printf("Contents: \n");
  for (int i = 0; i < ebook.num_pages; i++) {
    printf("%s", ebook.pages[i]);
  }
}

void add_ebook(EbookReader* reader) {
  if (reader->num_books < MAX_BOOKS) {
    Ebook new_book;
    printf("Enter the title of the ebook: ");
    read_string(new_book.title, MAX_TITLE_LENGTH);
    printf("Enter the number of pages in the ebook: ");
    new_book.num_pages = read_int();
    printf("Enter the contents of the ebook:\n");
    for (int i = 0; i < new_book.num_pages; i++) {
      printf("Page %d: ", i+1);
      new_book.pages[i] = malloc(MAX_TITLE_LENGTH * sizeof(char));
      read_string(new_book.pages[i], MAX_TITLE_LENGTH);
    }
    reader->library[reader->num_books] = new_book;
    reader->num_books++;
    printf("Ebook added successfully!\n");
  } else {
    printf("Sorry, the library is full and cannot accept more ebooks.\n");
  }
}

int search_ebook(EbookReader reader, char* title) {
  for (int i = 0; i < reader.num_books; i++) {
    if (strcmp(reader.library[i].title, title) == 0) {
      return i;
    }
  }
  return -1;
}

void view_library(EbookReader reader) {
  printf("Library:\n");
  for (int i = 0; i < reader.num_books; i++) {
    printf("%d. %s\n", i+1, reader.library[i].title);
  }
  printf("\n");
}

void read_ebook(EbookReader reader) {
  view_library(reader);
  printf("Enter the title of the ebook you would like to read: ");
  char title[MAX_TITLE_LENGTH];
  read_string(title, MAX_TITLE_LENGTH);
  int index = search_ebook(reader, title);
  if (index != -1) {
    display_ebook(reader.library[index]);
  } else {
    printf("Sorry, the ebook could not be found.\n");
  }
}

int main() {
  EbookReader reader;
  reader.num_books = 0;

  int choice = -1;
  while (choice != 0) {
    printf("Ebook Reader Menu:\n");
    printf("1. Add Ebook\n");
    printf("2. View Library\n");
    printf("3. Read Ebook\n");
    printf("0. Exit\n");

    printf("Enter your choice: ");
    choice = read_int();

    switch(choice) {
      case 1: add_ebook(&reader); break;
      case 2: view_library(reader); break;
      case 3: read_ebook(reader); break;
      case 0: printf("Goodbye!\n"); break;
      default: printf("Sorry, that is not a valid choice. Please try again.\n"); break;
    }
    printf("\n");
  }

  return 0;
}