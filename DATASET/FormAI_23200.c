//FormAI DATASET v1.0 Category: Ebook reader ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the details of the book
struct Book {
    char title[50];
    char author[50];
    char publisher[50];
    int year;
    float price;
    char format[10];
};

// Function to display the details of a book
void display_book_detail(struct Book book) {
    printf("Book Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Publisher: %s\n", book.publisher);
    printf("Year of Publication: %d\n", book.year);
    printf("Price: $%.2f\n", book.price);
    printf("Format: %s\n", book.format);
}

int main() {
    // Creating an array of Book structures
    struct Book books[5];

    // Adding books to the array
    strcpy(books[0].title, "C Programming for Beginners");
    strcpy(books[0].author, "John Smith");
    strcpy(books[0].publisher, "McGraw Hill");
    books[0].year = 2021;
    books[0].price = 29.99;
    strcpy(books[0].format, "eBook");

    strcpy(books[1].title, "Data Structures and Algorithms");
    strcpy(books[1].author, "Jane Doe");
    strcpy(books[1].publisher, "Pearson");
    books[1].year = 2020;
    books[1].price = 49.99;
    strcpy(books[1].format, "eBook");

    strcpy(books[2].title, "Introduction to Machine Learning");
    strcpy(books[2].author, "Michael Green");
    strcpy(books[2].publisher, "O'Reilly");
    books[2].year = 2019;
    books[2].price = 39.99;
    strcpy(books[2].format, "PDF");

    strcpy(books[3].title, "Python Crash Course");
    strcpy(books[3].author, "Eric Matthes");
    strcpy(books[3].publisher, "No Starch Press");
    books[3].year = 2018;
    books[3].price = 24.99;
    strcpy(books[3].format, "eBook");

    strcpy(books[4].title, "Blockchain Basics");
    strcpy(books[4].author, "Samuel Lee");
    strcpy(books[4].publisher, "Packt");
    books[4].year = 2021;
    books[4].price = 19.99;
    strcpy(books[4].format, "ePub");

    int choice;
    do {
        // Displaying the menu
        printf("\nEbook Reader\n");
        printf("1. Display Book Details\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Displaying the details of a book
                printf("\nEnter the book number (1-5): ");
                int number;
                scanf("%d", &number);
                if (number < 1 || number > 5) {
                    printf("Invalid book number\n");
                } else {
                    display_book_detail(books[number - 1]);
                }
                break;
            case 2:
                // Exiting the program
                printf("Exiting Ebook Reader\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (1);

    return 0;
}