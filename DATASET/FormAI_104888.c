//FormAI DATASET v1.0 Category: Music Library Management System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100

struct Song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    float duration;
};

struct Library {
    struct Song songs[MAX_SONGS];
    int num_songs;
};

void add_song(struct Library *lib, struct Song new_song) {
    if (lib->num_songs == MAX_SONGS) {
        printf("Library is full. Cannot add song.\n");
        return;
    }

    lib->songs[lib->num_songs] = new_song;
    lib->num_songs++;
}

void remove_song(struct Library *lib, int index) {
    if (index < 0 || index >= lib->num_songs) {
        printf("Invalid index. Cannot remove song.\n");
        return;
    }

    for (int i = index; i < lib->num_songs - 1; i++) {
        lib->songs[i] = lib->songs[i+1];
    }

    lib->num_songs--;
}

void print_song(struct Song song) {
    printf("Title: %s\nArtist: %s\nAlbum: %s\nYear: %d\nDuration: %.2f\n", 
           song.title, song.artist, song.album, song.year, song.duration);
}

void print_library(struct Library lib) {
    for (int i = 0; i < lib.num_songs; i++) {
        printf("Song %d:\n", i+1);
        print_song(lib.songs[i]);
        printf("\n");
    }
}

int main() {
    struct Library my_library;
    my_library.num_songs = 0;

    struct Song song1 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 6.07};
    struct Song song2 = {"Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 8.03};
    struct Song song3 = {"Hey Jude", "The Beatles", "The Beatles Again", 1968, 7.11};

    add_song(&my_library, song1);
    add_song(&my_library, song2);
    add_song(&my_library, song3);

    printf("Current library:\n");
    print_library(my_library);

    remove_song(&my_library, 1);

    printf("\nUpdated library:\n");
    print_library(my_library);

    return 0;
}