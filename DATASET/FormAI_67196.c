//FormAI DATASET v1.0 Category: Music Library Management System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALBUMS 1000
#define MAX_SONGS_PER_ALBUM 50
#define MAX_SONG_TITLE_LENGTH 50
#define MAX_ARTIST_NAME_LENGTH 50

typedef struct{
    char title[MAX_SONG_TITLE_LENGTH];
    int durationSeconds;
}Song;

typedef struct{
    char name[MAX_ARTIST_NAME_LENGTH];
    Song songs[MAX_SONGS_PER_ALBUM];
    int numSongs;
}Album;

typedef struct{
    Album albums[MAX_ALBUMS];
    int numAlbums;
}MusicLibrary;

void addAlbum(MusicLibrary *library, char *artistName, char *albumName, Song *songs, int numSongs){
    // Check if album already exists
    for(int i = 0; i < library->numAlbums; i++){
        if(strcmp(artistName, library->albums[i].name) == 0 && strcmp(albumName, library->albums[i].songs[0].title) == 0){
            printf("Album already exists in the library.\n");
            return;
        }
    }

    // Create new album
    Album newAlbum;
    strcpy(newAlbum.name, artistName);
    memcpy(newAlbum.songs, songs, sizeof(Song) * numSongs);
    newAlbum.numSongs = numSongs;

    // Add new album to library
    if(library->numAlbums >= MAX_ALBUMS){
        printf("Error: Music library is full!\n");
    }else{
        library->albums[library->numAlbums] = newAlbum;
        library->numAlbums++;
    }
}

void printAlbum(Album album){
    printf("Album: %s\nArtist: %s\n", album.songs[0].title, album.name);
    for(int i = 0; i < album.numSongs; i++){
        printf("Song %d:\nTitle: %s\nDuration: %d seconds\n", i+1, album.songs[i].title, album.songs[i].durationSeconds);
    }
}

void printLibrary(MusicLibrary library){
    printf("Music Library:\nTotal Albums: %d\n", library.numAlbums);
    for(int i = 0; i < library.numAlbums; i++){
        printAlbum(library.albums[i]);
    }
}

int main(){
    MusicLibrary library = {0};

    // Add some example albums
    Song album1Songs[] = {{"Song 1", 180}, {"Song 2", 220}};
    addAlbum(&library, "Artist 1", "Album 1", album1Songs, 2);

    Song album2Songs[] = {{"Song 1", 200}, {"Song 2", 240}, {"Song 3", 300}};
    addAlbum(&library, "Artist 2", "Album 2", album2Songs, 3);

    // Print library
    printLibrary(library);

    return 0;
}