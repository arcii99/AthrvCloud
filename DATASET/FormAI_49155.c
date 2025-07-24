//FormAI DATASET v1.0 Category: Music Library Management System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* A happy example of a music library management system */

// Define the maximum number of songs that can be stored in the library
#define MAX_SONGS 100

// Define the maximum length of each song's title and artist name
#define MAX_TITLE 50
#define MAX_ARTIST 20

// Define the song struct
typedef struct {
    char title[MAX_TITLE];
    char artist[MAX_ARTIST];
    int year;
} Song;

// Define the music library struct
typedef struct {
    Song songs[MAX_SONGS];
    int num_songs;
} MusicLibrary;

// Function to print the current contents of the library
void printLibrary(MusicLibrary library) {
    printf("Current Music Library:\n");
    for (int i = 0; i < library.num_songs; i++) {
        printf("%d. \"%s\" by %s (%d)\n", i+1, library.songs[i].title, library.songs[i].artist, library.songs[i].year);
    }
}

// Function to add a new song to the library
void addSong(MusicLibrary *library, char *title, char *artist, int year) {
    // Check if the library is already full
    if (library->num_songs == MAX_SONGS) {
        printf("Sorry, the library is already full!\n");
        return;
    }
    // Create a new Song struct and add it to the library
    Song newSong;
    strcpy(newSong.title, title);
    strcpy(newSong.artist, artist);
    newSong.year = year;
    library->songs[library->num_songs] = newSong;
    library->num_songs++;
    printf("Woo-hoo! \"%s\" by %s (%d) has been added to the library!\n", title, artist, year);
}

int main() {
    // Create a new MusicLibrary struct
    MusicLibrary myLibrary;
    myLibrary.num_songs = 0; // Set the number of songs to 0 to start

    // Add some initial songs to the library
    addSong(&myLibrary, "Happy", "Pharrell Williams", 2013);
    addSong(&myLibrary, "Shut Up and Dance", "Walk the Moon", 2014);
    addSong(&myLibrary, "Can't Stop the Feeling!", "Justin Timberlake", 2016);

    // Print the current contents of the library
    printLibrary(myLibrary);

    // Add a new song to the library
    addSong(&myLibrary, "Dancing in the Moonlight", "Toploader", 1999);

    // Print the current contents of the library again
    printLibrary(myLibrary);

    return 0;
}