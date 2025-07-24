//FormAI DATASET v1.0 Category: Ebook reader ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 10
#define MAX_TITLE_LENGTH 50
#define MAX_CHAPTERS 50
#define MAX_CHAPTER_LENGTH 10000

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char chapters[MAX_CHAPTERS][MAX_CHAPTER_LENGTH];
    int num_chapters;
} book;

book ebooks[MAX_BOOKS];
int num_ebooks = 0;

int read_book(char* filename) {
    // Read in the book from the file and save it to the global array of ebooks
    FILE* f = fopen(filename, "r");
    if (!f) {
        printf("Error: File not found.\n");
        return 0;
    }
    book new_book;
    new_book.num_chapters = 0;
    while (!feof(f)) {
        fgets(new_book.title, MAX_TITLE_LENGTH, f);
        new_book.title[strcspn(new_book.title, "\n")] = 0;
        fgets(new_book.chapters[new_book.num_chapters], MAX_CHAPTER_LENGTH, f);
        new_book.chapters[new_book.num_chapters][strcspn(new_book.chapters[new_book.num_chapters], "\n")] = 0;
        new_book.num_chapters++;
    }
    fclose(f);
    ebooks[num_ebooks++] = new_book;
    return 1;
}

int display_book() {
    // Allow the user to choose a book to read and navigate its chapters
    int book_choice, chapter_choice = 0;
    printf("Please choose a book:\n");
    for (int i = 0; i < num_ebooks; i++) {
        printf("%d. %s\n", i+1, ebooks[i].title);
    }
    scanf("%d", &book_choice);
    if (book_choice > num_ebooks || book_choice <= 0) {
        printf("Invalid choice.\n");
        return 0;
    }
    book chosen_book = ebooks[book_choice-1];
    printf("You have chosen \"%s\".\n", chosen_book.title);
    while (chapter_choice != -1) {
        printf("Please choose a chapter to read (-1 to exit):\n");
        for (int i = 0; i < chosen_book.num_chapters; i++) {
            printf("%d. Chapter %d\n", i+1, i+1);
        }
        scanf("%d", &chapter_choice);
        if (chapter_choice > chosen_book.num_chapters) {
            printf("Invalid choice.\n");
        } else if (chapter_choice != -1) {
            printf("%s\n", chosen_book.chapters[chapter_choice-1]);
        }
    }
    return 1;
}

int main() {
    // Demonstrate the Ebook reader program
    printf("Welcome to the Ebook Reader!\n");
    int choice = -1;
    while (choice != 0) {
        printf("Please choose an option:\n");
        printf("1. Read a book.\n");
        printf("2. Exit.\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Please enter the filename of the book you wish to read:\n");
                char filename[MAX_TITLE_LENGTH];
                scanf("%s", filename);
                if (read_book(filename)) {
                    display_book();
                }
                break;
            case 2:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}