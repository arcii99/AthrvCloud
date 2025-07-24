//FormAI DATASET v1.0 Category: Ebook reader ; Style: ephemeral
#include <stdio.h>

int main() {
    char bookTitle[50];
    printf("Welcome to Unique C Ebook Reader\n");

    printf("Enter the title of the book you want to read: ");
    scanf("%s", bookTitle);

    FILE *book = fopen(bookTitle, "r");

    if (book == NULL) {
        printf("Error opening book!");
        return -1;
    }

    printf("\n%s:\n\n", bookTitle);

    char character = fgetc(book);
    int lineCount = 1;
    int pageNumber = 1;

    while (character != EOF) {
        printf("%c", character);
        character = fgetc(book);

        if (lineCount % 40 == 0) {
            printf("\nPage %d\n", pageNumber);
            pageNumber++;
        }

        if (character == '\n') {
            lineCount++;
        }
    }

    printf("\nEnd of Book\n");

    fclose(book);
    return 0;
}