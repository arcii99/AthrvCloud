//FormAI DATASET v1.0 Category: Ebook reader ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define MAX_BOOKS 100 // Maximum number of books that can be stored in the reader
#define MAX_TITLE_LENGTH 50 // Maximum length of book titles
#define MAX_AUTHOR_LENGTH 30 // Maximum length of author names
#define MAX_PAGES 1000 // Maximum number of pages in a book

struct Book {
    char title[MAX_TITLE_LENGTH]; // Title of the book
    char author[MAX_AUTHOR_LENGTH]; // Author of the book
    int page_count; // Number of pages in the book
    char* content[MAX_PAGES]; // Content of the book (an array of pointers to strings)
};

struct EbookReader {
    int book_count; // Number of books in the reader
    struct Book books[MAX_BOOKS]; // Array of books in the reader
};

int main() {
    struct EbookReader reader = {0}; // Initialize the reader with 0 books

    // Add some books to the reader
    struct Book book1 = {"The Catcher in the Rye", "J.D. Salinger", 224, NULL};
    book1.content[0] = "If you really want to hear about it, the first thing you'll probably want to know is where I was born, and what my lousy childhood was like, and how my parents were occupied and all before they had me, and all that David Copperfield kind of crap, but I don't feel like going into it, if you want to know the truth.";
    book1.content[1] = "I'm not going to tell you my whole goddam autobiography or anything.";
    book1.content[2] = "I'll just tell you about this madman stuff that happened to me around last Christmas just before I got pretty run-down and had to come out here and take it easy.";
    reader.books[reader.book_count++] = book1;

    struct Book book2 = {"To Kill a Mockingbird", "Harper Lee", 281, NULL};
    book2.content[0] = "When he was nearly thirteen, my brother Jem got his arm badly broken at the elbow.";
    book2.content[1] = "When it healed, and Jem's fears of never being able to play football were assuaged, he was seldom self-conscious about his injury.";
    book2.content[2] = "His left arm was somewhat shorter than his right; when he stood or walked, the back of his hand was at right angles to his body, his thumb parallel to his thigh.";
    reader.books[reader.book_count++] = book2;

    // Display the list of books in the reader
    printf("List of books in the reader:\n");
    for (int i = 0; i < reader.book_count; i++) {
        printf("%d. \"%s\" by %s (%d pages)\n", i+1, reader.books[i].title, reader.books[i].author, reader.books[i].page_count);
    }

    // Display the content of the first book
    struct Book* book = &reader.books[0];
    printf("\nContent of the book \"%s\":\n", book->title);
    for (int i = 0; i < book->page_count; i++) {
        printf("[Page %d]\n%s\n", i+1, book->content[i]);
    }

    return 0;
}