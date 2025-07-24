//FormAI DATASET v1.0 Category: Music Library Management System ; Style: recursive
#include<stdio.h>
#include <string.h>

// Define the structure of each song
struct Song {
    char title[50];
    char artist[50];
    char album[50];
    int duration_seconds;
};

// Recursive function to search a specific song in the library
void search_song(struct Song songs[], int num_songs, char title[50], int current_index);

int main() {
    // Define the library as an array of songs
    struct Song library[100];

    // Add some sample songs to the library
    strcpy(library[0].title, "Bohemian Rhapsody");
    strcpy(library[0].artist, "Queen");
    strcpy(library[0].album, "A Night at the Opera");
    library[0].duration_seconds = 367;

    strcpy(library[1].title, "Stairway to Heaven");
    strcpy(library[1].artist, "Led Zeppelin");
    strcpy(library[1].album, "Led Zeppelin IV");
    library[1].duration_seconds = 482;

    strcpy(library[2].title, "Hotel California");
    strcpy(library[2].artist, "Eagles");
    strcpy(library[2].album, "Hotel California");
    library[2].duration_seconds = 391;

    // Call the search function on each song to find "Bohemian Rhapsody"
    search_song(library, 3, "Bohemian Rhapsody", 0);

    return 0;
}

void search_song(struct Song songs[], int num_songs, char title[50], int current_index) {
    // Base case: if all songs have been searched, print message and return
    if (current_index == num_songs) {
        printf("%s not found in library\n", title);
        return;
    }

    // Recursive case: if the current song matches the title, print message and return
    if (strcmp(songs[current_index].title, title) == 0) {
        printf("%s by %s found in library\n", title, songs[current_index].artist);
        return;
    }

    // Call the search function again with the next song in the library
    search_song(songs, num_songs, title, current_index + 1);
}