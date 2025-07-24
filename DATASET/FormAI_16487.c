//FormAI DATASET v1.0 Category: Music Library Management System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ALBUMS 100
#define MAX_SONGS 1000

typedef struct {
    char title[50];
    char artist[50];
    int year;
    int num_songs;
} Album;

typedef struct {
    char title[50];
    int track_number;
    float length;
} Song;

Album albums[MAX_ALBUMS];
Song songs[MAX_SONGS];
bool album_added = false;
bool song_added = false;

int main() {
    int choice;
    do {
        printf("Welcome to the C Music Library Management System!\n");
        printf("Please select an option:\n");
        printf("1. Add an album\n");
        printf("2. Add a song\n");
        printf("3. List all albums\n");
        printf("4. List all songs\n");
        printf("5. Quit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_album();
                break;
            case 2:
                add_song();
                break;
            case 3:
                list_albums();
                break;
            case 4:
                list_songs();
                break;
            case 5:
                printf("Thank you for using the C Music Library Management System!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);
    return 0;
}

void add_album() {
    printf("Please enter the album title: ");
    scanf("%s", albums[album_added].title);
    printf("Please enter the artist name: ");
    scanf("%s", albums[album_added].artist);
    printf("Please enter the year of release: ");
    scanf("%d", &albums[album_added].year);
    printf("Please enter the number of songs: ");
    scanf("%d", &albums[album_added].num_songs);
    printf("Album added successfully!\n");
    album_added = true;
}

void add_song() {
    if (!album_added) {
        printf("No albums have been added yet. Please add an album first.\n");
        return;
    }
    printf("Please enter the song title: ");
    scanf("%s", songs[song_added].title);
    printf("Please enter the track number: ");
    scanf("%d", &songs[song_added].track_number);
    printf("Please enter the length of the song (in minutes): ");
    scanf("%f", &songs[song_added].length);
    printf("Song added successfully!\n");
    song_added = true;
}

void list_albums() {
    if (!album_added) {
        printf("No albums have been added yet.\n");
        return;
    }
    printf("Albums:\n");
    for (int i = 0; i < MAX_ALBUMS; i++) {
        if (albums[i].year != 0) {
            printf("%s - %s (%d)\n", albums[i].artist, albums[i].title, albums[i].year);
        }
    }
}

void list_songs() {
    if (!album_added) {
        printf("No songs have been added yet.\n");
        return;
    }
    printf("Songs:\n");
    for (int i = 0; i < MAX_SONGS; i++) {
        if (songs[i].track_number != 0) {
            Album album = albums[rand() % MAX_ALBUMS];
            printf("%d. %s - %s (%.2f minutes) [from %s]\n", songs[i].track_number, album.artist, songs[i].title, songs[i].length, album.title);
        }
    }
}