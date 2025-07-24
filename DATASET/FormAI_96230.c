//FormAI DATASET v1.0 Category: Ebook reader ; Style: Alan Touring
#include<stdio.h>
#include<string.h>

struct Ebook {
  char title[50];
  char author[50];
  char publisher[50];
  int pages;
  float price;
};

int main() {
  struct Ebook book;
  printf("Enter the details of the Ebook:\n");
  printf("Title: ");
  fgets(book.title, sizeof(book.title), stdin);
  book.title[strcspn(book.title, "\n")] = 0;
  printf("Author: ");
  fgets(book.author, sizeof(book.author), stdin);
  book.author[strcspn(book.author, "\n")] = 0;
  printf("Publisher: ");
  fgets(book.publisher, sizeof(book.publisher), stdin);
  book.publisher[strcspn(book.publisher, "\n")] = 0;
  printf("Number of pages: ");
  scanf("%d", &book.pages);
  printf("Price: ");
  scanf("%f", &book.price);
  
  printf("\n\nThe details of the Ebook:\n");
  printf("Title: %s\n", book.title);
  printf("Author: %s\n", book.author);
  printf("Publisher: %s\n", book.publisher);
  printf("Number of pages: %d\n", book.pages);
  printf("Price: %f\n", book.price);
  
  return 0;
}