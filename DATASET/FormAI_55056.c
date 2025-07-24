//FormAI DATASET v1.0 Category: Music Library Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALBUMS 50
#define MAX_SONGS 2000

typedef struct {
    char title[50];
    char artist[50];
    int year;
    char genre[50];
    int num_songs;
    char songs[MAX_SONGS][50];
} Album;

Album albums[MAX_ALBUMS];
int num_albums = 0;

void add_album() {
    if (num_albums >= MAX_ALBUMS) {
        printf("Maximum number of albums reached.\n");
        return;
    }

    Album album;

    printf("Enter album title: ");
    fgets(album.title, 50, stdin);
    printf("Enter artist name: ");
    fgets(album.artist, 50, stdin);
    printf("Enter release year: ");
    scanf("%d", &album.year);
    getchar(); // consume newline character
    printf("Enter genre: ");
    fgets(album.genre, 50, stdin);
    printf("Enter number of songs: ");
    scanf("%d", &album.num_songs);
    getchar(); // consume newline character

    printf("Enter songs (one per line):\n");
    for (int i = 0; i < album.num_songs; i++) {
        fgets(album.songs[i], 50, stdin);
    }

    albums[num_albums++] = album;

    printf("Album added successfully!\n");
}

void display_album(Album album) {
    printf("Title: %s", album.title);
    printf("Artist: %s", album.artist);
    printf("Year: %d\n", album.year);
    printf("Genre: %s", album.genre);
    printf("Songs:\n");
    for (int i = 0; i < album.num_songs; i++) {
        printf("  %s", album.songs[i]);
    }
}

void search_album() {
    char query[50];
    printf("Enter search query: ");
    fgets(query, 50, stdin);

    int matches = 0;
    for (int i = 0; i < num_albums; i++) {
        if (strstr(albums[i].title, query) != NULL ||
            strstr(albums[i].artist, query) != NULL ||
            strstr(albums[i].genre, query) != NULL) {
            display_album(albums[i]);
            matches++;
        }
    }

    if (matches == 0) {
        printf("No matches found.\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Add album\n");
        printf("2. Search album\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline character

        switch (choice) {
            case 1:
                add_album();
                break;
            case 2:
                search_album();
                break;
            case 3:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}