//FormAI DATASET v1.0 Category: Data structures visualization ; Style: relaxed
#include <stdio.h>

// declare a structure called "book"
struct book {
  char title[50];
  char author[50];
  int pages;
  float price;
};

int main() {
  // create an array of 3 book structures 
  struct book library[3];

  // populate the array with book information
  printf("Welcome to your Book Library!\n\n");

  for(int i=0; i<3; i++) {
    printf("Enter the title of book %d: ", i+1);
    scanf("%s", library[i].title);

    printf("Enter the author of book %d: ", i+1);
    scanf("%s", library[i].author);
    
    printf("Enter the number of pages for book %d: ", i+1);
    scanf("%d", &library[i].pages);
    
    printf("Enter the price of book %d: ", i+1);
    scanf("%f", &library[i].price);

    printf("\n");
  }

  // display the book information in a table format
  printf("Here is your Book Library:\n\n");
  printf("%-30s%-20s%-15s%-10s", "Title", "Author", "Pages", "Price");
  printf("\n");

  for(int i=0; i<3; i++) {
    printf("%-30s%-20s%-15d%-10.2f", library[i].title, 
                                      library[i].author, 
                                      library[i].pages,
                                      library[i].price);
    printf("\n");
  }

  return 0;
}