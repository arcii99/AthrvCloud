//FormAI DATASET v1.0 Category: Music Library Management System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALBUMS 10
#define MAX_SONGS 50

// Struct for a Song
typedef struct {
    char title[50];
    char artist[50];
    float duration;
    int rating;
} Song;

// Struct for an Album
typedef struct {
    char title[50];
    char artist[50];
    int year;
    Song songs[MAX_SONGS];
    int num_songs;
} Album;

// Struct for the Music Library
typedef struct {
    Album albums[MAX_ALBUMS];
    int num_albums;
} Library;

// Function Prototypes
void add_album(Library * library);
void add_song_album(Album * album);
void display_library(Library library);
void display_album(Album album);
int get_int_input(int min, int max);
float get_float_input(float min, float max);

// Main function
int main() {
    Library library;
    library.num_albums = 0;
    int choice = 0;

    do {
        printf("Music Library Management System\n");
        printf("1. Add Album\n");
        printf("2. Display Library\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        choice = get_int_input(1, 3);

        switch (choice) {
            case 1:
                add_album(&library);
                break;
            case 2:
                display_library(library);
                break;
            case 3:
                printf("Thank you for using the Music Library Management System!");
                break;
        }

    } while (choice != 3);

    return 0;
}

// Function to add an album to the library
void add_album(Library * library) {
    if (library->num_albums >= MAX_ALBUMS) {
        printf("Error: Maximum albums limit reached.");
        return;
    }

    Album new_album;
    printf("\nAdding Album:\n");
    printf("Enter Album Title: ");
    fgets(new_album.title, 50, stdin);
    printf("Enter Artist Name: ");
    fgets(new_album.artist, 50, stdin);
    printf("Enter Year Released: ");
    new_album.year = get_int_input(0, 2021);

    // Add songs to album
    add_song_album(&new_album);

    // Add album to library
    library->albums[library->num_albums] = new_album;
    library->num_albums++;

    printf("\nAlbum added successfully!\n");
}

// Function to add songs to an album
void add_song_album(Album * album) {
    char choice = 'n';
    int i = album->num_songs;

    do {
        if (i >= MAX_SONGS) {
            printf("Error: Maximum number of songs reached.");
            return;
        }

        printf("Add Song %d\n", i + 1);
        printf("Enter Song Title: ");
        fgets(album->songs[i].title, 50, stdin);
        printf("Enter Artist Name: ");
        fgets(album->songs[i].artist, 50, stdin);
        printf("Enter Song Duration (in minutes): ");
        album->songs[i].duration = get_float_input(0.0, 100.0);
        printf("Enter Song Rating (out of 10): ");
        album->songs[i].rating = get_int_input(0, 10);

        album->num_songs++;
        i++;

        printf("Do you want to add another song? (y/n): ");
        choice = getchar();
        getchar(); // Clear input buffer

    } while (choice == 'y');
}

// Function to display the entire library
void display_library(Library library) {
    printf("\nDisplaying Library:\n");
    if (library.num_albums == 0) {
        printf("Error: Library is empty.");
        return;
    }

    for (int i = 0; i < library.num_albums; i++) {
        display_album(library.albums[i]);
    }
}

// Function to display an album with all its songs
void display_album(Album album) {
    printf("\nAlbum Title: %s", album.title);
    printf("Artist Name: %s", album.artist);
    printf("Year Released: %d\n", album.year);

    printf("Songs in Album:\n");
    for (int i = 0; i < album.num_songs; i++) {
        printf("Song %d: %s", i + 1, album.songs[i].title);
        printf("Artist: %sDuration: %.2f minutes Rating: %d\n", album.songs[i].artist, album.songs[i].duration, album.songs[i].rating);
    }
}

// Function to get an integer input within a given range
int get_int_input(int min, int max) {
    int input;
    do {
        scanf("%d", &input);
        getchar(); // Clear input buffer
        if (input < min || input > max) {
            printf("Invalid input. Try again: ");
        }
    } while (input < min || input > max);
    return input;
}

// Function to get a float input within a given range
float get_float_input(float min, float max) {
    float input;
    do {
        scanf("%f", &input);
        getchar(); // Clear input buffer
        if (input < min || input > max) {
            printf("Invalid input. Try again: ");
        }
    } while (input < min || input > max);
    return input;
}