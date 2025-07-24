//FormAI DATASET v1.0 Category: Music Library Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONG_LENGTH 50
#define MAX_ARTIST_LENGTH 50
#define MAX_LIBRARY_SIZE 100

// Song structure
typedef struct {
    char title[MAX_SONG_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    int year;
} Song;

// Library structure
typedef struct {
    Song songs[MAX_LIBRARY_SIZE];
    int num_songs;
} Library;

// Add a song to the library
void add_song(Library *lib, char *title, char *artist, int year) {
    Song new_song;
    strncpy(new_song.title, title, MAX_SONG_LENGTH);
    strncpy(new_song.artist, artist, MAX_ARTIST_LENGTH);
    new_song.year = year;
    if (lib->num_songs < MAX_LIBRARY_SIZE) {
        lib->songs[lib->num_songs++] = new_song;
    }
    else {
        printf("Library is full!\n");
    }
}

// Print the library
void print_library(Library *lib) {
    printf("Library:\n");
    printf("Title\t\tArtist\t\tYear\n");
    for (int i = 0; i < lib->num_songs; i++) {
        printf("%-16s%-16s%d\n", lib->songs[i].title, lib->songs[i].artist, lib->songs[i].year);
    }
}

// Search for songs by title
void search_title(Library *lib, char *title) {
    printf("Search results for \"%s\":\n", title);
    printf("Title\t\tArtist\t\tYear\n");
    for (int i = 0; i < lib->num_songs; i++) {
        if (strncmp(lib->songs[i].title, title, strlen(title)) == 0) {
            printf("%-16s%-16s%d\n", lib->songs[i].title, lib->songs[i].artist, lib->songs[i].year);
        }
    }
}

// Search for songs by artist
void search_artist(Library *lib, char *artist) {
    printf("Search results for \"%s\":\n", artist);
    printf("Title\t\tArtist\t\tYear\n");
    for (int i = 0; i < lib->num_songs; i++) {
        if (strncmp(lib->songs[i].artist, artist, strlen(artist)) == 0) {
            printf("%-16s%-16s%d\n", lib->songs[i].title, lib->songs[i].artist, lib->songs[i].year);
        }
    }
}

// Main function
int main() {
    Library lib;
    lib.num_songs = 0;

    // Add some songs to the library
    add_song(&lib, "Song 1", "Artist 1", 2000);
    add_song(&lib, "Song 2", "Artist 2", 2001);
    add_song(&lib, "Song 3", "Artist 1", 2002);
    add_song(&lib, "Song 4", "Artist 2", 2003);

    // Print the library
    print_library(&lib);

    // Search for songs by title
    search_title(&lib, "Song 2");

    // Search for songs by artist
    search_artist(&lib, "Artist 1");

    // Add a song that exceeds the library size
    for (int i = 0; i < 200; i++) {
        char title[MAX_SONG_LENGTH];
        sprintf(title, "Song %d", i+5);
        add_song(&lib, title, "Artist 3", 2000+i);
    }

    // Print the library again
    print_library(&lib);

    return 0;
}