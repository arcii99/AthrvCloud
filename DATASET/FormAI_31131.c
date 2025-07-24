//FormAI DATASET v1.0 Category: Database simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>

struct book {
    char title[50];
    char author[50];
    int year;
};

int main() {
    // Initialize database
    struct book database[5];

    // Add books to the database
    strcpy(database[0].title, "Pride and Prejudice");
    strcpy(database[0].author, "Jane Austen");
    database[0].year = 1813;

    strcpy(database[1].title, "To Kill a Mockingbird");
    strcpy(database[1].author, "Harper Lee");
    database[1].year = 1960;

    strcpy(database[2].title, "The Great Gatsby");
    strcpy(database[2].author, "F. Scott Fitzgerald");
    database[2].year = 1925;

    strcpy(database[3].title, "One Hundred Years of Solitude");
    strcpy(database[3].author, "Gabriel Garcia Marquez");
    database[3].year = 1967;

    strcpy(database[4].title, "1984");
    strcpy(database[4].author, "George Orwell");
    database[4].year = 1949;

    // Print the database
    printf("Database:\n");
    printf("Title\t\tAuthor\t\tYear\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\t\t%s\t\t%d\n", database[i].title, database[i].author, database[i].year);
    }

    // Update a book
    strcpy(database[2].title, "The Great Gatsby (1926 Version)");
    database[2].year = 1926;

    // Print the updated database
    printf("\nUpdated Database:\n");
    printf("Title\t\tAuthor\t\tYear\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\t\t%s\t\t%d\n", database[i].title, database[i].author, database[i].year);
    }

    return 0;
}