//FormAI DATASET v1.0 Category: Music Library Management System ; Style: decentralized
#include<stdio.h>
#include<string.h>
#define MAX_SIZE 100

typedef struct {
    char title[50];
    char artist[50];
    unsigned int release_year;
    char genre[20];
} Song;

typedef struct {
    char library_name[50];
    Song songs[MAX_SIZE];
    int num_songs;
} MusicLibrary;

void add_song(MusicLibrary *library, Song song) {
    if (library->num_songs == MAX_SIZE) {
        printf("Library is full. Cannot add any more songs.\n");
        return;
    }
    
    library->songs[library->num_songs++] = song;
    printf("Song added to library.\n");
}

void remove_song(MusicLibrary *library, char *title) {
    int i;
    for (i = 0; i < library->num_songs; i++) {
        if (strcmp(library->songs[i].title, title) == 0) {
            break;
        }
    }
    if (i == library->num_songs) {
        printf("Song not found in library.\n");
        return;
    }
    
    for (; i < library->num_songs-1; i++) {
        library->songs[i] = library->songs[i+1];
    }
    library->num_songs--;
    printf("Song removed from library.\n");
}

void search_by_title(MusicLibrary library, char *title) {
    int i, found = 0;
    for (i = 0; i < library.num_songs; i++) {
        if (strcmp(library.songs[i].title, title) == 0) {
            printf("Title: %s\n", library.songs[i].title);
            printf("Artist: %s\n", library.songs[i].artist);
            printf("Release Year: %u\n", library.songs[i].release_year);
            printf("Genre: %s\n", library.songs[i].genre);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Song not found in library.\n");
    }
}

int main() {
    MusicLibrary my_library;
    strcpy(my_library.library_name, "My Library");
    my_library.num_songs = 0;
    
    Song song1;
    strcpy(song1.title, "Bohemian Rhapsody");
    strcpy(song1.artist, "Queen");
    song1.release_year = 1975;
    strcpy(song1.genre, "Rock");
    add_song(&my_library, song1);
    
    Song song2;
    strcpy(song2.title, "Uptown Funk");
    strcpy(song2.artist, "Mark Ronson ft. Bruno Mars");
    song2.release_year = 2014;
    strcpy(song2.genre, "Pop");
    add_song(&my_library, song2);
    
    remove_song(&my_library, "Bohemian Rhapsody");
    
    search_by_title(my_library, "Uptown Funk");
    
    return 0;
}