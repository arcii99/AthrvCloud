//FormAI DATASET v1.0 Category: Ebook reader ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold eBook information
typedef struct {
    char title[100];
    char author[100];
    char publisher[100];
    int pages;
} eBook;

int main() {
    int numBooks;
    printf("How many eBooks do you want to read? ");
    scanf("%d", &numBooks);

    // Allocate memory for an array of eBooks
    eBook *bookArray = (eBook*) malloc(numBooks * sizeof(eBook));

    // Populate the array with eBook information
    for (int i = 0; i < numBooks; i++) {
        printf("Enter eBook %d title: ", i+1);
        scanf(" %[^\n]s", bookArray[i].title);
        printf("Enter eBook %d author: ", i+1);
        scanf(" %[^\n]s", bookArray[i].author);
        printf("Enter eBook %d publisher: ", i+1);
        scanf(" %[^\n]s", bookArray[i].publisher);
        printf("Enter eBook %d number of pages: ", i+1);
        scanf("%d", &bookArray[i].pages);
    }

    // Display the array of eBooks to the user
    printf("\n--- List of eBooks ---\n");
    for (int i = 0; i < numBooks; i++) {
        printf("Title: %s\n", bookArray[i].title);
        printf("Author: %s\n", bookArray[i].author);
        printf("Publisher: %s\n", bookArray[i].publisher);
        printf("Number of pages: %d\n", bookArray[i].pages);
        printf("\n");
    }

    // Free the memory allocated by the array of eBooks
    free(bookArray);

    return 0;
}