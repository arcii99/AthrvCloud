//FormAI DATASET v1.0 Category: Browser Plugin ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *name;
    char *url;
} Bookmark;

typedef struct {
    Bookmark *bookmarks;
    int count;
    int size;
} BookmarkList;

void addBookmark(BookmarkList *list, Bookmark bookmark) {
    if (list->count == list->size) {
        list->size += 10;
        list->bookmarks = (Bookmark *)realloc(list->bookmarks, sizeof(Bookmark) * list->size);
    }
    list->bookmarks[list->count] = bookmark;
    list->count++;
}

void printBookmarks(BookmarkList list) {
    for (int i = 0; i < list.count; i++) {
        printf("%s: %s\n", list.bookmarks[i].name, list.bookmarks[i].url);
    }
}

int main() {
    BookmarkList list = {NULL, 0, 0};
    addBookmark(&list, (Bookmark){"Google", "https://google.com"});
    addBookmark(&list, (Bookmark){"Facebook", "https://facebook.com"});
    addBookmark(&list, (Bookmark){"Amazon", "https://amazon.com"});
    addBookmark(&list, (Bookmark){"Twitter", "https://twitter.com"});
    printBookmarks(list);
    return 0;
}