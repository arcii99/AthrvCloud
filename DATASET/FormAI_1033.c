//FormAI DATASET v1.0 Category: Ebook reader ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[50];
    char author[50];
    char publisher[50];
    int pages;
} Book;

typedef struct {
    Book book;
    int currentPage;
    int totalPages;
    char *content;
} Ebook;

// Function to display book information
void printBookInfo(Book book) {
    printf("\nTitle: %s", book.title);
    printf("\nAuthor: %s", book.author);
    printf("\nPublisher: %s", book.publisher);
    printf("\nNumber of Pages: %d", book.pages);
}

// Function to load content into ebook
void loadEbookContent(Ebook *ebook, char *filename) {
    FILE *fp;
    char *line;
    size_t len = 0;
    int numLines = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("\nError: Unable to open file.");
        exit(EXIT_FAILURE);
    }

    // Count number of lines in file
    while (getline(&line, &len, fp) != -1) {
        numLines++;
    }

    rewind(fp); // Reset file pointer to beginning

    // Initialize ebook content to proper length
    ebook->content = (char *) malloc(numLines * (len+1) * sizeof(char));

    // Read all text from file into ebook content
    int i = 0;
    while (getline(&line, &len, fp) != -1) {
        strcpy(&(ebook->content[i*(len+1)]), line);
        i++;
    }

    fclose(fp);
    if (line) {
        free(line);
    }
}

// Function to open ebook
void openEbook(Ebook *ebook) {
    printf("\nOpening ebook:");
    printBookInfo(ebook->book);
    printf("\n\n");

    printf("Contents:\n");
    printf("---------\n\n");
    printf("%s\n", ebook->content);

    ebook->currentPage = 1;
    ebook->totalPages = strlen(ebook->content) / 80;

    printf("\nPage 1/%d\n", ebook->totalPages);

    // Wait for user to press enter key
    getchar();
}

// Function to flip to next page in ebook
void flipNextPage(Ebook *ebook) {
    if (ebook->currentPage < ebook->totalPages) {
        ebook->currentPage++;
        printf("\n\nPage %d/%d\n", ebook->currentPage, ebook->totalPages);
        for (int i = (ebook->currentPage-1)*80; i < ebook->currentPage*80 && ebook->content[i] != '\0'; i++) {
            printf("%c", ebook->content[i]);
        }
    } else {
        printf("\n\nAlready at last page of ebook.");
    }

    // Wait for user to press enter key
    getchar();
}

// Function to flip to previous page in ebook
void flipPrevPage(Ebook *ebook) {
    if (ebook->currentPage > 1) {
        ebook->currentPage--;
        printf("\n\nPage %d/%d\n", ebook->currentPage, ebook->totalPages);
        for (int i = (ebook->currentPage-1)*80; i < ebook->currentPage*80 && ebook->content[i] != '\0'; i++) {
            printf("%c", ebook->content[i]);
        }
    } else {
        printf("\n\nAlready at first page of ebook.");
    }

    // Wait for user to press enter key
    getchar();
}

int main() {
    Ebook ebook;

    // Initialize ebook
    strcpy(ebook.book.title, "The Art of War");
    strcpy(ebook.book.author, "Sun Tzu");
    strcpy(ebook.book.publisher, "Oxford University Press");
    ebook.book.pages = 256;

    // Load ebook content from file
    loadEbookContent(&ebook, "art_of_war.txt");

    // Open ebook
    openEbook(&ebook);

    // Flip through pages
    flipNextPage(&ebook);
    flipNextPage(&ebook);
    flipPrevPage(&ebook);
    flipNextPage(&ebook);

    return 0;
}