//FormAI DATASET v1.0 Category: Music Library Management System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for storing the information for a song
typedef struct Song {
    char* title;
    char* artist;
    int duration; // in seconds
} Song;

// Structure for storing the information for an album
typedef struct Album {
    char* title;
    char* artist;
    int year;
    Song** songs; // Pointer to array of Song pointers
    int num_songs; // Number of songs in the album
} Album;

// Structure for storing the information for a playlist
typedef struct Playlist {
    char* name;
    Song** songs; // Pointer to array of Song pointers
    int num_songs; // Number of songs in the playlist
} Playlist;

void print_song(Song* song) {
    printf("%s - %s (%d seconds)\n", song->artist, song->title, song->duration);
}

void print_album(Album* album) {
    printf("%s - %s (%d)\n", album->artist, album->title, album->year);
    for (int i = 0; i < album->num_songs; i++) {
        printf("%d. ", i+1);
        print_song(album->songs[i]);
    }
}

void print_playlist(Playlist* playlist) {
    printf("Playlist: %s\n", playlist->name);
    for (int i = 0; i < playlist->num_songs; i++) {
        printf("%d. ", i+1);
        print_song(playlist->songs[i]);
    }
}

int main() {
    // Create some example songs
    Song* song1 = (Song*) malloc(sizeof(Song));
    song1->title = "Bohemian Rhapsody";
    song1->artist = "Queen";
    song1->duration = 367;

    Song* song2 = (Song*) malloc(sizeof(Song));
    song2->title = "Stairway to Heaven";
    song2->artist = "Led Zeppelin";
    song2->duration = 482;

    Song* song3 = (Song*) malloc(sizeof(Song));
    song3->title = "Back in Black";
    song3->artist = "AC/DC";
    song3->duration = 255;

    // Create an album and add the songs to it
    Album* album1 = (Album*) malloc(sizeof(Album));
    album1->title = "A Night at the Opera";
    album1->artist = "Queen";
    album1->year = 1975;
    album1->num_songs = 1;
    album1->songs = (Song**) malloc(sizeof(Song*) * album1->num_songs);
    album1->songs[0] = song1;

    Album* album2 = (Album*) malloc(sizeof(Album));
    album2->title = "Led Zeppelin IV";
    album2->artist = "Led Zeppelin";
    album2->year = 1971;
    album2->num_songs = 1;
    album2->songs = (Song**) malloc(sizeof(Song*) * album2->num_songs);
    album2->songs[0] = song2;

    // Create a playlist and add the songs to it
    Playlist* playlist1 = (Playlist*) malloc(sizeof(Playlist));
    playlist1->name = "Rock Classics";
    playlist1->num_songs = 2;
    playlist1->songs = (Song**) malloc(sizeof(Song*) * playlist1->num_songs);
    playlist1->songs[0] = song2;
    playlist1->songs[1] = song3;

    // Print out the album and playlist
    print_album(album1);
    print_album(album2);
    print_playlist(playlist1);

    // Free the memory allocated for the songs, albums, and playlist
    free(song1);
    free(song2);
    free(song3);
    free(album1->songs);
    free(album1);
    free(album2->songs);
    free(album2);
    free(playlist1->songs);
    free(playlist1);

    return 0;
}