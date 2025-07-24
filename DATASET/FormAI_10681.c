//FormAI DATASET v1.0 Category: Ebook reader ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int num_of_pages;
    printf("Enter the number of pages in the eBook: ");
    scanf("%d", &num_of_pages);

    int current_page = 1;
    printf("You are currently on page %d.\n", current_page);

    while (1) {
        char user_input;
        printf("Press 'n' for next page, 'p' for previous page, or 'q' to quit: ");
        scanf(" %c", &user_input);

        if (user_input == 'n') {
            if (current_page < num_of_pages) {
                current_page++;
                printf("You are now on page %d.\n", current_page);
            } else {
                printf("You have reached the end of the eBook.\n");
            }
        } else if (user_input == 'p') {
            if (current_page > 1) {
                current_page--;
                printf("You are now on page %d.\n", current_page);
            } else {
                printf("You are already on the first page.\n");
            }
        } else if (user_input == 'q') {
            printf("Exiting the eBook reader.\n");
            break;
        } else {
            printf("Invalid input. Try again.\n");
        }
    }

    return 0;
}