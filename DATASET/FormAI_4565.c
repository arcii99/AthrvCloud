//FormAI DATASET v1.0 Category: Music Library Management System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    int duration;
};

struct MusicLibrary {
    int num_songs;
    struct Song *songs;
};

void add_song(struct MusicLibrary *library, struct Song song) {
    library->num_songs++;
    library->songs = realloc(library->songs, 
                            library->num_songs * sizeof(struct Song));
    library->songs[library->num_songs - 1] = song;
}

void remove_song(struct MusicLibrary *library, int song_index) {
    if (song_index < 0 || song_index >= library->num_songs) {
        printf("Error: Invalid song index.\n");
        return;
    }

    for (int i = song_index; i < library->num_songs - 1; i++) {
        library->songs[i] = library->songs[i + 1];
    }
    library->num_songs--;
    library->songs = realloc(library->songs, 
                            library->num_songs * sizeof(struct Song));
}

void display_songs(struct MusicLibrary library) {
    printf("Song\t\tArtist\t\tAlbum\t\tYear\tDuration\n");
    for (int i = 0; i < library.num_songs; i++) {
        printf("%s\t\t%s\t\t%s\t\t%d\t%d\n", 
               library.songs[i].title, 
               library.songs[i].artist, 
               library.songs[i].album, 
               library.songs[i].year, 
               library.songs[i].duration);
    }
}

int main() {
    struct MusicLibrary library;
    library.num_songs = 0;
    library.songs = NULL;

    struct Song song1, song2, song3;
    strncpy(song1.title, "Shape of You", 50);
    strncpy(song1.artist, "Ed Sheeran", 50);
    strncpy(song1.album, "÷", 50);
    song1.year = 2017;
    song1.duration = 233;

    strncpy(song2.title, "Stressed Out", 50);
    strncpy(song2.artist, "Twenty One Pilots", 50);
    strncpy(song2.album, "Blurryface", 50);
    song2.year = 2015;
    song2.duration = 202;

    strncpy(song3.title, "Shallow", 50);
    strncpy(song3.artist, "Lady Gaga, Bradley Cooper", 50);
    strncpy(song3.album, "A Star Is Born Soundtrack", 50);
    song3.year = 2018;
    song3.duration = 216;

    add_song(&library, song1);
    add_song(&library, song2);
    add_song(&library, song3);

    display_songs(library);
    printf("\n");

    remove_song(&library, 1);

    display_songs(library);

    return 0;
}