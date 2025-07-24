//FormAI DATASET v1.0 Category: Music Library Management System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_CHARS 100

struct Song {
    char title[MAX_CHARS];
    char artist[MAX_CHARS];
    char album[MAX_CHARS];
};

struct Library {
    int num_songs;
    struct Song songs[MAX_SONGS];
};

// function to add a new song to the library
void add_song(struct Library *lib, char *title, char *artist, char *album) {
    if (lib->num_songs >= MAX_SONGS) {
        printf("Error: could not add song - library is full.\n");
        return;
    }
    
    struct Song new_song;
    strcpy(new_song.title, title);
    strcpy(new_song.artist, artist);
    strcpy(new_song.album, album);
    
    lib->songs[lib->num_songs] = new_song;
    lib->num_songs++;
}

// function to display all songs in the library
void display_library(struct Library lib) {
    printf("Library:\n");
    for (int i = 0; i < lib.num_songs; i++) {
        printf("%s by %s (%s)\n", lib.songs[i].title, lib.songs[i].artist, lib.songs[i].album);
    }
}

int main() {
    struct Library my_library;
    my_library.num_songs = 0;
    
    // add some initial songs to the library
    add_song(&my_library, "Bohemian Rhapsody", "Queen", "A Night at the Opera");
    add_song(&my_library, "Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV");
    add_song(&my_library, "Hotel California", "Eagles", "Hotel California");
    
    // display the initial library
    display_library(my_library);
    
    // add a new song
    add_song(&my_library, "Purple Haze", "Jimi Hendrix", "Are You Experienced?");
    
    // display the updated library
    display_library(my_library);
    
    return 0;
}