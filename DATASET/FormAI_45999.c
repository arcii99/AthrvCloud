//FormAI DATASET v1.0 Category: Music Library Management System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARTISTS 100
#define MAX_ALBUMS 1000
#define MAX_SONGS 10000

// Structs to hold data
typedef struct {
    int artist_id;
    char artist_name[50];
} Artist;

typedef struct {
    int album_id;
    char album_title[100];
    int year;
    int artist_id;
} Album;

typedef struct {
    int song_id;
    char song_title[100];
    int duration;
    int album_id;
    int artist_id;
} Song;

// Global variables to hold data
static Artist artists[MAX_ARTISTS];
static int num_artists = 0;

static Album albums[MAX_ALBUMS];
static int num_albums = 0;

static Song songs[MAX_SONGS];
static int num_songs = 0;

// Function to add new data
void add_artist(char *name) {
    if (num_artists == MAX_ARTISTS) {
        printf("Error: Maximum number of artists reached\n");
        return;
    }
    artists[num_artists].artist_id = num_artists + 1;
    strcpy(artists[num_artists].artist_name, name);
    num_artists++;
}

void add_album(char *title, int year, int artist_id) {
    if (num_albums == MAX_ALBUMS) {
        printf("Error: Maximum number of albums reached\n");
        return;
    }
    albums[num_albums].album_id = num_albums + 1;
    strcpy(albums[num_albums].album_title, title);
    albums[num_albums].year = year;
    albums[num_albums].artist_id = artist_id;
    num_albums++;
}

void add_song(char *title, int duration, int album_id, int artist_id) {
    if (num_songs == MAX_SONGS) {
        printf("Error: Maximum number of songs reached\n");
        return;
    }
    songs[num_songs].song_id = num_songs + 1;
    strcpy(songs[num_songs].song_title, title);
    songs[num_songs].duration = duration;
    songs[num_songs].album_id = album_id;
    songs[num_songs].artist_id = artist_id;
    num_songs++;
}

// Function to display data
void display_artists() {
    printf("Artists:\n");
    for (int i = 0; i < num_artists; i++) {
        printf("%d. %s\n", artists[i].artist_id, artists[i].artist_name);
    }
}

void display_albums(int artist_id) {
    printf("Albums by Artist %d:\n", artist_id);
    for (int i = 0; i < num_albums; i++) {
        if (albums[i].artist_id == artist_id) {
            printf("%d. %s (%d)\n", albums[i].album_id, albums[i].album_title, albums[i].year);
        }
    }
}

void display_songs(int album_id) {
    printf("Songs on Album %d:\n", album_id);
    for (int i = 0; i < num_songs; i++) {
        if (songs[i].album_id == album_id) {
            printf("%d. %s (%d seconds)\n", songs[i].song_id, songs[i].song_title, songs[i].duration);
        }
    }
}

int main() {
    // Add some sample data
    add_artist("The Beatles");
    add_album("Abbey Road", 1969, 1);
    add_song("Come Together", 259, 1, 1);
    add_song("Something", 182, 1, 1);
    add_song("Maxwell's Silver Hammer", 215, 1, 1);

    add_album("White Album", 1968, 1);
    add_song("Back in the USSR", 163, 2, 1);
    add_song("Dear Prudence", 228, 2, 1);
    add_song("Helter Skelter", 240, 2, 1);

    add_artist("Led Zeppelin");
    add_album("Led Zeppelin IV", 1971, 2);
    add_song("Stairway to Heaven", 482, 3, 2);
    add_song("Rock and Roll", 219, 3, 2);
    add_song("Black Dog", 296, 3, 2);

    // Display the data
    display_artists();
    display_albums(1);
    display_songs(2);

    return 0;
}