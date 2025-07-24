//FormAI DATASET v1.0 Category: Music Library Management System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALBUMS 100
#define MAX_SONGS 50

// Define data structures to store information about music library.
typedef struct {
    char album_title[100];
    char artist_name[100];
    int release_year;
    char genre[50];
    int num_songs;
    char songs[MAX_SONGS][100];
} Album;

typedef struct {
    Album albums[MAX_ALBUMS];
    int num_albums;
} MusicLibrary;

// Function prototypes.
void add_album(MusicLibrary *library);
void remove_album(MusicLibrary *library);
void search_album(MusicLibrary *library);
void display_library(MusicLibrary *library);

// Main function to manage the music library.
int main() {

    // Create a new music library.
    MusicLibrary library;
    library.num_albums = 0;

    // Allow user to interact with the music library.
    int choice;
    do {
        printf("\nWelcome to the Music Library Management System!\n");
        printf("Please choose an option:\n");
        printf("1. Add a new album\n");
        printf("2. Remove an existing album\n");
        printf("3. Search for an album\n");
        printf("4. Display entire library\n");
        printf("5. Quit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_album(&library);
                break;
            case 2:
                remove_album(&library);
                break;
            case 3:
                search_album(&library);
                break;
            case 4:
                display_library(&library);
                break;
            case 5:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while(choice != 5);

    printf("\nThank you for using the Music Library Management System!\n");
    return 0;
}

// Function to add a new album to the music library.
void add_album(MusicLibrary *library) {

    // Check if maximum number of albums have been reached.
    if(library->num_albums >= MAX_ALBUMS) {
        printf("Sorry, the music library is full. You cannot add any more albums.\n");
        return;
    }

    // Get album details from user.
    Album album;
    printf("\nEnter the following details of the new album:\n");
    printf("Album Title: ");
    scanf(" %[^\n]", album.album_title);
    printf("Artist Name: ");
    scanf(" %[^\n]", album.artist_name);
    printf("Release Year: ");
    scanf("%d", &album.release_year);
    printf("Genre: ");
    scanf(" %[^\n]", album.genre);
    printf("Number of songs: ");
    scanf("%d", &album.num_songs);
    printf("Enter the names of the songs (one song per line):\n");
    for(int i = 0; i < album.num_songs; i++) {
        scanf(" %[^\n]", album.songs[i]);
    }

    // Add the album to the library and increment the number of albums.
    library->albums[library->num_albums] = album;
    library->num_albums++;

    printf("Album added successfully!\n");
}

// Function to remove an existing album from the music library.
void remove_album(MusicLibrary *library) {

    // Check if the library is empty.
    if(library->num_albums == 0) {
        printf("Sorry, the music library is empty. There are no albums to remove.\n");
        return;
    }

    // Get the title of the album to be removed from the user.
    char album_title[100];
    printf("\nEnter the title of the album to be removed: ");
    scanf(" %[^\n]", album_title);

    // Search for the album in the library and remove it if found.
    int index = -1;
    for(int i = 0; i < library->num_albums; i++) {
        if(strcmp(library->albums[i].album_title, album_title) == 0) {
            index = i;
            break;
        }
    }
    if(index == -1) {
        printf("Sorry, the album with the title '%s' was not found in the music library.\n", album_title);
    } else {
        for(int i = index; i < library->num_albums - 1; i++) {
            library->albums[i] = library->albums[i + 1];
        }
        library->num_albums--;
        printf("Album removed successfully!\n");
    }
}

// Function to search for an album in the music library.
void search_album(MusicLibrary *library) {

    // Check if the library is empty.
    if(library->num_albums == 0) {
        printf("Sorry, the music library is empty. There are no albums to search.\n");
        return;
    }

    // Get the title of the album to be searched from the user.
    char album_title[100];
    printf("\nEnter the title of the album to be searched: ");
    scanf(" %[^\n]", album_title);

    // Search for the album in the library and display its details if found.
    int index = -1;
    for(int i = 0; i < library->num_albums; i++) {
        if(strcmp(library->albums[i].album_title, album_title) == 0) {
            index = i;
            break;
        }
    }
    if(index == -1) {
        printf("Sorry, the album with the title '%s' was not found in the music library.\n", album_title);
    } else {
        Album album = library->albums[index];
        printf("\nTitle: %s\n", album.album_title);
        printf("Artist: %s\n", album.artist_name);
        printf("Release Year: %d\n", album.release_year);
        printf("Genre: %s\n", album.genre);
        printf("Number of songs: %d\n", album.num_songs);
        printf("Songs: \n");
        for(int i = 0; i < album.num_songs; i++) {
            printf("%d. %s\n", i + 1, album.songs[i]);
        }
    }
}

// Function to display the entire music library.
void display_library(MusicLibrary *library) {

    // Check if the library is empty.
    if(library->num_albums == 0) {
        printf("Sorry, the music library is empty. There are no albums to display.\n");
        return;
    }

    // Print the details of each album in the library.
    printf("\n--- Music Library ---\n");
    for(int i = 0; i < library->num_albums; i++) {
        Album album = library->albums[i];
        printf("\nTitle: %s\n", album.album_title);
        printf("Artist: %s\n", album.artist_name);
        printf("Release Year: %d\n", album.release_year);
        printf("Genre: %s\n", album.genre);
        printf("Number of songs: %d\n", album.num_songs);
        printf("Songs: \n");
        for(int j = 0; j < album.num_songs; j++) {
            printf("%d. %s\n", j + 1, album.songs[j]);
        }
    }
}