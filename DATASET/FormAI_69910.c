//FormAI DATASET v1.0 Category: Ebook reader ; Style: surprised
#include <stdio.h>

int main() {
  printf("Welcome to the Unique C Ebook Reader!\n");
  printf("Please input the name of the book you'd like to read: ");
  
  char bookName[50];
  scanf("%s", bookName);
  
  printf("\nOpening %s...\n\n", bookName);
  
  FILE *fp;
  char ch;
  fp = fopen(bookName, "r");
  
  if (fp == NULL) {
    printf("Error: File not found.\n");
    return 1;
  }
  
  while(1) {
    ch = fgetc(fp);
    if (ch == EOF) {
      break;
    }
    printf("%c", ch);
  }
  
  fclose(fp);
  
  printf("\n\nEnd of book. Thanks for reading!\n");
  
  return 0;
}