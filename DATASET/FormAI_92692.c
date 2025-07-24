//FormAI DATASET v1.0 Category: Ebook reader ; Style: cheerful
#include <stdio.h>

#define MAX_PAGES 100

int main(void) {
    int num_pages = 0;
    char* book_title = "The Joy of Programming";
    char* author_name = "Codey McCoderface";
    char* page_contents[MAX_PAGES];

    // Load ebook pages into memory
    for (int i = 0; i < MAX_PAGES; ++i) {
        page_contents[i] = malloc(sizeof(char) * 256);
        snprintf(page_contents[i], sizeof(char) * 256, "This is page %d of \"%s\" by %s.", i+1, book_title, author_name);
        num_pages++;
    }

    // Print welcome message
    printf("Welcome to the C Ebook Reader!\n\n");

    // Loop through book pages until user quits
    while (1) {
        int page_num;
        printf("Enter a page number (1-%d) or 'q' to quit: ", num_pages);
        char input[10];
        scanf("%s", input);

        // Check if user wants to quit
        if (input[0] == 'q') {
            break;
        }

        // Otherwise, try to convert input to integer page number
        sscanf(input, "%d", &page_num);

        // Check if page number is within allowed range
        if (page_num < 1 || page_num > num_pages) {
            printf("Invalid page number.\n");
            continue;
        }

        // Print the contents of the requested page
        printf("\n%s\n\n", page_contents[page_num-1]);
    }

    // Free allocated memory for page contents
    for (int i = 0; i < MAX_PAGES; ++i) {
        free(page_contents[i]);
    }

    // Print goodbye message
    printf("Thanks for reading \"%s\" by %s!\n", book_title, author_name);

    return 0;
}