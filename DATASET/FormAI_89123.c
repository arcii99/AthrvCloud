//FormAI DATASET v1.0 Category: Ebook reader ; Style: synchronous
#include <stdio.h>
#define MAX_PAGES 5000

// Define the Ebook struct
typedef struct Ebook {
    char title[100];
    char author[100];
    char pages[MAX_PAGES][20000];
    int num_pages;
} Ebook;

// Helper function to load an ebook from a file
void load_ebook(Ebook* book, char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open file: %s\n", filename);
        return;
    }

    fgets(book->title, 100, file);
    fgets(book->author, 100, file);

    int i = 0;
    while (fgets(book->pages[i], 20000, file)) {
        i++;
        if (i >= MAX_PAGES) {
            printf("File too large to load.\n");
            break;
        }
    }
    book->num_pages = i;

    fclose(file);
}

// Define the EbookReader struct
typedef struct EbookReader {
    Ebook book;
    int current_page;
} EbookReader;

// Helper function to initialize the EbookReader with a book
void initialize_reader(EbookReader* reader, char* filename) {
    load_ebook(&reader->book, filename);
    reader->current_page = 0;
}

// Main program
int main() {
    EbookReader reader;
    initialize_reader(&reader, "book.txt");

    // Print out the author and title of the book
    printf("Author: %s\n", reader.book.author);
    printf("Title: %s\n", reader.book.title);

    // Print out the first page of the book
    printf("\n--- Page 1 ---\n%s\n", reader.book.pages[0]);

    // Loop to get user input
    char input = ' ';
    while (input != 'q') {
        printf("\nEnter command (n,p,q): ");
        scanf(" %c", &input);

        if (input == 'n') {
            reader.current_page++;
            if (reader.current_page >= reader.book.num_pages) {
                printf("End of book reached.\n");
                reader.current_page--;
            }
            else {
                printf("\n--- Page %d ---\n%s\n", reader.current_page + 1, reader.book.pages[reader.current_page]);
            }
        }
        else if (input == 'p') {
            reader.current_page--;
            if (reader.current_page < 0) {
                printf("Beginning of book reached.\n");
                reader.current_page++;
            }
            else {
                printf("\n--- Page %d ---\n%s\n", reader.current_page + 1, reader.book.pages[reader.current_page]);
            }
        }
    }

    printf("\nGoodbye!\n");
    return 0;
}