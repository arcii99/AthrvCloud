//FormAI DATASET v1.0 Category: Ebook reader ; Style: cheerful
#include <stdio.h>

int main() {
    printf("Welcome to the Cheery Ebook Reader!\n");
    printf("Please enter the name of the book you would like to read: ");

    char book_name[50];
    scanf("%s", book_name);

    printf("\nOpening book: %s\n", book_name);

    FILE *book_file = fopen(book_name, "r");
    char c;

    if (book_file) {
        while ((c = getc(book_file)) != EOF)
            putchar(c);

        fclose(book_file);
    } else {
        printf("Oops! Unable to open book. Please try again.\n");
    }

    printf("\nThank you for using the Cheery Ebook Reader! Happy reading!\n");

    return 0;
}