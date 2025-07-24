//FormAI DATASET v1.0 Category: Ebook reader ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_PAGES 1000
#define MAX_CHAPTERS 50

// Define page and chapter structs
typedef struct {
    char* content;
} Page;

typedef struct {
    char* title;
    int num_pages;
    Page* pages[MAX_PAGES];
} Chapter;

// Define book struct
typedef struct {
    char* author;
    char* title;
    int num_chapters;
    Chapter* chapters[MAX_CHAPTERS];
} Ebook;

int main() {
    // Declare and initialize book content
    Ebook my_book = {
        .author = "Jane Smith",
        .title = "My Ebook",
        .num_chapters = 3,
    };
    
    // Add chapters to book
    Chapter chapter1 = {
        .title = "Chapter 1",
        .num_pages = 2,
    };
    Page page11 = {.content = "Page 1 content for chapter 1"};
    Page page12 = {.content = "Page 2 content for chapter 1"};
    chapter1.pages[0] = &page11;
    chapter1.pages[1] = &page12;
    my_book.chapters[0] = &chapter1;
    
    Chapter chapter2 = {
        .title = "Chapter 2",
        .num_pages = 1,
    };
    Page page21 = {.content = "Page 1 content for chapter 2"};
    chapter2.pages[0] = &page21;
    my_book.chapters[1] = &chapter2;
    
    Chapter chapter3 = {
        .title = "Chapter 3",
        .num_pages = 3,
    };
    Page page31 = {.content = "Page 1 content for chapter 3"};
    Page page32 = {.content = "Page 2 content for chapter 3"};
    Page page33 = {.content = "Page 3 content for chapter 3"};
    chapter3.pages[0] = &page31;
    chapter3.pages[1] = &page32;
    chapter3.pages[2] = &page33;
    my_book.chapters[2] = &chapter3;
    
    // Print book content
    printf("Author: %s\n", my_book.author);
    printf("Title: %s\n", my_book.title);
    printf("\n");
    
    for (int i = 0; i < my_book.num_chapters; i++) {
        Chapter* chapter = my_book.chapters[i];
        printf("%s:\n", chapter->title);
        
        for (int j = 0; j < chapter->num_pages; j++) {
            Page* page = chapter->pages[j];
            printf("%s\n", page->content);
        }
        
        printf("\n");
    }
    
    return 0;
}