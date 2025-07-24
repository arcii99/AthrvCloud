//FormAI DATASET v1.0 Category: Music Library Management System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of albums in the library
#define MAX_ALBUMS 50

// Define the maximum length of the album name
#define MAX_ALBUM_NAME_LENGTH 50

// Define the maximum number of tracks in an album
#define MAX_TRACKS 15

// Define the maximum length of the track name
#define MAX_TRACK_NAME_LENGTH 50

// Define the library structure
struct MusicLibrary {
    char albums[MAX_ALBUMS][MAX_ALBUM_NAME_LENGTH];
    int numAlbums;
};

// Define the album structure
struct Album {
    char name[MAX_ALBUM_NAME_LENGTH];
    char tracks[MAX_TRACKS][MAX_TRACK_NAME_LENGTH];
    int numTracks;
};

// Function prototypes
void addAlbum(struct MusicLibrary* library, struct Album album);
void removeAlbum(struct MusicLibrary* library, char albumName[]);
void displayLibrary(struct MusicLibrary* library);

int main() {
    struct MusicLibrary library;
    library.numAlbums = 0;

    // Example albums
    struct Album album1;
    strcpy(album1.name, "The Dark Side of the Moon");
    strcpy(album1.tracks[0], "Speak to Me");
    strcpy(album1.tracks[1], "Breathe");
    strcpy(album1.tracks[2], "On the Run");
    strcpy(album1.tracks[3], "Time");
    strcpy(album1.tracks[4], "The Great Gig in the Sky");
    album1.numTracks = 5;

    struct Album album2;
    strcpy(album2.name, "Led Zeppelin IV");
    strcpy(album2.tracks[0], "Black Dog");
    strcpy(album2.tracks[1], "Rock and Roll");
    strcpy(album2.tracks[2], "The Battle of Evermore");
    strcpy(album2.tracks[3], "Stairway to Heaven");
    album2.numTracks = 4;

    // Add the example albums to the library
    addAlbum(&library, album1);
    addAlbum(&library, album2);

    // Display the library
    displayLibrary(&library);

    // Remove an album from the library
    removeAlbum(&library, "Led Zeppelin IV");

    // Display the library again
    displayLibrary(&library);

    return 0;
}

void addAlbum(struct MusicLibrary* library, struct Album album) {
    // Check if the library is full
    if (library->numAlbums >= MAX_ALBUMS) {
        printf("Library is full!\n");
        return;
    }

    // Add the album to the library
    strcpy(library->albums[library->numAlbums], album.name);
    library->numAlbums++;

    printf("Album added: %s\n", album.name);
}

void removeAlbum(struct MusicLibrary* library, char albumName[]) {
    // Find the album in the library
    int index = -1;
    for (int i = 0; i < library->numAlbums; i++) {
        if (strcmp(library->albums[i], albumName) == 0) {
            index = i;
            break;
        }
    }

    // If the album is found, remove it from the library
    if (index != -1) {
        for (int i = index; i < library->numAlbums - 1; i++) {
            strcpy(library->albums[i], library->albums[i+1]);
        }
        library->numAlbums--;

        printf("Album removed: %s\n", albumName);
    } else {
        printf("Album %s not found!\n", albumName);
    }
}

void displayLibrary(struct MusicLibrary* library) {
    printf("\nLibrary:\n");
    for (int i = 0; i < library->numAlbums; i++) {
        printf("\nAlbum %d: %s\n", i+1, library->albums[i]);
    }
}