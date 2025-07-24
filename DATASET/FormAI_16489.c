//FormAI DATASET v1.0 Category: Music Library Management System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 1000

typedef struct {
    char title[100];
    char artist[50];
    char album[50];
    int year;
    char genre[20];
} Song;

typedef struct {
    Song songs[MAX_SONGS];
    int count;
} Library;

void add_song(Library *library, Song song);
void display_songs(Library *library);
void search_songs(Library *library, char searchQuery[]);
void remove_song(Library *library, int index);

int main() {
    Library library = { .count = 0 };
    int choice, year, index = 0;
    Song song;
    char searchQuery[100];
    do {
        printf("\n\n");
        printf("*************************************************\n");
        printf("* Welcome to the C Library Management System!  *\n");
        printf("*-----------------------------------------------*\n");
        printf("* 1. Add a song to the library                   *\n");
        printf("* 2. Display all songs in the library            *\n");
        printf("* 3. Search for a song by title or artist        *\n");
        printf("* 4. Remove a song from the library              *\n");
        printf("* 5. Exit the program                            *\n");
        printf("*************************************************\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                printf("Enter song title : ");
                scanf(" %[^\n]s", song.title);
                printf("Enter song artist : ");
                scanf(" %[^\n]s", song.artist);
                printf("Enter song album : ");
                scanf(" %[^\n]s", song.album);
                printf("Enter song year : ");
                scanf("%d", &song.year);
                printf("Enter song genre : ");
                scanf(" %[^\n]s", song.genre);
                add_song(&library, song);
                printf("\nSong added successfully!\n");
                break;

            case 2:
                display_songs(&library);
                break;

            case 3:
                printf("Enter search query : ");
                scanf(" %[^\n]s", searchQuery);
                search_songs(&library, searchQuery);
                break;

            case 4:
                printf("Enter song index : ");
                scanf("%d", &index);
                remove_song(&library, index);
                break;

            case 5:
                printf("Exiting...");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }

    } while (1);

    return 0;
}

void add_song(Library *library, Song song) {
    library->songs[library->count++] = song;
}

void display_songs(Library *library) {
    printf("Title\t\t\tArtist\t\t\tAlbum\t\t\tYear\t\tGenre\n");
    printf("----\t\t\t------\t\t\t-----\t\t\t----\t\t-----\n");
    for (int i = 0; i < library->count; i++) {
        Song song = library->songs[i];
        printf("%-27s%-27s%-27s%-9d%-20s\n", song.title, song.artist, song.album, song.year, song.genre);
    }
}

void search_songs(Library *library, char searchQuery[]) {
    printf("Title\t\t\tArtist\t\t\tAlbum\t\t\tYear\t\tGenre\n");
    printf("----\t\t\t------\t\t\t-----\t\t\t----\t\t-----\n");
    for (int i = 0; i < library->count; i++) {
        Song song = library->songs[i];
        if (strstr(song.title, searchQuery) != NULL || strstr(song.artist, searchQuery) != NULL) {
            printf("%-27s%-27s%-27s%-9d%-20s\n", song.title, song.artist, song.album, song.year, song.genre);
        }
    }
}

void remove_song(Library *library, int index) {
    if (index >= library->count || index < 0) {
        printf("Invalid index.\n");
    } else {
        for (int i = index; i < library->count - 1; i++) {
            library->songs[i] = library->songs[i + 1];
        }
        library->count--;
        printf("Song removed successfully!\n");
    }
}