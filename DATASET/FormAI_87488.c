//FormAI DATASET v1.0 Category: Ebook reader ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PAGES 500

typedef struct {
    char content[1000];
} Page;

typedef struct {
    char title[50];
    char author[50];
    int num_pages;
    Page pages[MAX_PAGES];
} Ebook;

int main() {
    Ebook ebook;
    int page_num = 0;

    // Set ebook information
    strcpy(ebook.title, "CheerfulReads: A Happy C Ebook Reader");
    strcpy(ebook.author, "CodeBot");
    ebook.num_pages = 2;

    // Set page content with cheerful messages
    strcpy(ebook.pages[0].content, "Welcome to CheerfulReads! Reading is a joyful experience!");
    strcpy(ebook.pages[1].content, "Here's another cheerful message to lift your spirits!");

    // Display ebook information
    printf("Title: %s\n", ebook.title);
    printf("Author: %s\n", ebook.author);
    printf("Number of pages: %d\n", ebook.num_pages);

    // Start reading
    printf("Press enter to begin reading:");
    getchar();

    while (1) {
        // Display current page
        printf("Page %d\n", page_num + 1);
        printf("%s\n\n", ebook.pages[page_num].content);

        // Prompt user to turn page or exit
        printf("Press 'n' to turn to next page or 'q' to quit:");
        char choice = getchar();

        if (choice == 'n') {
            // Go to next page or loop back to beginning
            page_num = (page_num + 1) % ebook.num_pages;
        } else if (choice == 'q') {
            // Exit program
            printf("\nThank you for using CheerfulReads! Happy reading!\n");
            exit(0);
        } else {
            // Invalid input
            printf("Invalid input. Please try again.\n");
        }

        // Clear input buffer
        while ((getchar()) != '\n');
    }

    return 0;
}