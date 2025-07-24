//FormAI DATASET v1.0 Category: Music Library Management System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALBUMS 10
#define MAX_TITLE_LENGTH 50
#define MAX_ARTIST_LENGTH 30

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
} Album;

typedef struct {
    Album albums[MAX_ALBUMS];
    int numAlbums;
} Library;

void addAlbum(Library *library, char *title, char *artist) {
    Album newAlbum = {title, artist};
    if (library->numAlbums < MAX_ALBUMS) {
        library->albums[library->numAlbums] = newAlbum;
        library->numAlbums++;
        printf("Added \"%s\" by %s to the library.\n", title, artist);
    } else {
        printf("Library is full. Cannot add \"%s\" by %s.\n", title, artist);
    }
}

void removeAlbum(Library *library, char *title) {
    for (int i = 0; i < library->numAlbums; i++) {
        if (strcmp(library->albums[i].title, title) == 0) {
            for (int j = i; j < library->numAlbums - 1; j++) {
                library->albums[j] = library->albums[j+1];
            }
            library->numAlbums--;
            printf("Removed \"%s\" from the library.\n", title);
            return;
        }
    }
    printf("Could not find \"%s\" in the library.\n", title);
}

void displayLibrary(Library *library) {
    printf("----- Current Library -----\n");
    for (int i = 0; i < library->numAlbums; i++) {
        printf("%s by %s\n", library->albums[i].title, library->albums[i].artist);
    }
    printf("---------------------------\n");
}

int main() {
    Library library = {0};
    char input[50];
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    
    printf("Welcome to the Music Library Management System!\n");
    printf("Enter \"add\" to add an album, \"remove\" to remove an album, or \"display\" to display the current library.\n");
    printf("Enter \"quit\" to exit the program.\n");
    
    while (1) {
        printf("Enter a command: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0; // remove trailing newline
        
        if (strcmp(input, "quit") == 0) {
            printf("Exiting program.\n");
            break;
        } else if (strcmp(input, "add") == 0) {
            printf("Enter the title of the album: ");
            fgets(title, sizeof(title), stdin);
            title[strcspn(title, "\n")] = 0; // remove trailing newline
            printf("Enter the artist of the album: ");
            fgets(artist, sizeof(artist), stdin);
            artist[strcspn(artist, "\n")] = 0; // remove trailing newline
            addAlbum(&library, title, artist);
        } else if (strcmp(input, "remove") == 0) {
            printf("Enter the title of the album to remove: ");
            fgets(title, sizeof(title), stdin);
            title[strcspn(title, "\n")] = 0; // remove trailing newline
            removeAlbum(&library, title);
        } else if (strcmp(input, "display") == 0) {
            displayLibrary(&library);
        } else {
            printf("Invalid command. Try again.\n");
        }
    }
    
    return 0;
}