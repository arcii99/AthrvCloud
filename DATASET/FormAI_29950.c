//FormAI DATASET v1.0 Category: Ebook reader ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

typedef struct Book {
    char title[50];
    char author[50];
    char publisher[50];
    int pageCount;
} Book;

typedef struct Node {
    Book *book;
    struct Node *next;
} Node;

Node *head = NULL; // Head node of the linked list

// Add a book to the linked list
void addBook(Book *book) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->book = book;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node *currentNode = head;
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
}

// Display the list of books in the linked list
void displayBooks() {
    Node *currentNode = head;

    printf("+---------------------------------------------+\n");
    printf("|%-25s|%-25s|%-25s|%-8s|\n", "Title", "Author", "Publisher", "Pages");
    printf("+---------------------------------------------+\n");

    while (currentNode != NULL) {
        printf("|%-25s|%-25s|%-25s|%-8d|\n", currentNode->book->title, currentNode->book->author,
               currentNode->book->publisher, currentNode->book->pageCount);
        currentNode = currentNode->next;
    }

    printf("+---------------------------------------------+\n");
}

int main() {
    Book book1, book2, book3;

    // Book 1
    strcpy(book1.title, "C Programming Absolute Beginner's Guide (3rd Edition)");
    strcpy(book1.author, "Greg Perry");
    strcpy(book1.publisher, "Que Publishing");
    book1.pageCount = 352;

    // Book 2
    strcpy(book2.title, "Head First C: A Brain-Friendly Guide (2nd Edition)");
    strcpy(book2.author, "David Griffiths");
    strcpy(book2.publisher, "O'Reilly Media");
    book2.pageCount = 632;

    // Book 3
    strcpy(book3.title, "Programming in C (4th Edition)");
    strcpy(book3.author, "Stephen G. Kochan");
    strcpy(book3.publisher, "Addison-Wesley Professional");
    book3.pageCount = 600;

    // Add the books to the linked list
    addBook(&book1);
    addBook(&book2);
    addBook(&book3);

    // Display the list of books
    displayBooks();

    return 0;
}