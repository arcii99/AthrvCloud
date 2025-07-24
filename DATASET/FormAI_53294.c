//FormAI DATASET v1.0 Category: Ebook reader ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PAGES 500
#define MAX_CHARS_PER_PAGE 5000

// Digital circuit for reading an eBook page
struct eBookPage {
    char content[MAX_CHARS_PER_PAGE];
    int currentPage;
};

// Function to read a page from the eBook
void readPage(struct eBookPage* page) {
    printf("Reading page %d...\n", page->currentPage);
    // Read page content from a file and store it in the page struct
    FILE* pageFile = fopen("eBook.txt", "r");
    if (pageFile == NULL) {
        printf("Error: could not open eBook file.\n");
        exit(1);
    }
    fseek(pageFile, page->currentPage * MAX_CHARS_PER_PAGE, SEEK_SET);
    fgets(page->content, MAX_CHARS_PER_PAGE, pageFile);
    fclose(pageFile);
}

// Function to go to the next page in the eBook
void next_page(struct eBookPage* page) {
    if (page->currentPage < MAX_PAGES - 1) {
        page->currentPage++;
        readPage(page);
    }
}

// Function to go to the previous page in the eBook
void prev_page(struct eBookPage* page) {
    if (page->currentPage > 0) {
        page->currentPage--;
        readPage(page);
    }
}

// Main function to run the eBook reader
int main() {
    struct eBookPage page;
    page.currentPage = 0;
    readPage(&page);

    // Loop to read pages based on user input
    while (true) {
        // Print current page content to the console
        printf("\n%s\n", page.content);

        // Prompt user for next action
        printf("Enter 'n' for next page, 'p' for previous page, or 'q' to quit.\n");
        char userInput = getchar();
        fflush(stdin);

        switch (userInput) {
            case 'n':
                next_page(&page);
                break;
            case 'p':
                prev_page(&page);
                break;
            case 'q':
                printf("Exiting eBook reader.\n");
                exit(0);
            default:
                printf("Invalid input. Enter 'n', 'p', or 'q'.\n");
        }
    }

    return 0;
}