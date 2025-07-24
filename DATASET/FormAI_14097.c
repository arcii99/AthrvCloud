//FormAI DATASET v1.0 Category: Ebook reader ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char title[100];
  char author[100];
  char text[10000];
} eBook;

void printTitle(char *title) {
  printf("=============================================\n\n\t%s\n\n=============================================\n\n", title);
}

void readText(char *text) {
  printf("%s", text);
}

void openFile(char *filename, eBook *book) {
  FILE *fp;
  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error opening file.\n");
    exit(1);
  }
  fscanf(fp, "%[^\n] %[^\n] %[^\n]s", book->title, book->author, book->text);
  fclose(fp);
}

int main() {
  eBook romeoAndJuliet;
  openFile("romeo_and_juliet.txt", &romeoAndJuliet);

  printTitle(romeoAndJuliet.title);
  readText(romeoAndJuliet.text);

  return 0;
}