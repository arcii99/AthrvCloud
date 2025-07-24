//FormAI DATASET v1.0 Category: Ebook reader ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ebook {
    char* title;
    char* author;
    char* content;
    int num_pages;
} Ebook;

void read_ebook(Ebook* e) {
    printf("Reading ebook: %s by %s\n", e->title, e->author);
    printf("Number of pages: %d\n", e->num_pages);
    printf("Content:\n%s\n", e->content);
}

int main() {
    Ebook ebook1, ebook2;

    // Set ebook1 properties
    ebook1.title = "The Last Book on Earth";
    ebook1.author = "John Doe";
    ebook1.num_pages = 150;
    ebook1.content = "Lorem ipsum dolor sit amet, consectetur adipiscing elit....";

    // Set ebook2 properties
    ebook2.title = "Gone with the Wind";
    ebook2.author = "Margaret Mitchell";
    ebook2.num_pages = 500;
    ebook2.content = "Scarlett O'Hara is the headstrong and stubborn daughter of a wealthy Georgia plantation owner....";

    // Read the ebooks
    read_ebook(&ebook1);
    read_ebook(&ebook2);

    return 0;
}