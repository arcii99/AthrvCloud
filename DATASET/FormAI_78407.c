//FormAI DATASET v1.0 Category: Ebook reader ; Style: ephemeral
#include <stdio.h>

int main() {
    int bookLength;
    int currentPage = 1;

    printf("Welcome to the Ebook Reader program! \n\n");
    printf("Please enter the length of the book (in pages): ");
    scanf("%d", &bookLength);

    while (currentPage <= bookLength) {
        printf("--Page %d--\n", currentPage);
        printf("...\n");
        printf("Press 'n' to go to the next page. Press 's' to stop reading.\n");

        char option;
        scanf(" %c", &option);

        if (option == 'n') {
            currentPage++;
        } else if (option == 's') {
            printf("\nThank you for using the Ebook Reader program!");
            break;
        } else {
            printf("\nInvalid input. Please try again.\n");
        }
    }

    return 0;
}