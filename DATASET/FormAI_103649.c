//FormAI DATASET v1.0 Category: Ebook reader ; Style: high level of detail
#include <stdio.h>
#include <string.h>

struct Book {
  char title[50];
  char author[50];
  int year_published;
  char file_path[100];
};

int main() {
  struct Book book1;
  
  // Initialize book1
  strcpy(book1.title, "The C Programming Language");
  strcpy(book1.author, "Brian Kernighan and Dennis Ritchie");
  book1.year_published = 1978;
  strcpy(book1.file_path, "/books/c_programming.pdf");
  
  // Open the ebook file
  FILE* ebook_file = fopen(book1.file_path, "r");
  
  // Check if the ebook file was successfully opened
  if (ebook_file == NULL) {
    printf("Could not open ebook file.\n");
    return 1;
  }
  
  // Read the contents of the ebook file
  char contents[10000];
  int num_bytes_read = fread(contents, sizeof(char), sizeof(contents), ebook_file);
  
  // Close the ebook file
  fclose(ebook_file);
  
  // Output the book information and contents
  printf("Title: %s\n", book1.title);
  printf("Author: %s\n", book1.author);
  printf("Year Published: %d\n", book1.year_published);
  printf("Contents: %s\n", contents);
  
  return 0;
}