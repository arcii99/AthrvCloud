//FormAI DATASET v1.0 Category: Music Library Management System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 1000
#define MAX_TITLE_LENGTH 50
#define MAX_ARTIST_LENGTH 50

struct Song {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    int year;
    float length;
};

struct MusicLibrary {
    struct Song songs[MAX_SONGS];
    int num_songs;
};

void add_song(struct MusicLibrary *library) {
    if (library->num_songs < MAX_SONGS) {
        printf("Enter song title: ");
        scanf("%s", library->songs[library->num_songs].title);
        printf("Enter artist name: ");
        scanf("%s", library->songs[library->num_songs].artist);
        printf("Enter year: ");
        scanf("%d", &library->songs[library->num_songs].year);
        printf("Enter length in minutes: ");
        scanf("%f", &library->songs[library->num_songs].length);
        library->num_songs++;
    } else {
        printf("Music library is full.\n");
    }
}

void print_song(struct Song song) {
    printf("%s by %s (%d) - %.2f minutes\n", song.title, song.artist, song.year, song.length);
}

void display_library(struct MusicLibrary library) {
    for (int i = 0; i < library.num_songs; i++) {
        print_song(library.songs[i]);
    }
}

void search_library(struct MusicLibrary library, char *search_term) {
    int found_songs = 0;
    for (int i = 0; i < library.num_songs; i++) {
        if (strstr(library.songs[i].title, search_term) != NULL || strstr(library.songs[i].artist, search_term) != NULL) {
            print_song(library.songs[i]);
            found_songs++;
        }
    }
    if (found_songs == 0) {
        printf("No songs found.\n");
    }
}

int main() {
    struct MusicLibrary library;
    library.num_songs = 0;
    int choice;

    printf("Welcome to the Music Library Management System.\n");

    do {
        printf("\nMenu:\n");
        printf("1. Add song\n");
        printf("2. Display library\n");
        printf("3. Search library\n");
        printf("4. Quit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_song(&library);
                break;
            case 2:
                display_library(library);
                break;
            case 3:
                char search_term[MAX_TITLE_LENGTH];
                printf("Enter search term: ");
                scanf("%s", search_term);
                search_library(library, search_term);
                break;
            default:
                printf("Goodbye!\n");
        }
    } while (choice != 4);

    return 0;
}