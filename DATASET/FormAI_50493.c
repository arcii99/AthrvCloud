//FormAI DATASET v1.0 Category: Ebook reader ; Style: excited
#include <stdio.h>
#include <stdlib.h>

/* define maximum length of book title and book content */
#define TITLE_LENGTH 100
#define CONTENT_LENGTH 1000

/* define structure for ebook, including title and content */
struct ebook {
    char title[TITLE_LENGTH];
    char content[CONTENT_LENGTH];
};

int main() {

    /* initialize variables */
    int num_books, choice;
    struct ebook *library;

    /* prompt user to enter number of books in library */
    printf("How many books do you want to add to your library? ");
    scanf("%d", &num_books);

    /* allocate memory for library of ebooks */
    library = (struct ebook*) malloc(num_books * sizeof(struct ebook));

    /* prompt user to enter book title and content for each book */
    for (int i = 0; i < num_books; i++) {
        printf("\nEnter title for book %d: ", i+1);
        scanf("%s", library[i].title);
        printf("Enter content for book %d: ", i+1);
        scanf("\n%[^\n]", library[i].content);
    }

    /* prompt user to choose a book to read */
    printf("\nWhich book do you want to read? Enter number 1-%d: ", num_books);
    scanf("%d", &choice);

    /* print title and content of chosen book */
    printf("\nTitle: %s\nContent:\n%s", library[choice-1].title, library[choice-1].content);

    /* free allocated memory for library */
    free(library);

    return 0;
}