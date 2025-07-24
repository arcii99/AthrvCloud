//FormAI DATASET v1.0 Category: Music Library Management System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char title[MAX_NAME_LENGTH];
    char artist[MAX_NAME_LENGTH];
    int year;
} Song;

typedef struct {
    Song songs[MAX_SONGS];
    int num_songs;
} MusicLibrary;

void add_song(MusicLibrary* library, Song track) {
    if (library->num_songs < MAX_SONGS) {
        library->songs[library->num_songs++] = track;
        printf("Added %s by %s to the library!\n", track.title, track.artist);
    } else {
        printf("Music library is full!\n");
    }
}

void print_songs(MusicLibrary* library) {
    printf("Title\tArtist\tYear\n");
    for (int i = 0; i < library->num_songs; i++) {
        printf("%s\t%s\t%d\n", library->songs[i].title, library->songs[i].artist, library->songs[i].year);
    }
}

void search_songs(MusicLibrary* library, char* keyword) {
    printf("Search results for keyword '%s':\n", keyword);
    for (int i = 0; i < library->num_songs; i++) {
        if (strstr(library->songs[i].title, keyword) || strstr(library->songs[i].artist, keyword)) {
            printf("%s by %s (%d)\n", library->songs[i].title, library->songs[i].artist, library->songs[i].year);
        }
    }
}

int main() {
    MusicLibrary library = {0};
    Song s1 = {"Sweet Child O' Mine", "Guns N' Roses", 1987};
    Song s2 = {"Smells Like Teen Spirit", "Nirvana", 1991};
    Song s3 = {"Bohemian Rhapsody", "Queen", 1975};
    Song s4 = {"Stairway to Heaven", "Led Zeppelin", 1971};
    Song s5 = {"Hotel California", "Eagles", 1977};

    add_song(&library, s1);
    add_song(&library, s2);
    add_song(&library, s3);
    add_song(&library, s4);
    add_song(&library, s5);

    printf("\n--- Music Library ---\n");
    print_songs(&library);

    printf("\n--- Search Results ---\n");
    search_songs(&library, "Stairway");

    return 0;
}