//FormAI DATASET v1.0 Category: Music Library Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LIBRARY_SIZE 50 

// Define a struct for each Music Album
typedef struct {
    char AlbumName[50];
    char ArtistName[50];
    int ReleaseYear;
    int NumberOfSongs;
} Album;

// Define a struct for Music Library
typedef struct {
    Album albumList[MAX_LIBRARY_SIZE];
    int numberOfAlbums;
} MusicLibrary;

// Function to add Album to Music Library
bool addAlbum(MusicLibrary* library, Album album) {
    if (library->numberOfAlbums < MAX_LIBRARY_SIZE) {
        library->albumList[library->numberOfAlbums] = album;
        library->numberOfAlbums++;
        return true;
    } else {
        return false;
    }
}

// Function to print all the Albums in Music Library
void printAlbums(MusicLibrary library) {
    for (int i = 0; i < library.numberOfAlbums; i++) {
        printf("Album Name : %s\n", library.albumList[i].AlbumName);
        printf("Artist Name : %s\n", library.albumList[i].ArtistName);
        printf("Release Year : %d\n", library.albumList[i].ReleaseYear);
        printf("Number of Songs : %d\n", library.albumList[i].NumberOfSongs);
        printf("\n");
    }
}

int main() {
    MusicLibrary library;
    library.numberOfAlbums = 0;
    Album album1;
    strcpy(album1.AlbumName, "Back in Black");
    strcpy(album1.ArtistName, "AC/DC");
    album1.ReleaseYear = 1980;
    album1.NumberOfSongs = 10;

    Album album2;
    strcpy(album2.AlbumName, "Thriller");
    strcpy(album2.ArtistName, "Michael Jackson");
    album2.ReleaseYear = 1982;
    album2.NumberOfSongs = 9;

    Album album3;
    strcpy(album3.AlbumName, "Dark Side of the Moon");
    strcpy(album3.ArtistName, "Pink Floyd");
    album3.ReleaseYear = 1973;
    album3.NumberOfSongs = 10;

    // Add Albums to Music Library
    addAlbum(&library, album1);
    addAlbum(&library, album2);
    addAlbum(&library, album3);

    // Print all Albums in Music Library
    printf("All Albums in Music Library\n");
    printf("---------------------------\n");
    printAlbums(library);
    
    return 0;
}