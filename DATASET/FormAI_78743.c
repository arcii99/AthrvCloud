//FormAI DATASET v1.0 Category: Ebook reader ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
   char title[50];
   char author[50];
   int pages;
   double price;
};
    
struct Ebook {
   struct Book book;
   char file[50];
   int size;
   int currentPage;
   int fontSize;
};

void displayPage(struct Ebook *ebook){
   printf("Title: %s\n", ebook->book.title);
   printf("Author: %s\n", ebook->book.author);
   printf("Pages: %d\n", ebook->book.pages);
   printf("Price: %f\n", ebook->book.price);
   printf("Current Page: %d\n", ebook->currentPage);
   printf("File: %s\n", ebook->file);
   printf("Size: %d bytes\n", ebook->size);
   printf("Font Size: %d\n", ebook->fontSize);
}

void readEbook(struct Ebook *ebook){
    int choice;
    printf("Enter Page number: ");
    scanf("%d", &ebook->currentPage);
    printf("Choose Font Size (1-10): ");
    scanf("%d", &ebook->fontSize);
    displayPage(ebook);
    printf("1-Next Page\n2-Previous Page\n3-Change Font Size\n4-Quit Reading\n");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            ebook->currentPage++;
            readEbook(ebook);
            break;
        case 2:
            if(ebook->currentPage > 1){
                ebook->currentPage--;
            }
            readEbook(ebook);
            break;
        case 3:
            printf("Choose Font Size (1-10): ");
            scanf("%d", &ebook->fontSize);
            readEbook(ebook);
            break;
        case 4:
            printf("Exiting Ebook Reader\n");
            break;
        default:
            printf("Invalid Choice, Try Again\n");
            readEbook(ebook);
            break;
    }
}

int main() {
   struct Ebook ebook;
   strcpy(ebook.book.title, "The Art of War");
   strcpy(ebook.book.author, "Sun Tzu");
   ebook.book.pages = 120;
   ebook.book.price = 9.99;
   strcpy(ebook.file, "art_of_war.epub");
   ebook.size = 12345;
   ebook.currentPage = 1;
   ebook.fontSize = 5;
   printf("Welcome to Ebook Reader!\n");
   readEbook(&ebook);
   return 0;
}