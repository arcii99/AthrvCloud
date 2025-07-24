//FormAI DATASET v1.0 Category: Music Library Management System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARTISTS 100
#define MAX_ALBUMS 1000
#define MAX_SONGS 10000

typedef struct Song {
    char title[50];
    int duration;
} Song;

typedef struct Album {
    char title[50];
    char artist[50];
    int year;
    int n_songs;
    Song songs[MAX_SONGS];
} Album;

typedef struct Artist {
    char name[50];
    char origin[50];
    int n_albums;
    Album albums[MAX_ALBUMS];
} Artist;

typedef struct MusicLibrary {
    int n_artists;
    Artist artists[MAX_ARTISTS];
} MusicLibrary;

void add_song_to_album(Album *album, char *title, int duration);
void add_album_to_artist(Artist *artist, char *title, char *artist_name, int year);
void add_artist_to_library(MusicLibrary *library, char *name, char *origin);
void add_album_to_library(MusicLibrary *library, char *title, char *artist_name, int year);
void add_song_to_library(MusicLibrary *library, char *title, char *artist_name, char *album_title, int duration);
void print_library(MusicLibrary *library);

int main() {
    MusicLibrary library;
    library.n_artists = 0;

    add_artist_to_library(&library, "Pink Floyd", "London");
    add_album_to_library(&library, "Dark Side of the Moon", "Pink Floyd", 1973);
    add_song_to_library(&library, "Time", "Pink Floyd", "Dark Side of the Moon", 420);
    add_song_to_library(&library, "Money", "Pink Floyd", "Dark Side of the Moon", 390);
    add_album_to_library(&library, "Wish You Were Here", "Pink Floyd", 1975);
    add_song_to_library(&library, "Shine On You Crazy Diamond", "Pink Floyd", "Wish You Were Here", 810);
    add_song_to_library(&library, "Wish You Were Here", "Pink Floyd", "Wish You Were Here", 330);
    add_artist_to_library(&library, "Led Zeppelin", "London");
    add_album_to_library(&library, "IV", "Led Zeppelin", 1971);
    add_song_to_library(&library, "Stairway to Heaven", "Led Zeppelin", "IV", 480);

    print_library(&library);

    return 0;
}

void add_song_to_album(Album *album, char *title, int duration) {
    strcpy(album->songs[album->n_songs].title, title);
    album->songs[album->n_songs].duration = duration;
    album->n_songs++;
}

void add_album_to_artist(Artist *artist, char *title, char *artist_name, int year) {
    strcpy(artist->albums[artist->n_albums].title, title);
    strcpy(artist->albums[artist->n_albums].artist, artist_name);
    artist->albums[artist->n_albums].year = year;
    artist->albums[artist->n_albums].n_songs = 0;
    artist->n_albums++;
}

void add_artist_to_library(MusicLibrary *library, char *name, char *origin) {
    strcpy(library->artists[library->n_artists].name, name);
    strcpy(library->artists[library->n_artists].origin, origin);
    library->artists[library->n_artists].n_albums = 0;
    library->n_artists++;
}

void add_album_to_library(MusicLibrary *library, char *title, char *artist_name, int year) {
    Artist *artist = NULL;
    for (int i = 0; i < library->n_artists; i++) {
        if (strcmp(library->artists[i].name, artist_name) == 0) {
            artist = &library->artists[i];
            break;
        }
    }
    if (artist == NULL) {
        add_artist_to_library(library, artist_name, "");
        artist = &library->artists[library->n_artists - 1];
    }
    add_album_to_artist(artist, title, artist_name, year);
}

void add_song_to_library(MusicLibrary *library, char *title, char *artist_name, char *album_title, int duration) {
    Artist *artist = NULL;
    Album *album = NULL;
    for (int i = 0; i < library->n_artists; i++) {
        if (strcmp(library->artists[i].name, artist_name) == 0) {
            artist = &library->artists[i];
            break;
        }
    }
    if (artist == NULL) {
        add_artist_to_library(library, artist_name, "");
        artist = &library->artists[library->n_artists - 1];
    }
    for (int i = 0; i < artist->n_albums; i++) {
        if (strcmp(artist->albums[i].title, album_title) == 0) {
            album = &artist->albums[i];
            break;
        }
    }
    if (album == NULL) {
        add_album_to_artist(artist, album_title, artist_name, 0);
        album = &artist->albums[artist->n_albums - 1];
    }
    add_song_to_album(album, title, duration);
}

void print_library(MusicLibrary *library) {
    printf("Music Library:\n");
    for (int i = 0; i < library->n_artists; i++) {
        printf("Artist: %s (origin: %s)\n", library->artists[i].name, library->artists[i].origin);
        for (int j = 0; j < library->artists[i].n_albums; j++) {
            printf("  Album: %s (year: %d)\n", library->artists[i].albums[j].title, library->artists[i].albums[j].year);
            for (int k = 0; k < library->artists[i].albums[j].n_songs; k++) {
                printf("    Song: %s (duration: %d seconds)\n", library->artists[i].albums[j].songs[k].title, library->artists[i].albums[j].songs[k].duration);
            }
        }
    }
}