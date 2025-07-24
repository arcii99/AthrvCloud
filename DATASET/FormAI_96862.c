//FormAI DATASET v1.0 Category: Data mining ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Creating a structure to hold information about each book
struct Book {
    char title[50];
    char author[50];
    int year_published;
};

int main() {
    // Creating an array of books to be mined
    struct Book library[5];

    // Filling the array with dummy data
    strcpy(library[0].title, "Harry Potter and the Chamber of Secrets");
    strcpy(library[0].author, "J.K. Rowling");
    library[0].year_published = 1998;

    strcpy(library[1].title, "Lord of the Rings: The Fellowship of the Ring");
    strcpy(library[1].author, "J.R.R. Tolkien");
    library[1].year_published = 1954;

    strcpy(library[2].title, "The Hitchhiker's Guide to the Galaxy");
    strcpy(library[2].author, "Douglas Adams");
    library[2].year_published = 1979;

    strcpy(library[3].title, "To Kill a Mockingbird");
    strcpy(library[3].author, "Harper Lee");
    library[3].year_published = 1960;

    strcpy(library[4].title, "Pride and Prejudice");
    strcpy(library[4].author, "Jane Austen");
    library[4].year_published = 1813;

    // Sorting the array by year_published in ascending order
    for(int i = 0; i < 5; i++) {
        for(int j = i + 1; j < 5; j++) {
            if(library[i].year_published > library[j].year_published) {
                struct Book temp = library[i];
                library[i] = library[j];
                library[j] = temp;
            }
        }
    }

    // Finding the book with the latest year_published using linear search
    int latest_year = 0;
    int latest_index = 0;
    for(int i = 0; i < 5; i++) {
        if(library[i].year_published > latest_year) {
            latest_year = library[i].year_published;
            latest_index = i;
        }
    }

    // Displaying the book with the latest year_published
    printf("The book with the latest year_published is:\n");
    printf("%s by %s, published in %d\n", library[latest_index].title, library[latest_index].author, library[latest_index].year_published);

    return 0;
}