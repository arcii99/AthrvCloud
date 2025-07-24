//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Artist {
    char name[50];
    int num_albums;
};

struct Album {
    char name[50];
    char release_date[11]; // YYYY-MM-DD
    struct Artist artist;
    int num_songs;
};

struct Song {
    char name[50];
    int duration; // in seconds
    struct Album album;
};

void print_artist(struct Artist artist);
void print_album(struct Album album);
void print_song(struct Song song);
void print_library(struct Song *library, int num_songs);
void sort_library(struct Song *library, int num_songs);
int get_total_duration(struct Song *library, int num_songs);
void update_artist(struct Artist *artist, char *new_name, int new_num_albums);

int main() {
    // Create some sample data
    struct Artist a1 = {"Taylor Swift", 9};
    struct Artist a2 = {"The Beatles", 13};
    struct Album al1 = {"Folklore", "2020-07-24", a1, 16};
    struct Album al2 = {"Revolver", "1966-08-05", a2, 14};
    struct Song s1 = {"Cardigan", 239, al1};
    struct Song s2 = {"Eleanor Rigby", 155, al2};
    struct Song s3 = {"August", 258, al1};

    // Put the songs in an array
    struct Song library[3] = {s1, s2, s3};
    int num_songs = 3;

    // Print out the library before sorting
    printf("Library before sorting:\n");
    print_library(library, num_songs);
    printf("\n");

    // Sort the library
    sort_library(library, num_songs);

    // Print out the library after sorting
    printf("Library after sorting:\n");
    print_library(library, num_songs);
    printf("\n");

    // Get the total duration of the library
    int total_duration = get_total_duration(library, num_songs);
    printf("Total duration of library: %d seconds\n", total_duration);
    printf("\n");

    // Update an artist's information
    printf("Before update:\n");
    print_artist(a1);
    printf("\n");
    update_artist(&a1, "Taylor Swift - New name", 10);
    printf("After update:\n");
    print_artist(a1);

    return 0;
}

void print_artist(struct Artist artist) {
    printf("Name: %s\n", artist.name);
    printf("Number of albums: %d\n", artist.num_albums);
}

void print_album(struct Album album) {
    printf("Name: %s\n", album.name);
    printf("Release date: %s\n", album.release_date);
    printf("Artist:\n");
    print_artist(album.artist);
    printf("Number of songs: %d\n", album.num_songs);
}

void print_song(struct Song song) {
    printf("Name: %s\n", song.name);
    printf("Duration: %d seconds\n", song.duration);
    printf("Album:\n");
    print_album(song.album);
}

void print_library(struct Song *library, int num_songs) {
    for (int i = 0; i < num_songs; i++) {
        print_song(library[i]);
    }
}

void sort_library(struct Song *library, int num_songs) {
    // Insertion sort by song name
    for (int i = 1; i < num_songs; i++) {
        struct Song key = library[i];
        int j = i - 1;
        while (j >= 0 && strcmp(library[j].name, key.name) > 0) {
            library[j + 1] = library[j];
            j--;
        }
        library[j + 1] = key;
    }
}

int get_total_duration(struct Song *library, int num_songs) {
    int total_duration = 0;
    for (int i = 0; i < num_songs; i++) {
        total_duration += library[i].duration;
    }
    return total_duration;
}

void update_artist(struct Artist *artist, char *new_name, int new_num_albums) {
    strcpy(artist->name, new_name);
    artist->num_albums = new_num_albums;
}