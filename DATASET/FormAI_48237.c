//FormAI DATASET v1.0 Category: Ebook reader ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Book {
    char* title;
    char* author;
    int year;
    double price;
    int pages;
} Book;

// Function to calculate the price of a book based on its page count and publication year
double calculatePrice(Book* book) {
    int currentYear = 2022;
    double pricePerPage = 0.01;
    double ageFactor = pow(0.9, currentYear - book->year);

    double price = book->pages * pricePerPage * ageFactor;

    if (price < book->price) {
        return price;
    } else {
        return book->price;
    }
}

int main() {
    Book* myBook = (Book*)malloc(sizeof(Book));
    myBook->title = "A Mathematical Approach to C Programming";
    myBook->author = "John Doe";
    myBook->year = 2020;
    myBook->price = 29.99;
    myBook->pages = 300;

    printf("Title: %s\n", myBook->title);
    printf("Author: %s\n", myBook->author);
    printf("Year: %d\n", myBook->year);
    printf("Price: %.2f\n", myBook->price);
    printf("Pages: %d\n", myBook->pages);

    double finalPrice = calculatePrice(myBook);

    printf("Final Price: %.2f\n", finalPrice);

    free(myBook);

    return 0;
}