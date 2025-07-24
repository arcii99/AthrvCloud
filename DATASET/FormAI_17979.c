//FormAI DATASET v1.0 Category: Music Library Management System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100

struct song {
    char *title;
    char *artist;
    char *album;
    int release_year;
};

struct song music_library[MAX_SONGS];
int num_songs = 0;

// Function to add a song to the music library
void add_song(char *title, char *artist, char *album, int release_year) {
    struct song new_song;
    new_song.title = strdup(title);
    new_song.artist = strdup(artist);
    new_song.album = strdup(album);
    new_song.release_year = release_year;
    music_library[num_songs++] = new_song;
}

// Function to print out details of all the songs in the library
void print_library() {
    printf("---- Music Library ----\n");
    for (int i = 0; i < num_songs; i++) {
        printf("Title: %s\n", music_library[i].title);
        printf("Artist: %s\n", music_library[i].artist);
        printf("Album: %s\n", music_library[i].album);
        printf("Release Year: %d\n", music_library[i].release_year);
        printf("\n");
    }
}

int main() {
    add_song("Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975);
    add_song("Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971);
    add_song("Hotel California", "Eagles", "Hotel California", 1976);
    add_song("Imagine", "John Lennon", "Imagine", 1971);

    print_library();

    return 0;
}