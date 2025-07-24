//FormAI DATASET v1.0 Category: Ebook reader ; Style: invasive
#include <stdio.h>

int main() {
    char bookTitle[50];
    int numPages, currentPage = 1;
    
    printf("Welcome to the Ebook reader program!\n");
    printf("Please enter the title of the book you would like to read: ");
    scanf("%s", bookTitle);
    
    printf("Please enter the number of pages in the book: ");
    scanf("%d", &numPages);
    
    printf("\n%s has %d pages. Let's start reading!\n\n", bookTitle, numPages);
    
    while(currentPage <= numPages) {
        printf("===== Page %d =====\n", currentPage);
        printf("Here is the content for page %d.\n", currentPage);
        printf("Press 'n' to go to the next page or 'q' to quit: ");
        
        char userChoice;
        scanf(" %c", &userChoice);
        
        if(userChoice == 'n') {
            currentPage++;
            printf("\n");
        } else if(userChoice == 'q') {
            printf("\nThanks for reading %s!\n", bookTitle);
            return 0;
        } else {
            printf("\nInvalid choice. Please try again.\n\n");
        }
    }
    
    printf("\nCongratulations! You have finished reading %s!\n", bookTitle);
    return 0;
}