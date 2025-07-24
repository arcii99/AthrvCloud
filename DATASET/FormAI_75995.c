//FormAI DATASET v1.0 Category: Music Library Management System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALBUMS 100
#define MAX_SONGS 500

typedef struct song {
    char title[50];
    char artist[50];
    int duration; //in seconds
} Song;

typedef struct album {
    char title[50];
    char artist[50];
    int year;
    Song songs[MAX_SONGS];
    int numOfSongs;
} Album;

typedef struct library {
    Album albums[MAX_ALBUMS];
    int numOfAlbums;
} Library;

void addAlbum(Library *lib, Album album) {
    if (lib->numOfAlbums < MAX_ALBUMS) {
        lib->albums[lib->numOfAlbums] = album;
        lib->numOfAlbums++;
    } else {
        printf("Library is out of space.\n");
    }
}

void addSongToAlbum(Album *album, Song song) {
    if (album->numOfSongs < MAX_SONGS) {
        album->songs[album->numOfSongs] = song;
        album->numOfSongs++;
    } else {
        printf("Album is out of space.\n");
    }
}

void printAlbum(Album album) {
    printf("%s (%d) - %s\n", album.title, album.year, album.artist);
    printf("--------------------------------\n");
    for (int i=0; i<album.numOfSongs; i++) {
        printf("%s - %s (%d:%02d)\n", album.songs[i].artist, album.songs[i].title, album.songs[i].duration/60, album.songs[i].duration%60);
    }
}

void printLibrary(Library lib) {
    for (int i=0; i<lib.numOfAlbums; i++) {
        printAlbum(lib.albums[i]);
        printf("\n");
    }
}

int main() {
    Library myLibrary = {0};
    
    Album album1 = {"The Dark Side of the Moon", "Pink Floyd", 1973, {0}, 0};
    Song song1 = {"Speak to Me", "Pink Floyd", 67};
    Song song2 = {"Breathe", "Pink Floyd", 163};
    addSongToAlbum(&album1, song1);
    addSongToAlbum(&album1, song2);
    
    Album album2 = {"Thriller", "Michael Jackson", 1982, {0}, 0};
    Song song3 = {"Wanna Be Startin' Somethin'", "Michael Jackson", 368};
    Song song4 = {"Beat It", "Michael Jackson", 258};
    addSongToAlbum(&album2, song3);
    addSongToAlbum(&album2, song4);
    
    addAlbum(&myLibrary, album1);
    addAlbum(&myLibrary, album2);
    
    printLibrary(myLibrary);
    
    return 0;
}