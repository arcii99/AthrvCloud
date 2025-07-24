//FormAI DATASET v1.0 Category: Ebook reader ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Welcome to the Happy E-Book Reader!\n");

    // Prompt user to enter book name and author name 
    char bookName[50];
    char authorName[50];
    printf("Please enter the name of the book: ");
    fgets(bookName, 50, stdin);
    printf("Please enter the name of the author: ");
    fgets(authorName, 50, stdin);

    // Display the book and author name
    printf("\nThe book you have selected is: %s", bookName);
    printf("The author is: %s", authorName);

    // Ask user to rate the book on a scale of 1 to 10
    int bookRating;
    printf("\n\nPlease rate this book on a scale of 1 (worst) to 10 (best): ");
    scanf("%d", &bookRating);

    // Confirm user's rating and give a positive response
    printf("\nYou have rated '%s' by %s a %d out of 10!", bookName, authorName, bookRating);
    printf("\nThank you for sharing your rating with us! We hope you continue to enjoy the Happy E-Book Reader!");

    return 0;
}