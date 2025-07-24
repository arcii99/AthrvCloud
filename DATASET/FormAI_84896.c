//FormAI DATASET v1.0 Category: Ebook reader ; Style: sophisticated
#include<stdio.h>

struct Book {
    char author[50];
    char title[50];
    int pages;
    float price;
    char language[20];
};

void printBook(struct Book book) {
    printf("Author : %s\n", book.author);
    printf("Title  : %s\n", book.title);
    printf("Pages  : %d\n", book.pages);
    printf("Price  : %.2f\n", book.price);
    printf("Language : %s\n", book.language);
}

int main() {
    struct Book book1 = {"Dan Brown", "The Da Vinci Code", 598, 18.50, "English"};
    struct Book book2 = {"Paulo Coelho", "The Alchemist", 172, 12.99, "Portuguese"};
    struct Book book3 = {"Agatha Christie", "Murder on the Orient Express", 274, 9.99, "English"};
    
    printBook(book1);
    printBook(book2);
    printBook(book3);
    
    return 0;
}