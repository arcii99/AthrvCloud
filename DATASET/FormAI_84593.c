//FormAI DATASET v1.0 Category: Ebook reader ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_SIZE 50
#define MAX_LINE_SIZE 256

typedef struct {
  char title[MAX_LINE_SIZE];
  char author[MAX_LINE_SIZE];
  char publication_date[MAX_LINE_SIZE];
  char filename[MAX_FILE_NAME_SIZE];
} Ebook;

void print_ebook_info(Ebook* ebook) {
  printf("Title: %s\n", ebook->title);
  printf("Author: %s\n", ebook->author);
  printf("Publication Date: %s\n", ebook->publication_date);
  printf("Filename: %s\n", ebook->filename);
}

void read_ebook_info(FILE* file, Ebook* ebook) {
  char line[MAX_LINE_SIZE];

  fgets(line, MAX_LINE_SIZE, file);
  strcpy(ebook->title, line);

  fgets(line, MAX_LINE_SIZE, file);
  strcpy(ebook->author, line);

  fgets(line, MAX_LINE_SIZE, file);
  strcpy(ebook->publication_date, line);

  fgets(line, MAX_FILE_NAME_SIZE, file);
  strcpy(ebook->filename, line);

  // remove trailing newline character from filename
  ebook->filename[strcspn(ebook->filename, "\n")] = 0;
}

void read_ebook(char* filename) {
  FILE* file;
  Ebook ebook;

  file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error opening file: %s\n", filename);
    return;
  }

  read_ebook_info(file, &ebook);
  print_ebook_info(&ebook);

  fclose(file);
}

int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  read_ebook(argv[1]);

  return 0;
}