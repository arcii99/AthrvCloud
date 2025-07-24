//FormAI DATASET v1.0 Category: Ebook reader ; Style: energetic
#include <stdio.h>

int main() {
    int pages = 0;
    int currentPage = 0;
    char bookTitle[50];
    char authorName[50];
    printf("Enter the name of the book: ");
    scanf("%s", bookTitle);
    printf("Enter the name of the author: ");
    scanf("%s", authorName);
    printf("Enter the number of pages in the book: ");
    scanf("%d", &pages);
    printf("\n");
    printf("Browsing through %s by %s\n", bookTitle, authorName);
    printf("-----------------------------\n");
    printf("Press n to go to next page, p to go to previous page, and q to quit.\n\n");
    while (1) {
        printf("Page %d of %d\n", currentPage+1, pages);
        char input = getchar();
        if (input == 'n') {
            currentPage = currentPage < pages-1 ? currentPage+1 : currentPage;
        } else if (input == 'p') {
            currentPage = currentPage > 0 ? currentPage-1 : currentPage;
        } else if (input == 'q') {
            break;
        }
    }
    printf("Thank you for reading %s by %s!\n", bookTitle, authorName);
    return 0;
}