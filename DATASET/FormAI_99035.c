//FormAI DATASET v1.0 Category: Ebook reader ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define MAX_PAGES 100
#define MAX_CHARS_PER_PAGE 1000

void readBook(char** book);
void initBook(char** book);
void printPageIndex(int currentPage, int totalPages);
void printPage(char** book, int currentPage);

int main(void){
    char* book[MAX_PAGES] = {NULL};
    int currentPage = 0, totalPages = 0;
    initBook(book);
    readBook(book);
    totalPages = sizeof(book) / sizeof(char*);
    while (1) {
        system("clear");
        printPageIndex(currentPage, totalPages);
        printPage(book, currentPage);
        char input = getchar();
        if (input == 'n' && currentPage + 1 < totalPages) {
            ++currentPage;
        } else if (input == 'p' && currentPage - 1 >= 0) {
            --currentPage;
        } else if (input == 'q') {
            break;
        }
    }
    return 0;
}

void readBook(char** book){
    FILE* fp = fopen("book.txt", "r");
    char currentLine[MAX_CHARS_PER_PAGE];
    int i = 0;
    while (fgets(currentLine, MAX_CHARS_PER_PAGE, fp) != NULL) {
        if (i < MAX_PAGES) {
            book[i++] = strdup(currentLine);
        } else {
            printf("Warning: Book exceeds maximum number of pages.\n");
            break;
        }
    }
    fclose(fp);
}

void initBook(char** book){
    for (int i = 0; i < MAX_PAGES; i++) {
        book[i] = NULL;
    }
}

void printPageIndex(int currentPage, int totalPages){
    printf("Page %d of %d | Press 'p' for previous page | Press 'n' for next page | Press 'q' to quit\n\n", currentPage+1, totalPages);
}

void printPage(char** book, int currentPage){
    char* page = book[currentPage];
    if (page == NULL) {
        printf("Empty Page");
    } else {
        printf("%s", page);
    }
}