//FormAI DATASET v1.0 Category: Data mining ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct data type for a book
typedef struct {
    char title[50];
    char author[50];
    int year_published;
} Book;

// Define a struct data type for a node in a linked list
typedef struct node {
    Book book;
    struct node *next;
} Node;

// Function prototypes
void insert_book(Node **head, Book book);
void print_books(Node *head);
void delete_books(Node **head);
Book create_book(char title[], char author[], int year_published);

int main() {
    Node *head = NULL;

    // Create some Book instances
    Book book1 = create_book("The Great Gatsby", "F. Scott Fitzgerald", 1925);
    Book book2 = create_book("To Kill a Mockingbird", "Harper Lee", 1960);
    Book book3 = create_book("1984", "George Orwell", 1949);
    Book book4 = create_book("The Catcher in the Rye", "J.D. Salinger", 1951);

    // Insert the books into a linked list
    insert_book(&head, book1);
    insert_book(&head, book2);
    insert_book(&head, book3);
    insert_book(&head, book4);

    // Print out the books in the linked list
    print_books(head);

    // Delete the books from the linked list
    delete_books(&head);

    return 0;
}

// Function to insert a book into a linked list
void insert_book(Node **head, Book book) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->book = book;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        Node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Function to print out all the books in a linked list
void print_books(Node *head) {
    Node *current = head;

    while (current != NULL) {
        printf("%s by %s (%d)\n", current->book.title, current->book.author, current->book.year_published);
        current = current->next;
    }
}

// Function to delete all the books from a linked list
void delete_books(Node **head) {
    Node *current = *head;
    Node *next_node;

    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }

    *head = NULL;
}

// Function to create a new book instance
Book create_book(char title[], char author[], int year_published) {
    Book book;
    strcpy(book.title, title);
    strcpy(book.author, author);
    book.year_published = year_published;
    return book;
}