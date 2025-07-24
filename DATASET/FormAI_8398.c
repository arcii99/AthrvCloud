//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_ARTISTS 50

// Song data structure
struct Song {
    char title[50];
    char artist[30];
    int year;
};

// Artist data structure
struct Artist {
    char name[30];
    int num_songs;
};

// Library data structure
struct Library {
    struct Song songs[MAX_SONGS];
    struct Artist artists[MAX_ARTISTS];
    int num_songs;
    int num_artists;
};

// Function to add a song to the library
void add_song(struct Library *library, char *title, char *artist, int year) {
    // Check if the song already exists
    for (int i = 0; i < library->num_songs; i++) {
        if (strcmp(library->songs[i].title, title) == 0 && strcmp(library->songs[i].artist, artist) == 0) {
            printf("Error: Song already exists in the library.\n");
            return;
        }
    }
    // Add the song to the library
    strcpy(library->songs[library->num_songs].title, title);
    strcpy(library->songs[library->num_songs].artist, artist);
    library->songs[library->num_songs].year = year;
    library->num_songs++;
    // Update the artist's list of songs
    int artist_found = 0;
    for (int i = 0; i < library->num_artists; i++) {
        if (strcmp(library->artists[i].name, artist) == 0) {
            library->artists[i].num_songs++;
            artist_found = 1;
            break;
        }
    }
    if (!artist_found) {
        strcpy(library->artists[library->num_artists].name, artist);
        library->artists[library->num_artists].num_songs = 1;
        library->num_artists++;
    }
}

// Function to delete a song from the library
void delete_song(struct Library *library, char *title, char *artist) {
    int song_found = 0, artist_index = -1, song_index = -1;
    // Find the song and artist index in the library
    for (int i = 0; i < library->num_songs; i++) {
        if (strcmp(library->songs[i].title, title) == 0 && strcmp(library->songs[i].artist, artist) == 0) {
            song_found = 1;
            song_index = i;
            break;
        }
    }
    if (!song_found) {
        printf("Error: Song not found in the library.\n");
        return;
    }
    for (int i = 0; i < library->num_artists; i++) {
        if (strcmp(library->artists[i].name, artist) == 0) {
            artist_index = i;
            break;
        }
    }
    // Remove the song from the library
    for (int i = song_index; i < library->num_songs - 1; i++) {
        library->songs[i] = library->songs[i+1];
    }
    library->num_songs--;
    // Update the artist's list of songs
    library->artists[artist_index].num_songs--;
    if (library->artists[artist_index].num_songs == 0) {
        for (int i = artist_index; i < library->num_artists - 1; i++) {
            library->artists[i] = library->artists[i+1];
        }
        library->num_artists--;
    }
}

// Function to print all the songs in the library
void print_songs(struct Library *library) {
    printf("Library\n=======\n");
    for (int i = 0; i < library->num_songs; i++) {
        printf("%s - %s (%d)\n", library->songs[i].artist, library->songs[i].title, library->songs[i].year);
    }
}

// Function to print all the artists in the library
void print_artists(struct Library *library) {
    printf("Artists\n=======\n");
    for (int i = 0; i < library->num_artists; i++) {
        printf("%s (%d)\n", library->artists[i].name, library->artists[i].num_songs);
    }
}

int main() {
    struct Library library;
    library.num_songs = 0;
    library.num_artists = 0;
    // Add some initial songs to the library
    add_song(&library, "Bohemian Rhapsody", "Queen", 1975);
    add_song(&library, "Hotel California", "Eagles", 1976);
    add_song(&library, "Imagine", "John Lennon", 1971);
    // Delete a song from the library
    delete_song(&library, "Bohemian Rhapsody", "Queen");
    // Print the songs and artists in the library
    print_songs(&library);
    print_artists(&library);
    return 0;
}