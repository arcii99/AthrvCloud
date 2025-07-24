//FormAI DATASET v1.0 Category: Ebook reader ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

struct Book {
    int id;
    char title[50];
    char author[50];
    char publisher[50];
    int year;
    float price;
};

struct Node {
    struct Book book;
    struct Node *next;
};

void addBook(struct Node **head, struct Book book) {
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->book = book;
    newNode->next = *head;
    *head = newNode;
}

void printBooks(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf("ID: %d\n", current->book.id);
        printf("Title: %s\n", current->book.title);
        printf("Author: %s\n", current->book.author);
        printf("Publisher: %s\n", current->book.publisher);
        printf("Year: %d\n", current->book.year);
        printf("Price: %.2f\n\n", current->book.price);
        current = current->next;
    }
}

void openBook(struct Book book) {
    printf("==============================\n\n");
    printf("Opening book '%s'...\n\n", book.title);
    printf("==============================\n\n");
    // Code for opening the book goes here
}

int main() {
    struct Node *head = NULL;
    struct Book book1, book2, book3;
    book1.id = 1;
    strcpy(book1.title, "C Programming for Beginners");
    strcpy(book1.author, "John Doe");
    strcpy(book1.publisher, "ABC Publications");
    book1.year = 2021;
    book1.price = 9.99;
    book2.id = 2;
    strcpy(book2.title, "Data Structures and Algorithms");
    strcpy(book2.author, "Jane Smith");
    strcpy(book2.publisher, "XYZ Publications");
    book2.year = 2020;
    book2.price = 19.99;
    book3.id = 3;
    strcpy(book3.title, "Object-Oriented Programming in C++");
    strcpy(book3.author, "Bob Johnson");
    strcpy(book3.publisher, "DEF Publications");
    book3.year = 2019;
    book3.price = 29.99;
    addBook(&head, book1);
    addBook(&head, book2);
    addBook(&head, book3);
    printBooks(head);
    int bookId;
    printf("Enter the ID of the book you want to open: ");
    scanf("%d", &bookId);
    struct Node *current = head;
    while (current != NULL) {
        if (current->book.id == bookId) {
            openBook(current->book);
            break;
        }
        current = current->next;
    }
    if (current == NULL) {
        printf("Book with ID %d not found!\n", bookId);
    }
    return 0;
}