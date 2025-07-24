//FormAI DATASET v1.0 Category: Music Library Management System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALBUMS 100
#define MAX_NAME_LENGTH 50
#define MAX_SONGS 20

typedef struct Song {
    char title[MAX_NAME_LENGTH];
    char artist[MAX_NAME_LENGTH];
    int length; //in seconds
} Song;

typedef struct Album {
    char title[MAX_NAME_LENGTH];
    char artist[MAX_NAME_LENGTH];
    Song songs[MAX_SONGS];
    int num_songs;
} Album;

typedef struct MusicLibrary {
    Album albums[MAX_ALBUMS];
    int num_albums;
} MusicLibrary;

void add_album(MusicLibrary* library, char* album_title, char* artist_name) {
    if (library->num_albums >= MAX_ALBUMS) {
        printf("Error: Maximum number of albums reached.\n");
        return;
    }
    Album new_album;
    strcpy(new_album.title, album_title);
    strcpy(new_album.artist, artist_name);
    new_album.num_songs = 0;
    library->albums[library->num_albums++] = new_album;
    printf("Album added successfully.\n");
}

void add_song(MusicLibrary* library, char* album_title, Song song) {
    for (int i = 0; i < library->num_albums; i++) {
        if (strcmp(library->albums[i].title, album_title) == 0) {
            if (library->albums[i].num_songs >= MAX_SONGS) {
                printf("Error: Maximum number of songs for album reached.\n");
                return;
            }
            library->albums[i].songs[library->albums[i].num_songs++] = song;
            printf("Song added to album.\n");
            return;
        }
    }
    printf("Error: Album does not exist.\n");
}

void print_albums(MusicLibrary library) {
    printf("Albums:\n");
    for (int i = 0; i < library.num_albums; i++) {
        printf("%s - %s\n", library.albums[i].title, library.albums[i].artist);
    }
}

void print_songs(MusicLibrary library, char* album_title) {
    for (int i = 0; i < library.num_albums; i++) {
        if (strcmp(library.albums[i].title, album_title) == 0) {
            printf("Songs in %s:\n", album_title);
            for (int j = 0; j < library.albums[i].num_songs; j++) {
                Song song = library.albums[i].songs[j];
                printf("%s - %s (%d seconds)\n", song.artist, song.title, song.length);
            }
            return;
        }
    }
    printf("Error: Album does not exist.\n");
}

int main() {
    MusicLibrary my_library;
    my_library.num_albums = 0;

    add_album(&my_library, "Hot Fuss", "The Killers");
    add_album(&my_library, "Demon Days", "Gorillaz");

    Song song1 = {"Mr. Brightside", "The Killers", 222};
    Song song2 = {"Somebody Told Me", "The Killers", 202};
    add_song(&my_library, "Hot Fuss", song1);
    add_song(&my_library, "Hot Fuss", song2);

    Song song3 = {"Feel Good Inc.", "Gorillaz", 222};
    Song song4 = {"DARE", "Gorillaz", 202};
    add_song(&my_library, "Demon Days", song3);
    add_song(&my_library, "Demon Days", song4);

    print_albums(my_library);
    print_songs(my_library, "Hot Fuss");
    print_songs(my_library, "Nonexistent Album");

    return 0;
}