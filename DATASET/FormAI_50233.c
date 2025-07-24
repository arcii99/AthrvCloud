//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SONGS 100
 
struct song {
    char title[1024];
    char artist[1024];
    char genre[1024];
    int year;
};
 
struct library {
    struct song songs[MAX_SONGS];
    int count;
};
 
void add_song(struct library *lib, struct song s) {
    if (lib->count >= MAX_SONGS) {
        printf("Library is full!\n");
        return;
    }
    lib->songs[lib->count] = s;
    lib->count++;
}
 
void print_song(struct song s) {
    printf("%s - %s (%s, %d)\n", s.title, s.artist, s.genre, s.year);
}
 
void print_library(struct library lib) {
    int i;
    for (i = 0; i < lib.count; i++) {
        print_song(lib.songs[i]);
    }
}
 
int main(void) {
    struct library lib = {0};
    struct song s;
 
    // add some songs
    strcpy(s.title, "Bohemian Rhapsody");
    strcpy(s.artist, "Queen");
    strcpy(s.genre, "Rock");
    s.year = 1975;
    add_song(&lib, s);
 
    strcpy(s.title, "Stairway to Heaven");
    strcpy(s.artist, "Led Zeppelin");
    strcpy(s.genre, "Rock");
    s.year = 1971;
    add_song(&lib, s);
 
    strcpy(s.title, "Imagine");
    strcpy(s.artist, "John Lennon");
    strcpy(s.genre, "Rock");
    s.year = 1971;
    add_song(&lib, s);
 
    // print library
    printf("Library:\n");
    print_library(lib);
 
    return 0;
}