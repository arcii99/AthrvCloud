//FormAI DATASET v1.0 Category: Ebook reader ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EBOOKS 100
#define MAX_TITLE_LENGTH 50
#define MAX_AUTHOR_LENGTH 30

struct Ebook {
  char title[MAX_TITLE_LENGTH];
  char author[MAX_AUTHOR_LENGTH];
  char* content;
  int content_size;
};

struct Ebook_library {
  int num_ebooks;
  struct Ebook ebooks[MAX_EBOOKS];
};

void add_ebook(struct Ebook_library* library, struct Ebook ebook) {
  if (library->num_ebooks >= MAX_EBOOKS) {
    printf("Library is full!\n");
    return;
  }
  library->ebooks[library->num_ebooks] = ebook;
  library->num_ebooks++;
  printf("Ebook added to the library!\n");
}

void read_ebook(struct Ebook ebook) {
  printf("*** %s by %s ***\n", ebook.title, ebook.author);
  printf("%s\n", ebook.content);
}

int main() {
  struct Ebook alice;
  struct Ebook_library library;
  library.num_ebooks = 0;
  strcpy(alice.title, "Alice in Wonderland");
  strcpy(alice.author, "Lewis Carroll");
  alice.content_size = 2345;
  alice.content = (char*) malloc(alice.content_size * sizeof(char));
  strcpy(alice.content, "... text of Alice in Wonderland ...");
  add_ebook(&library, alice);
  read_ebook(library.ebooks[0]);
  free(alice.content);
  return 0;
}