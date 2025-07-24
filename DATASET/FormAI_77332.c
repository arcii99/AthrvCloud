//FormAI DATASET v1.0 Category: Ebook reader ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

// Define a struct for a book
typedef struct {
  char title[50];
  char author[50];
  int num_pages;
} Book;

// Define a struct for an ebook reader
typedef struct {
  Book *current_book;
  int current_page;
} EbookReader;

// Function to initialize an ebook reader
void init_ebook_reader(EbookReader *reader) {
  reader->current_book = NULL;
  reader->current_page = 0;
}

// Function to load a book into the ebook reader
void load_book(EbookReader *reader, Book *book) {
  reader->current_book = book;
  reader->current_page = 1;
}

// Function to display the current book and page number
void display_ebook_reader(EbookReader *reader) {
  if (reader->current_book == NULL) {
    printf("No book loaded.\n");
  } else {
    printf("Current Book: %s by %s\n", reader->current_book->title, reader->current_book->author);
    printf("Page %d of %d\n", reader->current_page, reader->current_book->num_pages);
  }
}

// Function to turn to the next page
void next_page(EbookReader *reader) {
  if (reader->current_book == NULL) {
    printf("No book loaded.\n");
  } else if (reader->current_page == reader->current_book->num_pages) {
    printf("End of book.\n");
  } else {
    reader->current_page++;
    printf("Page %d of %d\n", reader->current_page, reader->current_book->num_pages);
  }
}

// Function to turn to the previous page
void prev_page(EbookReader *reader) {
  if (reader->current_book == NULL) {
    printf("No book loaded.\n");
  } else if (reader->current_page == 1) {
    printf("Beginning of book.\n");
  } else {
    reader->current_page--;
    printf("Page %d of %d\n", reader->current_page, reader->current_book->num_pages);
  }
}

int main(void) {
  EbookReader reader;
  init_ebook_reader(&reader);

  // Create a book object and load it into the ebook reader
  Book book = {"The Great Gatsby", "F. Scott Fitzgerald", 180};
  load_book(&reader, &book);

  // Display the current book and page number
  display_ebook_reader(&reader);

  // Turn to the next page
  next_page(&reader);

  // Turn to the previous page
  prev_page(&reader);

  return 0;
}