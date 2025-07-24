//FormAI DATASET v1.0 Category: File handling ; Style: future-proof
#include <stdio.h>
#include <string.h>

typedef struct Book {
    int id;
    char title[50];
    char author[50];
    float price;
} Book;

int main() {
    FILE *fp;
    char filename[] = "books.dat";
    Book book, read_book;

    // create or open a file to write
    fp = fopen(filename, "wb");

    book.id = 1;
    strcpy(book.title, "The Alchemist");
    strcpy(book.author, "Paulo Coelho");
    book.price = 10.50;

    // write a book to the file
    fwrite(&book, sizeof(Book), 1, fp);

    book.id = 2;
    strcpy(book.title, "Harry Potter");
    strcpy(book.author, "J.K. Rowling");
    book.price = 15.99;

    // write another book to the file
    fwrite(&book, sizeof(Book), 1, fp);

    fclose(fp);

    // open the file for reading
    fp = fopen(filename, "rb");

    // read the first book from the file
    fread(&read_book, sizeof(Book), 1, fp);
    printf("Book ID: %d\nTitle: %s\nAuthor: %s\nPrice: $%.2f\n", read_book.id, read_book.title, read_book.author, read_book.price);

    // read the second book from the file
    fread(&read_book, sizeof(Book), 1, fp);
    printf("Book ID: %d\nTitle: %s\nAuthor: %s\nPrice: $%.2f\n", read_book.id, read_book.title, read_book.author, read_book.price);

    fclose(fp);

    return 0;
}