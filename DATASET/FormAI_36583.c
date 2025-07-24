//FormAI DATASET v1.0 Category: Ebook reader ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX_PAGES 100

// Define struct for Ebook Page
typedef struct {
    char title[50];
    int number;
    char content[1000];
} EbookPage;

// Define struct for Ebook Reader
typedef struct {
    EbookPage pages[MAX_PAGES];
    int currentPage;
    int totalPages;
} EbookReader;

// Function to add page to Ebook Reader
void addPage(EbookReader *reader, EbookPage page) {
    reader->pages[reader->totalPages] = page;
    reader->totalPages++;
}

// Function to display current page on Ebook Reader
void displayPage(EbookReader *reader) {
    printf("%s\n\n", reader->pages[reader->currentPage].title);
    printf("%s\n\n", reader->pages[reader->currentPage].content);
}

// Function to move to next page on Ebook Reader
void nextPage(EbookReader *reader) {
    if (reader->currentPage >= reader->totalPages-1) {
        printf("End of Ebook reached.\n");
    } else {
        reader->currentPage++;
        displayPage(reader);
    }
}

// Function to move to previous page on Ebook Reader
void prevPage(EbookReader *reader) {
    if (reader->currentPage <= 0) {
        printf("Beginning of Ebook reached.\n");
    } else {
        reader->currentPage--;
        displayPage(reader);
    }
}

int main() {
    EbookReader reader;
    EbookPage p1 = { "Introduction", 1, "Welcome to my Ebook reader!" };
    EbookPage p2 = { "Chapter 1", 2, "This is the content for chapter 1." };
    EbookPage p3 = { "Chapter 2", 3, "This is the content for chapter 2." };
    EbookPage p4 = { "Conclusion", 4, "That's all folks." };
    
    // Add pages to Ebook Reader
    addPage(&reader, p1);
    addPage(&reader, p2);
    addPage(&reader, p3);
    addPage(&reader, p4);
    
    // Set current page to first page
    reader.currentPage = 0;
    
    // Display first page
    displayPage(&reader);
    
    // Let user navigate Ebook
    char input[10];
    while (1) {
        printf("Enter 'n' for next page, 'p' for previous page, or 'q' to quit: ");
        scanf("%s", input);
        if (input[0] == 'n') {
            nextPage(&reader);
        } else if (input[0] == 'p') {
            prevPage(&reader);
        } else if (input[0] == 'q') {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }
    
    return 0;
}