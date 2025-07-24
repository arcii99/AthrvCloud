//FormAI DATASET v1.0 Category: Ebook reader ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  printf("Welcome to Linus Torvalds' Ebook Reader!\n");

  FILE *fp;
  char filename[100];
  printf("Enter the name of the file you want to read: ");
  scanf("%s", filename);

  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error: File not found.\n");
    exit(1);
  }

  int ch;
  while ((ch = fgetc(fp)) != EOF) {
    putchar(ch);
  }

  fclose(fp);
  return 0;
}