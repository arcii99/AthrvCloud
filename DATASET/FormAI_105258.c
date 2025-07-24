//FormAI DATASET v1.0 Category: Ebook reader ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to the Grateful Ebook Reader!\n");

  FILE *fp;
  char file_name[100];
  int ch;

  printf("Enter the name of the Ebook you wish to read: ");
  gets(file_name);

  fp = fopen(file_name, "r");

  if (fp == NULL) {
    printf("Error: Could not open Ebook.\n");
    exit(1);
  }

  printf("Loading Ebook...\n");

  while ((ch = getc(fp)) != EOF) {
    putchar(ch);
  }

  printf("\n\nThank you for using the Grateful Ebook Reader!\n");

  fclose(fp);

  return 0;
}