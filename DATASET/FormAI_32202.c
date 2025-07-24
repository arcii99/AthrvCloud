//FormAI DATASET v1.0 Category: Music Library Management System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for music albums
typedef struct {
    char title[50];
    char artist[50];
    int year;
    char genre[20];
} Album;

// Define function to add a new album
void addAlbum(Album* library, int* numAlbums) {
    Album newAlbum;
    printf("Enter the album title: ");
    fgets(newAlbum.title, 50, stdin);
    printf("Enter the artist: ");
    fgets(newAlbum.artist, 50, stdin);
    printf("Enter the year: ");
    scanf("%d", &newAlbum.year);
    printf("Enter the genre: ");
    fgets(newAlbum.genre, 20, stdin);

    library[*numAlbums] = newAlbum;
    (*numAlbums)++;
}

// Define function to search for an album by title
void searchByTitle(Album* library, int numAlbums) {
    char searchTitle[50];
    printf("Enter the album title to search for: ");
    fgets(searchTitle, 50, stdin);

    for(int i = 0; i < numAlbums; i++) {
        if(strcmp(library[i].title, searchTitle) == 0) {
            printf("Album found! Artist: %s, Year: %d, Genre: %s\n", library[i].artist, library[i].year, library[i].genre);
            return;
        }
    }

    printf("Album not found.\n");
}

// Define function to print all albums in library
void printLibrary(Album* library, int numAlbums) {
    for(int i = 0; i < numAlbums; i++) {
        printf("Title: %s, Artist: %s, Year: %d, Genre: %s\n", library[i].title, library[i].artist, library[i].year, library[i].genre);
    }
}

int main() {
    Album library[100]; // Create array to hold up to 100 albums
    int numAlbums = 0; // Initialize number of albums to 0

    printf("Welcome to the Music Library Management System!\n");

    while(1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a new album\n");
        printf("2. Search for an album by title\n");
        printf("3. Print the entire library\n");
        printf("4. Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Clear input buffer before reading in album info
        while(getchar() != '\n');

        switch(choice) {
            case 1:
                addAlbum(library, &numAlbums);
                break;
            case 2:
                searchByTitle(library, numAlbums);
                break;
            case 3:
                printLibrary(library, numAlbums);
                break;
            case 4:
                printf("Thank you for using the Music Library Management System!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}