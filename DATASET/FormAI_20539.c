//FormAI DATASET v1.0 Category: Ebook reader ; Style: expert-level
#include <stdio.h>

// Define the maximum number of pages in the ebook
#define MAX_PAGES 500

// Define the maximum length of a page in characters
#define PAGE_LENGTH 1000

int main()
{
    char book[MAX_PAGES][PAGE_LENGTH];
    int num_pages = 0;
    int current_page = 0;
    
    // Open the ebook file
    FILE *fp = fopen("ebook.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open ebook file\n");
        return 1;
    }
    
    // Read the ebook into memory
    while (fgets(book[num_pages], PAGE_LENGTH, fp)) {
        num_pages++;
    }
    
    // Close the ebook file
    fclose(fp);
    
    // Print instructions for the user
    printf("Welcome to the E-Book reader!\n");
    printf("Press 'n' to go to the next page or 'q' to quit.\n");
    
    // Main reading loop
    char input = ' ';
    while (input != 'q') {
        // Print the current page
        printf("%s\n", book[current_page]);
        
        // Wait for user input
        input = getchar();
        
        // Go to the next page if the user presses 'n'
        if (input == 'n') {
            current_page++;
            
            // If we've reached the end of the book, loop back to the beginning
            if (current_page == num_pages) {
                current_page = 0;
            }
        }
    }
    
    return 0;
}