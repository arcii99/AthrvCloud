//FormAI DATASET v1.0 Category: Ebook reader ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

struct Book {
  char title[50];
  char author[50];
  int year;
  float price;
};

int main() {
  struct Book myBook = {"C Programming", "John Doe", 2020, 9.99};
  FILE *fp;
  unsigned int current_page = 1;
  char input;
  
  // open book file
  fp = fopen("C_Programming_Ebook.txt", "r");
  if (fp == NULL) {
    printf("Error opening file.");
    exit(1);
  }
  
  // read and display book details
  printf("Title: %s\nAuthor: %s\nYear: %d\nPrice: $%.2f\n\n", 
         myBook.title, myBook.author, myBook.year, myBook.price);
  
  // display first page of book
  printf("Page %d\n\n", current_page);
  while ((input = fgetc(fp)) != EOF && current_page == 1) {
    printf("%c", input);
    if (input == '\n') {
      if ((input = fgetc(fp)) == EOF) {
        break;
      }
      printf("%c", input);
    }
    if (ftell(fp) >= 1000) {
      break;
    }
  }
  printf("\n\n");
  
  // loop for user input
  while (1) {
    printf("Press N for next page, P for previous page, or Q to quit: ");
    input = getchar();
    printf("\n");
    if (input == 'N' || input == 'n') {
      current_page++;
      printf("Page %d\n\n", current_page);
      while ((input = fgetc(fp)) != EOF) {
        if (input == '\f') {
          current_page++;
          printf("\nPage %d\n\n", current_page);
          continue;
        }
        printf("%c", input);
        if (input == '\n') {
          if ((input = fgetc(fp)) == EOF) {
            break;
          }
          printf("%c", input);
        }
        if (ftell(fp) >= (current_page * 1000)) {
          break;
        }
      }
      printf("\n\n");
    }
    else if (input == 'P' || input == 'p') {
      if (current_page == 1) {
        printf("You are already on the first page.\n\n");
        continue;
      }
      current_page--;
      fseek(fp, (current_page - 1) * 1000, SEEK_SET);
      printf("Page %d\n\n", current_page);
      while ((input = fgetc(fp)) != EOF) {
        if (input == '\f' && current_page == 1) {
          continue;
        }
        if (input == '\f') {
          current_page--;
          printf("\nPage %d\n\n", current_page);
          continue;
        }
        printf("%c", input);
        if (input == '\n') {
          if ((input = fgetc(fp)) == EOF) {
            break;
          }
          printf("%c", input);
        }
        if (ftell(fp) < ((current_page - 1) * 1000)) {
          break;
        }
      }
      printf("\n\n");
    }
    else if (input == 'Q' || input == 'q') {
      break;
    }
    else {
      printf("Invalid input.\n\n");
    }
    getchar(); // clear newline character from input buffer
  }
  
  // close book file
  fclose(fp);
  
  return 0;
}