//FormAI DATASET v1.0 Category: Ebook reader ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PAGES 100
#define MAX_CHAPTERS 10

struct page {
    char* text;
};

struct chapter {
    char* title;
    struct page pages[MAX_PAGES];
};

struct ebook {
    char* title;
    char* author;
    struct chapter chapters[MAX_CHAPTERS];
    int curr_chapter;
    int curr_page;
};

void print_page(struct page p) {
    printf("%s\n", p.text);
}

void print_chapter(struct chapter c) {
    int i;
    printf("%s\n", c.title);
    for (i = 0; i < MAX_PAGES; i++) {
        if (c.pages[i].text != NULL) {
            print_page(c.pages[i]);
        }
    }
}

void print_ebook(struct ebook e) {
    int i;
    printf("%s by %s\n", e.title, e.author);
    for (i = 0; i < MAX_CHAPTERS; i++) {
        if (e.chapters[i].title != NULL) {
            print_chapter(e.chapters[i]);
        }
    }
}

int main() {
    struct ebook my_ebook;
    my_ebook.title = "The Chronicles of Elvandar";
    my_ebook.author = "Lord Ithilien";
    my_ebook.curr_chapter = 0;
    my_ebook.curr_page = 0;
    
    struct chapter chapter1;
    chapter1.title = "The Beginning";
    struct page chapter1_page1 = {"In the land of Elvandar, deep in the heart of the forest..."};    
    chapter1.pages[0] = chapter1_page1;
    my_ebook.chapters[0] = chapter1;

    struct chapter chapter2;
    chapter2.title = "The Quest";
    struct page chapter2_page1 = {"After many long years of peace..."};    
    chapter2.pages[0] = chapter2_page1;
    my_ebook.chapters[1] = chapter2;
    
    print_ebook(my_ebook);
    
    return 0;
}