//FormAI DATASET v1.0 Category: Music Library Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the song title
#define MAX_TITLE_LENGTH 50

// Define the maximum number of songs in the library
#define MAX_LIBRARY_SIZE 1000

// Define the struct for song
typedef struct {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_TITLE_LENGTH];
    int year;
} Song;

// Define the struct for music library
typedef struct {
    Song songs[MAX_LIBRARY_SIZE];
    int size;
} MusicLibrary;

// Function to add a song to the music library
void addSong(MusicLibrary* library, char* title, char* artist, int year) {
    Song song;
    strcpy(song.title, title);
    strcpy(song.artist, artist);
    song.year = year;
    library->songs[library->size++] = song;
}

// Function to print all the songs in the music library
void printSongs(MusicLibrary* library) {
    printf("Title\t\tArtist\t\tYear\n");
    for (int i = 0; i < library->size; i++) {
        printf("%s\t\t%s\t\t%d\n", library->songs[i].title, library->songs[i].artist, library->songs[i].year);
    }
}

// Function to initialize the music library
void initializeLibrary(MusicLibrary* library) {
    library->size = 0;
}

int main() {
    MusicLibrary library;
    initializeLibrary(&library);

    addSong(&library, "Shape of You", "Ed Sheeran", 2017);
    addSong(&library, "Hello", "Adele", 2015);
    addSong(&library, "Despacito", "Luis Fonsi", 2017);
    addSong(&library, "Uptown Funk", "Mark Ronson ft. Bruno Mars", 2014);
    
    printSongs(&library);
    
    return 0;
}