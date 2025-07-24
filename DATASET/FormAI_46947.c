//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100 // Maximum number of songs in library
#define MAX_TITLE_LENGTH 100 // Maximum length of song title

// Song struct
struct song {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_TITLE_LENGTH];
    int year;
};

// Music library struct
struct library {
    struct song songs[MAX_SONGS];
    int num_songs;
};

// Function to add a song to the library
void add_song(struct library *lib, char title[], char artist[], int year) {
    // Check if library is full
    if (lib->num_songs >= MAX_SONGS) {
        printf("Error: music library is full\n");
        return;
    }

    // Create new song
    struct song new_song;
    strcpy(new_song.title, title);
    strcpy(new_song.artist, artist);
    new_song.year = year;

    // Add song to library
    lib->songs[lib->num_songs] = new_song;
    lib->num_songs++;

    printf("Added '%s' by %s to the library\n", title, artist);
}

// Function to remove a song from the library
void remove_song(struct library *lib, char title[], char artist[]) {
    // Search for song
    int song_index = -1;
    for (int i = 0; i < lib->num_songs; i++) {
        if (strcmp(lib->songs[i].title, title) == 0 && strcmp(lib->songs[i].artist, artist) == 0) {
            song_index = i;
            break;
        }
    }

    // Check if song was found
    if (song_index == -1) {
        printf("Error: song not found in music library\n");
        return;
    }

    // Remove song from library
    for (int i = song_index; i < lib->num_songs - 1; i++) {
        lib->songs[i] = lib->songs[i+1];
    }
    lib->num_songs--;

    printf("Removed '%s' by %s from the library\n", title, artist);
}

// Function to print the list of songs in the library
void print_library(struct library *lib) {
    printf("Music library:\n");
    printf("-------------------------------------------------------\n");
    printf("| %-50s | %-20s | %-4s |\n", "Title", "Artist", "Year");
    printf("-------------------------------------------------------\n");
    for (int i = 0; i < lib->num_songs; i++) {
        printf("| %-50s | %-20s | %-4d |\n", lib->songs[i].title, lib->songs[i].artist, lib->songs[i].year);
    }
    printf("-------------------------------------------------------\n");
}

int main() {
    // Create new music library
    struct library my_library;
    my_library.num_songs = 0;

    // Add some songs to the library
    add_song(&my_library, "Bohemian Rhapsody", "Queen", 1975);
    add_song(&my_library, "Stairway to Heaven", "Led Zeppelin", 1971);
    add_song(&my_library, "Hotel California", "Eagles", 1976);

    // Print the library
    print_library(&my_library);

    // Remove a song from the library
    remove_song(&my_library, "Stairway to Heaven", "Led Zeppelin");

    // Print the library again
    print_library(&my_library);

    return 0;
}