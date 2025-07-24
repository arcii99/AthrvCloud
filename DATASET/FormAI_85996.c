//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALBUMS 50
#define MAX_SONGS_PER_ALBUM 20

typedef struct {
    char title[50];
    char artist[50];
    int year;
    int length; // in seconds
} Song;

typedef struct {
    char title[50];
    char artist[50];
    int year;
    Song songs[MAX_SONGS_PER_ALBUM];
    int num_songs;
} Album;

void add_song_to_album(Album* album, const char* title, const char* artist, int year, int length) {
    if (album->num_songs >= MAX_SONGS_PER_ALBUM) {
        printf("Album \"%s\" has reached maximum song capacity.\n", album->title);
        return;
    }
    Song* song = &album->songs[album->num_songs];
    strncpy(song->title, title, sizeof(song->title));
    strncpy(song->artist, artist, sizeof(song->artist));
    song->year = year;
    song->length = length;
    album->num_songs++;
}

int main() {
    Album albums[MAX_ALBUMS];
    int num_albums = 0;

    // Create some example albums
    Album album1 = {"Album 1", "Artist A", 2000, {}, 0};
    add_song_to_album(&album1, "Song 1", "Artist A", 2000, 180);
    add_song_to_album(&album1, "Song 2", "Artist A", 2000, 240);
    albums[num_albums++] = album1;

    Album album2 = {"Album 2", "Artist B", 1995, {}, 0};
    add_song_to_album(&album2, "Song 3", "Artist B", 1995, 200);
    albums[num_albums++] = album2;

    // Print out album information
    for (int i = 0; i < num_albums; i++) {
        Album* album = &albums[i];
        printf("Album: %s\n", album->title);
        printf("Artist: %s\n", album->artist);
        printf("Year: %d\n", album->year);
        printf("Songs:\n");
        for (int j = 0; j < album->num_songs; j++) {
            Song* song = &album->songs[j];
            printf("- %s (%s, %d, %d seconds)\n", song->title, song->artist, song->year, song->length);
        }
        printf("\n");
    }

    return 0;
}