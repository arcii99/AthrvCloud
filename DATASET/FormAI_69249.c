//FormAI DATASET v1.0 Category: Ebook reader ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[50];
    char author[50];
    int page_count;
    char* content;
} Ebook;

void read_ebook(Ebook* book) {
    printf("\nReading %s by %s\n", book->title, book->author);
    printf("Total pages: %d\n\n", book->page_count);
    printf("%s", book->content);
}

int main() {
    Ebook book1;
    strcpy(book1.title, "The Adventures of Sherlock Holmes");
    strcpy(book1.author, "Arthur Conan Doyle");
    book1.page_count = 527;
    book1.content = "It was in the year ’95 that a combination of events, into which I need not enter, caused Mr. Sherlock Holmes \n" \
                     "and myself to spend some weeks in one of our great university towns, and it was during this time that the small \n" \
                     "incident occurred which forms the starting-point of the strange problem which I have now to record.";

    Ebook book2;
    strcpy(book2.title, "War and Peace");
    strcpy(book2.author, "Leo Tolstoy");
    book2.page_count = 1225;
    book2.content = "’Well, Prince, so Genoa and Lucca are now just family estates of the Buonapartes.’ \n" \
                     "’But I warn you, if you don’t tell me that this means war, if you still try to defend the infamies \n" \
                     "and horrors perpetrated by that Antichrist—I really believe he is Antichrist—I will have nothing \n" \
                     "more to do with you and you are no longer my friend, no longer my ‘faithful slave,’ as you call yourself! \n" \
                     "But how do you do? I see I frighten you—sit down and tell me all the news.’";

    read_ebook(&book1);
    read_ebook(&book2);

    return 0;
}