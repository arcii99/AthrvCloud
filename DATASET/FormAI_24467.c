//FormAI DATASET v1.0 Category: Music Library Management System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARTISTS 100
#define MAX_ALBUMS 100
#define MAX_SONGS 500

typedef struct song {
    char name[50];
    float duration;
    int trackNumber;
} Song;

typedef struct album {
    char name[50];
    char artist[50];
    int numSongs;
    Song* songs[MAX_SONGS];
} Album;

typedef struct artist {
    char name[50];
    int numAlbums;
    Album* albums[MAX_ALBUMS];
} Artist;

typedef struct musicLibrary {
    int numArtists;
    Artist* artists[MAX_ARTISTS];
} MusicLibrary;

MusicLibrary* library;

void addArtist(char* name) {
    Artist* artist = malloc(sizeof(Artist));
    strcpy(artist->name, name);
    artist->numAlbums = 0;
    library->artists[library->numArtists] = artist;
    library->numArtists++;
    printf("Successfully added artist %s\n", artist->name);
}

void addAlbum(char* artistName, char* albumName) {
    int artistIndex = -1;
    for(int i=0; i<library->numArtists; i++) {
        if(strcmp(library->artists[i]->name, artistName) == 0) {
            artistIndex = i;
            break;
        }
    }
    if(artistIndex == -1) {
        printf("Error: artist %s not found\n", artistName);
        return;
    }
    Artist* artist = library->artists[artistIndex];
    Album* album = malloc(sizeof(Album));
    strcpy(album->name, albumName);
    strcpy(album->artist, artistName);
    album->numSongs = 0;
    artist->albums[artist->numAlbums] = album;
    artist->numAlbums++;
    printf("Successfully added album %s by artist %s\n", album->name, album->artist);
}

void addSong(char* artistName, char* albumName, char* songName, float duration, int trackNumber) {
    int artistIndex = -1, albumIndex = -1;
    for(int i=0; i<library->numArtists; i++) {
        if(strcmp(library->artists[i]->name, artistName) == 0) {
            artistIndex = i;
            break;
        }
    }
    if(artistIndex == -1) {
        printf("Error: artist %s not found\n", artistName);
        return;
    }
    Artist* artist = library->artists[artistIndex];
    for(int i=0; i<artist->numAlbums; i++) {
        if(strcmp(artist->albums[i]->name, albumName) == 0) {
            albumIndex = i;
            break;
        }
    }
    if(albumIndex == -1) {
        printf("Error: album %s not found\n", albumName);
        return;
    }
    Album* album = artist->albums[albumIndex];
    Song* song = malloc(sizeof(Song));
    strcpy(song->name, songName);
    song->duration = duration;
    song->trackNumber = trackNumber;
    album->songs[album->numSongs] = song;
    album->numSongs++;
    printf("Successfully added song %s to album %s by artist %s\n", song->name, album->name, album->artist);
}

void printLibrary() {
    printf("------------- MUSIC LIBRARY -------------\n");
    for(int i=0; i<library->numArtists; i++) {
        Artist* artist = library->artists[i];
        printf("Artist: %s\n", artist->name);
        for(int j=0; j<artist->numAlbums; j++) {
            Album* album = artist->albums[j];
            printf("    Album: %s\n", album->name);
            for(int k=0; k<album->numSongs; k++) {
                Song* song = album->songs[k];
                printf("        %d. %s (%.2f minutes)\n", song->trackNumber, song->name, song->duration);
            }
        }
    }
}

int main() {
    library = malloc(sizeof(MusicLibrary));
    library->numArtists = 0;

    addArtist("The Beatles");
    addAlbum("The Beatles", "Abbey Road");
    addSong("The Beatles", "Abbey Road", "Come Together", 4.20, 1);
    addSong("The Beatles", "Abbey Road", "Something", 3.03, 2);
    addSong("The Beatles", "Abbey Road", "Maxwell's Silver Hammer", 3.28, 3);
    addSong("The Beatles", "Abbey Road", "Oh! Darling", 3.27, 4);
    addSong("The Beatles", "Abbey Road", "Octopus's Garden", 2.51, 5);
    addSong("The Beatles", "Abbey Road", "I Want You (She's So Heavy)", 7.47, 6);
    addSong("The Beatles", "Abbey Road", "Here Comes the Sun", 3.05, 7);
    addSong("The Beatles", "Abbey Road", "Because", 2.45, 8);
    addSong("The Beatles", "Abbey Road", "You Never Give Me Your Money", 4.02, 9);
    addSong("The Beatles", "Abbey Road", "Sun King", 2.26, 10);
    addSong("The Beatles", "Abbey Road", "Mean Mr. Mustard", 1.06, 11);
    addSong("The Beatles", "Abbey Road", "Polythene Pam", 1.13, 12);
    addSong("The Beatles", "Abbey Road", "She Came in Through the Bathroom Window", 1.57, 13);
    addSong("The Beatles", "Abbey Road", "Golden Slumbers", 1.31, 14);
    addSong("The Beatles", "Abbey Road", "Carry That Weight", 1.37, 15);
    addSong("The Beatles", "Abbey Road", "The End", 2.20, 16);
    addSong("The Beatles", "Abbey Road", "Her Majesty", 0.23, 17);

    addArtist("Queen");
    addAlbum("Queen", "A Night at the Opera");
    addSong("Queen", "A Night at the Opera", "Death on Two Legs (Dedicated to...)", 3.43, 1);
    addSong("Queen", "A Night at the Opera", "Lazing on a Sunday Afternoon", 1.07, 2);
    addSong("Queen", "A Night at the Opera", "I'm in Love with My Car", 3.05, 3);
    addSong("Queen", "A Night at the Opera", "You're My Best Friend", 2.52, 4);
    addSong("Queen", "A Night at the Opera", "'39", 3.30, 5);
    addSong("Queen", "A Night at the Opera", "Sweet Lady", 4.03, 6);
    addSong("Queen", "A Night at the Opera", "Seaside Rendezvous", 2.13, 7);
    addSong("Queen", "A Night at the Opera", "The Prophet's Song", 8.21, 8);
    addSong("Queen", "A Night at the Opera", "Love of My Life", 3.38, 9);
    addSong("Queen", "A Night at the Opera", "Good Company", 3.26, 10);
    addSong("Queen", "A Night at the Opera", "Bohemian Rhapsody", 5.55, 11);
    addSong("Queen", "A Night at the Opera", "God Save the Queen", 1.05, 12);

    printLibrary();

    return 0;
}