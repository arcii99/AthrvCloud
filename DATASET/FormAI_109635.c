//FormAI DATASET v1.0 Category: Ebook reader ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_PAGES 100
#define MAX_CHARS_PER_PAGE 1000

// Define a struct to represent a Ebook
typedef struct {
    char title[50];
    char author[50];
    int publication_year;
    char pages[MAX_PAGES][MAX_CHARS_PER_PAGE];
    int num_pages;
    int current_page;
} Ebook;

int main() {
    // Declare and initialize variables
    Ebook ebook = {
        .title = "Cryptic Ebook",
        .author = "Bot",
        .publication_year = 2021,
        .pages = {
            "This is a cryptic ebook written in C.",
            "The code is difficult to understand at first glance,",
            "but with careful reading and interpretation,",
            "you will unlock its secrets.",
            "Each page is limited to 1000 characters,",
            "so some sections may be split across multiple pages.",
            "Use the arrow keys to navigate through the book.",
            "Press 'q' to quit and save your progress."
        },
        .num_pages = 8,
        .current_page = 0
    };

    // Display the current page of the ebook
    printf("%s\n\n", ebook.pages[ebook.current_page]);

    // Wait for user input
    char input;
    do {
        input = getchar();

        // Process user input
        switch (input) {
            case 'q':
                printf("Saving progress...done!\n");
                break;
            case '\033':
                // Arrow key pressed, check which one
                getchar(); // Ignore the [
                char arrow = getchar();
                switch (arrow) {
                    case 'A':
                        // Up arrow, go back a page
                        if (ebook.current_page > 0) {
                            ebook.current_page--;
                        }
                        break;
      
                    case 'B':
                        // Down arrow, go forward a page
                        if (ebook.current_page < ebook.num_pages - 1) {
                            ebook.current_page++;
                        }
                        break;
                }
                // Clear the console and display the new page
                system("clear");
                printf("%s\n\n", ebook.pages[ebook.current_page]);
                break;
        }
    } while (input != 'q');

    return 0;
}