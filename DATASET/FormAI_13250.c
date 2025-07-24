//FormAI DATASET v1.0 Category: Music Library Management System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_ARTISTS 100
#define MAX_ALBUMS 1000
#define MAX_SONGS 10000

// Define data structures for artists, albums, and songs
struct artist {
    char name[100];
    int num_albums;
    int albums[MAX_ALBUMS];
};

struct album {
    char title[100];
    int year;
    int artist;
    int num_songs;
    int songs[MAX_SONGS];
};

struct song {
    char title[100];
    float duration;
    int album;
};

// Define global variables
struct artist artist_list[MAX_ARTISTS];
int num_artists = 0;
struct album album_list[MAX_ALBUMS];
int num_albums = 0;
struct song song_list[MAX_SONGS];
int num_songs = 0;

// Function to add a new artist
void add_artist(char *name) {
    strcpy(artist_list[num_artists].name, name);
    artist_list[num_artists].num_albums = 0;
    num_artists++;
}

// Function to add a new album
void add_album(char *title, int year, char *artist_name) {
    // Find the ID of the artist
    int artist_id = -1;
    for (int i = 0; i < num_artists; i++) {
        if (strcmp(artist_list[i].name, artist_name) == 0) {
            artist_id = i;
            break;
        }
    }

    // If the artist does not exist, add them
    if (artist_id == -1) {
        add_artist(artist_name);
        artist_id = num_artists - 1;
    }

    // Add the album to the album list
    strcpy(album_list[num_albums].title, title);
    album_list[num_albums].year = year;
    album_list[num_albums].artist = artist_id;
    album_list[num_albums].num_songs = 0;
    artist_list[artist_id].albums[artist_list[artist_id].num_albums++] = num_albums;
    num_albums++;
}

// Function to add a new song
void add_song(char *title, float duration, char *album_title) {
    // Find the ID of the album
    int album_id = -1;
    for (int i = 0; i < num_albums; i++) {
        if (strcmp(album_list[i].title, album_title) == 0) {
            album_id = i;
            break;
        }
    }

    // If the album does not exist, return an error
    if (album_id == -1) {
        printf("Error: Album not found\n");
        return;
    }

    // Add the song to the song list and the album's list of songs
    strcpy(song_list[num_songs].title, title);
    song_list[num_songs].duration = duration;
    song_list[num_songs].album = album_id;
    album_list[album_id].songs[album_list[album_id].num_songs++] = num_songs;
    num_songs++;
}

// Function to print all the artists, their albums, and the songs on each album
void print_library() {
    for (int i = 0; i < num_artists; i++) {
        printf("Artist: %s\n", artist_list[i].name);
        for (int j = 0; j < artist_list[i].num_albums; j++) {
            int album_id = artist_list[i].albums[j];
            printf("  Album: %s (%d)\n", album_list[album_id].title, album_list[album_id].year);
            for (int k = 0; k < album_list[album_id].num_songs; k++) {
                int song_id = album_list[album_id].songs[k];
                printf("    Song: %s (%.2f minutes)\n", song_list[song_id].title, song_list[song_id].duration);
            }
        }
    }
}

// Main program loop
int main() {
    // Add some test data
    add_album("Back in Black", 1980, "AC/DC");
    add_song("Hells Bells", 5.12, "Back in Black");
    add_song("Shoot to Thrill", 5.17, "Back in Black");
    add_song("Givin the Dog a Bone", 3.31, "Back in Black");
    add_song("Rock and Roll Ain't Noise Pollution", 4.12, "Back in Black");

    add_album("The Wall", 1979, "Pink Floyd");
    add_song("In the Flesh?", 3.19, "The Wall");
    add_song("Another Brick in the Wall (Part 1)", 3.11, "The Wall");
    add_song("The Happiest Days of Our Lives", 1.46, "The Wall");
    add_song("Another Brick in the Wall (Part 2)", 4.01, "The Wall");

    add_album("Nevermind", 1991, "Nirvana");
    add_song("Smells Like Teen Spirit", 5.01, "Nevermind");
    add_song("In Bloom", 4.14, "Nevermind");
    add_song("Come as You Are", 3.39, "Nevermind");
    add_song("Lithium", 4.17, "Nevermind");

    // Print the library
    print_library();

    return 0;
}