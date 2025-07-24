//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100

struct FileMetadata {
    char author[MAX_STR_LEN];
    char title[MAX_STR_LEN];
    char publisher[MAX_STR_LEN];
};

typedef struct FileMetadata file_data;

int main() {
    file_data my_book;
    char user_input[MAX_STR_LEN];

    printf("Greetings traveler! Pray, what is thy name?\n");
    fgets(my_book.author, MAX_STR_LEN, stdin);
    my_book.author[strcspn(my_book.author, "\n")] = 0;

    printf("Welcome, %s! What is the title of thy tome?\n", my_book.author);
    fgets(my_book.title, MAX_STR_LEN, stdin);
    my_book.title[strcspn(my_book.title, "\n")] = 0;

    printf("Enlighten us, %s, who hath crafted this work of art?\n", my_book.author);
    fgets(my_book.publisher, MAX_STR_LEN, stdin);
    my_book.publisher[strcspn(my_book.publisher, "\n")] = 0;

    printf("\nAh, we see! The author of this piece is none other than %s, the publisher is %s, and the title is %s.\n", my_book.author, my_book.publisher, my_book.title);

    return 0;
}