//FormAI DATASET v1.0 Category: Music Library Management System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define MAX_SONGS 1000

typedef struct Song {
    char title[50];
    char artist[50];
    int year;
    int duration; // in seconds
    char genre[20];
} Song;

Song song_library[MAX_SONGS]; // main library to store all songs
int num_songs = 0; // current number of songs

bool add_song(char *title, char *artist, int year, int duration, char *genre) {
    if (num_songs >= MAX_SONGS) {
        printf("Error: Library is full. Cannot add song.\n");
        return false;
    }

    Song new_song;
    strcpy(new_song.title, title);
    strcpy(new_song.artist, artist);
    new_song.year = year;
    new_song.duration = duration;
    strcpy(new_song.genre, genre);

    song_library[num_songs] = new_song;
    num_songs++;

    printf("Song added to library: %s by %s.\n", new_song.title, new_song.artist);
    return true;
}

void print_library() {
    if (num_songs == 0) {
        printf("Library is empty.\n");
        return;
    }

    printf("Library:\n");
    printf("%-30s %-30s %-10s %-10s %-20s\n", "Title", "Artist", "Year", "Duration", "Genre");
    for (int i = 0; i < num_songs; i++) {
        printf("%-30s %-30s %-10d %-10d %-20s\n", song_library[i].title, song_library[i].artist, 
                                                    song_library[i].year, song_library[i].duration, 
                                                    song_library[i].genre);
    }
}

void search_songs(char *query) {
    if (num_songs == 0) {
        printf("Library is empty.\n");
        return;
    }

    printf("Search Results:\n");
    printf("%-30s %-30s %-10s %-10s %-20s\n", "Title", "Artist", "Year", "Duration", "Genre");
    for (int i = 0; i < num_songs; i++) {
        if (strstr(song_library[i].title, query) != NULL || strstr(song_library[i].artist, query) != NULL
                                                         || strstr(song_library[i].genre, query) != NULL) {
            printf("%-30s %-30s %-10d %-10d %-20s\n", song_library[i].title, song_library[i].artist, 
                                                        song_library[i].year, song_library[i].duration, 
                                                        song_library[i].genre);
        }
    }
}

void generate_playlist(int num_songs_wanted, char *genre_wanted) {
    if (num_songs == 0) {
        printf("Library is empty.\n");
        return;
    }

    printf("Generating playlist...\n");

    // seed random number generator for shuffling songs
    srand(time(NULL));

    // create new playlist array
    Song playlist[num_songs];
    int num_songs_of_genre = 0;

    // loop through library to find and add songs of desired genre
    for (int i = 0; i < num_songs; i++) {
        if (strcmp(song_library[i].genre, genre_wanted) == 0) {
            playlist[num_songs_of_genre] = song_library[i];
            num_songs_of_genre++;
        }
    }
    if (num_songs_of_genre == 0) {
        printf("Error: No songs found with genre: %s.\n", genre_wanted);
        return;
    }

    // shuffle playlist using Fisher-Yates algorithm
    for (int i = num_songs_of_genre - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Song temp = playlist[i];
        playlist[i] = playlist[j];
        playlist[j] = temp;
    }

    printf("Playlist:\n");
    printf("%-30s %-30s %-10s %-10s %-20s\n", "Title", "Artist", "Year", "Duration", "Genre");
    for (int i = 0; i < num_songs_wanted && i < num_songs_of_genre; i++) {
        printf("%-30s %-30s %-10d %-10d %-20s\n", playlist[i].title, playlist[i].artist, 
                                                    playlist[i].year, playlist[i].duration, 
                                                    playlist[i].genre);
    }
}

int main() {
    // add some demo songs
    add_song("Happy", "Pharrell Williams", 2013, 233, "Pop");
    add_song("Bohemian Rhapsody", "Queen", 1975, 367, "Classic Rock");
    add_song("Billie Jean", "Michael Jackson", 1983, 296, "Pop");
    add_song("Stairway to Heaven", "Led Zeppelin", 1971, 482, "Classic Rock");
    add_song("Say You Love Me", "Fleetwood Mac", 1975, 258, "Rock");
    add_song("Watermelon Sugar", "Harry Styles", 2019, 234, "Pop");
    add_song("Sweet Caroline", "Neil Diamond", 1969, 206, "Pop");
    add_song("Purple Haze", "Jimi Hendrix", 1967, 168, "Rock");
    add_song("Dancing Queen", "ABBA", 1976, 227, "Pop");
    add_song("Living on a Prayer", "Bon Jovi", 1986, 244, "Rock");

    // test out functions
    printf("\n");
    print_library();
    printf("\n");
    search_songs("Queen");
    printf("\n");
    generate_playlist(5, "Pop");
    printf("\n");
    generate_playlist(3, "Rock");
    printf("\n");

    return 0;
}