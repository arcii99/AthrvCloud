//FormAI DATASET v1.0 Category: Music Library Management System ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_STR_LEN 100
#define MAX_LIB_ENTRIES 100

struct music_entry {
    char title[MAX_STR_LEN];
    char artist[MAX_STR_LEN];
    char album[MAX_STR_LEN];
    char genre[MAX_STR_LEN];
    int trackNum;
};

struct music_library {
    struct music_entry entries[MAX_LIB_ENTRIES];
    int count;
};

void initLibrary(struct music_library* library) {
    library->count = 0;
}

void addEntry(struct music_library* library, struct music_entry newEntry) {
    if (library->count >= MAX_LIB_ENTRIES) {
        printf("Error: Library full.\n");
        return;
    }
    library->entries[library->count++] = newEntry;
}

void printEntry(struct music_entry entry) {
    printf("Title: %s\n", entry.title);
    printf("Artist: %s\n", entry.artist);
    printf("Album: %s\n", entry.album);
    printf("Genre: %s\n", entry.genre);
    printf("Track Number: %d\n", entry.trackNum);
}

void printLibrary(struct music_library* library) {
    int i;
    for (i = 0; i < library->count; i++) {
        printEntry(library->entries[i]);
        printf("\n");
    }
}

int main() {
    struct music_library library;

    initLibrary(&library);

    struct music_entry helloWorld = {"Hello World", "Me", "My Album", "Rock", 1};
    struct music_entry goodbyeWorld = {"Goodbye World", "Me", "My Album", "Rock", 2};
    struct music_entry heyThere = {"Hey There", "Me", "My Album", "Pop", 3};

    addEntry(&library, helloWorld);
    addEntry(&library, goodbyeWorld);
    addEntry(&library, heyThere);

    printLibrary(&library);

    return 0;
}