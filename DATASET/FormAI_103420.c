//FormAI DATASET v1.0 Category: Database Indexing System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100 //max number of books in database
#define TABLE_SIZE 10 //size of hash table

//struct for a single book record
typedef struct {
    int id;
    char title[50];
    char author[50];
} Book;

//struct for the hash table
typedef struct {
    Book* books[MAX_SIZE];
} HashTable;

//function to create a new book record
Book* createBook(int id, char* title, char* author) {
    Book* newBook = (Book*) malloc(sizeof(Book));
    newBook->id = id;
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    return newBook;
}

//hash function to map book ids to hash table indices
int hash(int id) {
    return id % TABLE_SIZE;
}

//function to add a book to the database
void addBook(HashTable* database, Book* newBook) {
    int index = hash(newBook->id);
    database->books[index] = newBook;
}

//function to search for a book by id
Book* searchBook(HashTable* database, int id) {
    int index = hash(id);
    return database->books[index];
}

//function to delete a book by id
void deleteBook(HashTable* database, int id) {
    int index = hash(id);
    free(database->books[index]);
    database->books[index] = NULL;
}

//function to display all books in the database
void displayBooks(HashTable* database) {
    printf("Books in database:\n");
    for(int i = 0; i < TABLE_SIZE; i++) {
        if(database->books[i] != NULL) {
            printf("\nID: %d\nTitle: %s\nAuthor: %s\n", database->books[i]->id, database->books[i]->title, database->books[i]->author);
        }
    }
}

int main() {
    HashTable database;
    for(int i = 0; i < MAX_SIZE; i++) {
        database.books[i] = NULL;
    }
    int choice;
    do {
        printf("\n1. Add a book\n2. Search for a book\n3. Delete a book\n4. Display all books\n5. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                int id;
                char title[50];
                char author[50];
                printf("\nEnter book ID: ");
                scanf("%d", &id);
                printf("Enter book title: ");
                scanf("%s", title);
                printf("Enter book author: ");
                scanf("%s", author);
                Book* newBook = createBook(id, title, author);
                addBook(&database, newBook);
                printf("Book added to database.\n");
                break;
            }
            case 2: {
                int id;
                printf("\nEnter book ID to search: ");
                scanf("%d", &id);
                Book* foundBook = searchBook(&database, id);
                if(foundBook != NULL) {
                    printf("Book found:\nID: %d\nTitle: %s\nAuthor: %s\n", foundBook->id, foundBook->title, foundBook->author);
                }
                else {
                    printf("Book not found.\n");
                }
                break;
            }
            case 3: {
                int id;
                printf("\nEnter book ID to delete: ");
                scanf("%d", &id);
                deleteBook(&database, id);
                printf("Book deleted from database.\n");
                break;
            }
            case 4: {
                displayBooks(&database);
                break;
            }
            case 5: {
                printf("\nExiting program...\n");
                return 0;
            }
            default: {
                printf("\nInvalid choice.\n");
                break;
            }
        }
    } while(choice != 5);

    return 0;
}