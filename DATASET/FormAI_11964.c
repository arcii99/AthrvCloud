//FormAI DATASET v1.0 Category: Music Library Management System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALBUMS 50
#define MAX_SONGS 200

// Structure for a song
struct Song {
    char name[50];
    char artist[50];
    float duration;
};

// Structure for an album
struct Album {
    char title[50];
    int year;
    char artist[50];
    int num_songs;
    struct Song songs[MAX_SONGS];
};

// Global variables
struct Album albums[MAX_ALBUMS];
int num_albums = 0;

// Function to add an album
void add_album() {
    struct Album album;
    printf("Please enter the title of the album: ");
    fgets(album.title, 50, stdin);
    printf("Please enter the release year of the album: ");
    scanf("%d", &album.year);
    getchar();
    printf("Please enter the artist of the album: ");
    fgets(album.artist, 50, stdin);
    printf("Please enter the number of songs in the album: ");
    scanf("%d", &album.num_songs);
    getchar();
    for (int i = 0; i < album.num_songs; i++) {
        printf("Please enter the name of song #%d: ", i+1);
        fgets(album.songs[i].name, 50, stdin);
        printf("Please enter the artist of song #%d: ", i+1);
        fgets(album.songs[i].artist, 50, stdin);
        printf("Please enter the duration of song #%d (in minutes): ", i+1);
        scanf("%f", &album.songs[i].duration);
        getchar();
    }
    albums[num_albums++] = album;
    printf("Album added successfully!\n");
}

// Function to display all the albums
void display_albums() {
    if (num_albums == 0) {
        printf("No albums to display!\n");
        return;
    }
    printf("-------------------------------\n");
    for (int i = 0; i < num_albums; i++) {
        struct Album album = albums[i];
        printf("Title: %s", album.title);
        printf("Year: %d\n", album.year);
        printf("Artist: %s", album.artist);
        printf("Number of Songs: %d\n", album.num_songs);
        printf("SONGS:\n");
        for (int j = 0; j < album.num_songs; j++) {
            struct Song song = album.songs[j];
            printf("\tName: %s", song.name);
            printf("\tArtist: %s", song.artist);
            printf("\tDuration: %.2f minutes\n", song.duration);
        }
        printf("-------------------------------\n");
    }
}

// Function to search for an album
void search_album() {
    if (num_albums == 0) {
        printf("No albums to search!\n");
        return;
    }
    char search_title[50];
    printf("Please enter the title of the album to search: ");
    fgets(search_title, 50, stdin);
    for (int i = 0; i < num_albums; i++) {
        struct Album album = albums[i];
        if (strcmp(search_title, album.title) == 0) {
            printf("-------------------------------\n");
            printf("Title: %s", album.title);
            printf("Year: %d\n", album.year);
            printf("Artist: %s", album.artist);
            printf("Number of Songs: %d\n", album.num_songs);
            printf("SONGS:\n");
            for (int j = 0; j < album.num_songs; j++) {
                struct Song song = album.songs[j];
                printf("\tName: %s", song.name);
                printf("\tArtist: %s", song.artist);
                printf("\tDuration: %.2f minutes\n", song.duration);
            }
            printf("-------------------------------\n");
            return;
        }
    }
    printf("Album not found!\n");
}

// Function to delete an album
void delete_album() {
    if (num_albums == 0) {
        printf("No albums to delete!\n");
        return;
    }
    char delete_title[50];
    printf("Please enter the title of the album to delete: ");
    fgets(delete_title, 50, stdin);
    for (int i = 0; i < num_albums; i++) {
        struct Album album = albums[i];
        if (strcmp(delete_title, album.title) == 0) {
            for (int j = i; j < num_albums-1; j++) {
                albums[j] = albums[j+1];
            }
            num_albums--;
            printf("Album deleted successfully!\n");
            return;
        }
    }
    printf("Album not found!\n");
}

// Main function
int main() {
    int choice;
    do {
        printf("MENU:\n");
        printf("1. Add an album\n");
        printf("2. Display all albums\n");
        printf("3. Search for an album\n");
        printf("4. Delete an album\n");
        printf("5. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1: add_album();
                    break;
            case 2: display_albums();
                    break;
            case 3: search_album();
                    break;
            case 4: delete_album();
                    break;
            case 5: printf("Exiting the program, thank you!\n");
                    break;
            default: printf("Invalid choice, please try again!\n");
                     break;
        }
    } while (choice != 5);
    return 0;
}