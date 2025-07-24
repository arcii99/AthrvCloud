//FormAI DATASET v1.0 Category: Music Library Management System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARTISTS 1000
#define MAX_SONGS 5000
#define MAX_ALBUMS 1000

struct Artist {
    char name[50];
    int num_songs;
    int albums[MAX_ALBUMS];
    int num_albums;
};

struct Song {
    char name[50];
    int artist_id;
    int album_id;
};

struct Album {
    char name[50];
    int artist_id;
    int songs[MAX_SONGS];
    int num_songs;
};

struct MusicLibrary {
    struct Artist artists[MAX_ARTISTS];
    struct Song songs[MAX_SONGS];
    struct Album albums[MAX_ALBUMS];
    int num_artists;
    int num_songs;
    int num_albums;
};

void add_artist(struct MusicLibrary *l, char *name) {
    strcpy(l->artists[l->num_artists].name, name);
    l->artists[l->num_artists].num_songs = 0;
    l->artists[l->num_artists].num_albums = 0;
    l->num_artists++;
}

void add_album(struct MusicLibrary *l, char *name, int artist_id) {
    strcpy(l->albums[l->num_albums].name, name);
    l->albums[l->num_albums].artist_id = artist_id;
    l->albums[l->num_albums].num_songs = 0;
    l->artists[artist_id].albums[l->artists[artist_id].num_albums] = l->num_albums;
    l->artists[artist_id].num_albums++;
    l->num_albums++;
}

void add_song(struct MusicLibrary *l, char *name, int artist_id, int album_id) {
    strcpy(l->songs[l->num_songs].name, name);
    l->songs[l->num_songs].artist_id = artist_id;
    l->songs[l->num_songs].album_id = album_id;
    l->albums[album_id].songs[l->albums[album_id].num_songs] = l->num_songs;
    l->albums[album_id].num_songs++;
    l->artists[artist_id].num_songs++;
    l->num_songs++;
}

void print_artist(struct MusicLibrary l, int artist_id) {
    printf("Artist: %s\n", l.artists[artist_id].name);
    printf("Number of albums: %d\n", l.artists[artist_id].num_albums);
    for (int i = 0; i < l.artists[artist_id].num_albums; i++) {
        printf("Album %d: %s\n", i, l.albums[l.artists[artist_id].albums[i]].name);
    }
    printf("Number of songs: %d\n", l.artists[artist_id].num_songs);
}

void print_album(struct MusicLibrary l, int album_id) {
    printf("Album: %s\n", l.albums[album_id].name);
    printf("Artist: %s\n", l.artists[l.albums[album_id].artist_id].name);
    printf("Number of songs: %d\n", l.albums[album_id].num_songs);
    for (int i = 0; i < l.albums[album_id].num_songs; i++) {
        printf("Song %d: %s\n", i, l.songs[l.albums[album_id].songs[i]].name);
    }
}

void print_song(struct MusicLibrary l, int song_id) {
    printf("Song: %s\n", l.songs[song_id].name);
    printf("Artist: %s\n", l.artists[l.songs[song_id].artist_id].name);
    printf("Album: %s\n", l.albums[l.songs[song_id].album_id].name);
}

int main() {
    struct MusicLibrary library;
    library.num_artists = 0;
    library.num_songs = 0;
    library.num_albums = 0;
    add_artist(&library, "The Beatles");
    add_album(&library, "Abbey Road", 0);
    add_song(&library, "Come Together", 0, 0);
    add_song(&library, "Something", 0, 0);
    add_song(&library, "Maxwell's Silver Hammer", 0, 0);
    add_album(&library, "The White Album", 0);
    add_song(&library, "Back in the U.S.S.R.", 0, 1);
    add_song(&library, "Dear Prudence", 0, 1);
    add_song(&library, "Ob-La-Di, Ob-La-Da", 0, 1);
    add_song(&library, "While My Guitar Gently Weeps", 0, 1);
    print_artist(library, 0);
    print_album(library, 0);
    print_song(library, 0);
    return 0;
}