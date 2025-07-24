//FormAI DATASET v1.0 Category: Music Library Management System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALBUM_LEN 50
#define MAX_ARTIST_LEN 30
#define MAX_YEAR_LEN 4
#define MAX_SONGS 100

struct song {
    char title[MAX_ALBUM_LEN];
    char artist[MAX_ARTIST_LEN];
    char year[MAX_YEAR_LEN];
};

struct library {
    struct song songs[MAX_SONGS];
    int num_songs;
};

void add_song(struct library *lib, char *title, char *artist, char *year) {
    if (lib->num_songs >= MAX_SONGS) {
        printf("Error: Too many songs in library.");
        return;
    }
    strncpy(lib->songs[lib->num_songs].title, title, MAX_ALBUM_LEN);
    strncpy(lib->songs[lib->num_songs].artist, artist, MAX_ARTIST_LEN);
    strncpy(lib->songs[lib->num_songs].year, year, MAX_YEAR_LEN);
    lib->num_songs++;
}

void print_library(struct library *lib) {
    int i;
    printf("\nSong Library:\n");
    for (i = 0; i < lib->num_songs; i++) {
        printf("Title: %s\n", lib->songs[i].title);
        printf("Artist: %s\n", lib->songs[i].artist);
        printf("Year: %s\n\n", lib->songs[i].year);
    }
}

int main() {
    struct library lib = {0};

    add_song(&lib, "The Chain", "Fleetwood Mac", "1977");
    add_song(&lib, "Bohemian Rhapsody", "Queen", "1975");
    add_song(&lib, "Stairway to Heaven", "Led Zeppelin", "1971");

    print_library(&lib);

    return 0;
}