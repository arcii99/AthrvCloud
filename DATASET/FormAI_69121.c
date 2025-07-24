//FormAI DATASET v1.0 Category: Music Library Management System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_ARTIST_LENGTH 50
#define MAX_ALBUM_LENGTH 50
#define MAX_TRACKS 50

// Data Structure to store information about a single track
struct Track {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    char album[MAX_ALBUM_LENGTH];
    int rating;
};

// Data Structure to store information about a music album
struct Album {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    int release_year;
    struct Track tracks[MAX_TRACKS];
    int num_tracks;
};

// Data Structure to store information about the entire music library
struct MusicLibrary {
    struct Album albums[MAX_TRACKS];
    int num_albums;
};

// Function to add a new track to an album
void add_track_to_album(struct Album* album, char* title, char* artist, int rating) {
    if (album->num_tracks >= MAX_TRACKS) {
        printf("ERROR: Maximum number of tracks reached for album %s\n", album->title);
        return;
    }
    struct Track* track = &(album->tracks[album->num_tracks]);
    strncpy(track->title, title, MAX_TITLE_LENGTH);
    strncpy(track->artist, artist, MAX_ARTIST_LENGTH);
    strncpy(track->album, album->title, MAX_ALBUM_LENGTH);
    track->rating = rating;
    album->num_tracks++;
}

// Function to add a new album to the music library
void add_album_to_library(struct MusicLibrary* library, char* title, char* artist, int release_year) {
    if (library->num_albums >= MAX_TRACKS) {
        printf("ERROR: Maximum number of albums reached for library\n");
        return;
    }
    struct Album* album = &(library->albums[library->num_albums]);
    strncpy(album->title, title, MAX_TITLE_LENGTH);
    strncpy(album->artist, artist, MAX_ARTIST_LENGTH);
    album->release_year = release_year;
    album->num_tracks = 0;
    library->num_albums++;
}

// Function to display the list of albums in the library
void display_albums_in_library(struct MusicLibrary* library) {
    printf("Albums in Library:\n");
    for (int i = 0; i < library->num_albums; i++) {
        struct Album* album = &(library->albums[i]);
        printf("- %s by %s (%d)\n", album->title, album->artist, album->release_year);
    }
}

// Main Function
int main() {
    // Create a new Music Library
    struct MusicLibrary library;
    library.num_albums = 0;
    
    // Add some albums to the library
    add_album_to_library(&library, "Master of Puppets", "Metallica", 1986);
    add_album_to_library(&library, "Appetite for Destruction", "Guns N' Roses", 1987);
    add_album_to_library(&library, "Ten", "Pearl Jam", 1991);
    
    // Display the list of albums in the library
    display_albums_in_library(&library);
    
    // Add some tracks to an album
    struct Album* master_of_puppets = &(library.albums[0]);
    add_track_to_album(master_of_puppets, "Battery", "Metallica", 5);
    add_track_to_album(master_of_puppets, "Master of Puppets", "Metallica", 5);
    add_track_to_album(master_of_puppets, "The Thing That Should Not Be", "Metallica", 
    4);
    
    // Display the list of tracks in the album
    printf("Tracks in %s:\n", master_of_puppets->title);
    for (int i = 0; i < master_of_puppets->num_tracks; i++) {
        struct Track* track = &(master_of_puppets->tracks[i]);
        printf("- %s by %s (%d/5)\n", track->title, track->artist, track->rating);
    }
    
    return 0;
}