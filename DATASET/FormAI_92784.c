//FormAI DATASET v1.0 Category: Ebook reader ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[50];
    char author[50];
    char publisher[50];
    float price;
    int yearPublished;
} Book;

void printBook(Book *book) {
    printf("\n---------\n");
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Publisher: %s\n", book->publisher);
    printf("Price: %.2f\n", book->price);
    printf("Year Published: %d\n", book->yearPublished);
    printf("---------\n");
}

void readBooksFromFile(char *fileName, Book *books, int *numBooks) {
    FILE *fp = fopen(fileName, "r");
    if(fp == NULL) {
        printf("Error: could not open file %s", fileName);
        exit(1);
    }

    char buffer[100];
    char *token;
    while(fgets(buffer, sizeof(buffer), fp) != NULL) {
        token = strtok(buffer, ",");
        int index = *numBooks;
        while(token != NULL) {
            switch(index%5) {
                case 0:
                    strcpy(books[index/5].title, token);
                    break;
                case 1:
                    strcpy(books[index/5].author, token);
                    break;
                case 2:
                    strcpy(books[index/5].publisher, token);
                    break;
                case 3:
                    books[index/5].price = atof(token);
                    break;
                case 4:
                    books[index/5].yearPublished = atoi(token);
                    (*numBooks)++;
                    break;
            }
            index++;
            token = strtok(NULL, ",");
        }
    }

    fclose(fp);
}

void displayMenu() {
    printf("\n1. Display all books");
    printf("\n2. Search for books by author");
    printf("\n3. Search for books by publisher");
    printf("\n4. Search for books by year");
    printf("\n5. Quit");
    printf("\nEnter your choice: ");
}

void displayAllBooks(Book *books, int numBooks) {
    for(int i = 0; i < numBooks; i++) {
        printBook(&books[i]);
    }
}

void searchByAuthor(Book *books, int numBooks) {
    char author[50];
    printf("\nEnter author name: ");
    scanf("%s", author);

    int found = 0;
    for(int i = 0; i < numBooks; i++) {
        if(strcmp(books[i].author, author) == 0) {
            printBook(&books[i]);
            found = 1;
        }
    }

    if(found == 0) {
        printf("\nNo books found for author %s", author);
    }
}

void searchByPublisher(Book *books, int numBooks) {
    char publisher[50];
    printf("\nEnter publisher name: ");
    scanf("%s", publisher);

    int found = 0;
    for(int i = 0; i < numBooks; i++) {
        if(strcmp(books[i].publisher, publisher) == 0) {
            printBook(&books[i]);
            found = 1;
        }
    }

    if(found == 0) {
        printf("\nNo books found for publisher %s", publisher);
    }
}

void searchByYear(Book *books, int numBooks) {
    int year;
    printf("\nEnter year: ");
    scanf("%d", &year);

    int found = 0;
    for(int i = 0; i < numBooks; i++) {
        if(books[i].yearPublished == year) {
            printBook(&books[i]);
            found = 1;
        }
    }

    if(found == 0) {
        printf("\nNo books found for year %d", year);
    }
}

int main() {
    Book books[100];
    int numBooks = 0;
    readBooksFromFile("books.txt", books, &numBooks);

    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                displayAllBooks(books, numBooks);
                break;
            case 2:
                searchByAuthor(books, numBooks);
                break;
            case 3:
                searchByPublisher(books, numBooks);
                break;
            case 4:
                searchByYear(books, numBooks);
                break;
            case 5:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while(choice != 5);

    return 0;
}