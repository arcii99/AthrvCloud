//FormAI DATASET v1.0 Category: Music Library Management System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 256
#define MAX_ARTIST_LENGTH 128
#define MAX_ALBUM_LENGTH 128
#define MAX_SONG_LENGTH 256
#define MAX_LIBRARY_SIZE 1000

typedef struct Song {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    char album[MAX_ALBUM_LENGTH];
    int year;
    float duration;
} Song;

typedef struct MusicLibrary {
    Song songs[MAX_LIBRARY_SIZE];
    int size;
} MusicLibrary;

int main() {
    MusicLibrary library;
    library.size = 0;

    // Add some example songs to the library
    Song song1 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 6.07};
    Song song2 = {"Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 8.02};
    Song song3 = {"Hotel California", "Eagles", "Hotel California", 1976, 6.30};
    Song song4 = {"Yesterday", "The Beatles", "Help!", 1965, 2.05};

    library.songs[library.size++] = song1;
    library.songs[library.size++] = song2;
    library.songs[library.size++] = song3;
    library.songs[library.size++] = song4;

    int choice;
    do {
        printf("Welcome to the Music Library Management System!\n");
        printf("1. View all songs\n");
        printf("2. Add a new song\n");
        printf("3. Search for a song\n");
        printf("4. Remove a song\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("All songs in the library:\n");
                for (int i = 0; i < library.size; i++) {
                    printf("%d. %s - %s (%s, %d)\n", i+1, library.songs[i].title, library.songs[i].artist,
                            library.songs[i].album, library.songs[i].year);
                }
                printf("\n");
                break;

            case 2:
                if (library.size == MAX_LIBRARY_SIZE) {
                    printf("The library is full and cannot accept more songs.\n\n");
                    break;
                }
                printf("Enter the title of the new song: ");
                scanf(" %[^\n]s", library.songs[library.size].title);
                printf("Enter the artist of the new song: ");
                scanf(" %[^\n]s", library.songs[library.size].artist);
                printf("Enter the album of the new song: ");
                scanf(" %[^\n]s", library.songs[library.size].album);
                printf("Enter the year of the new song: ");
                scanf("%d", &library.songs[library.size].year);
                printf("Enter the duration in minutes of the new song: ");
                scanf("%f", &library.songs[library.size].duration);
                library.size++;
                printf("Song added successfully!\n\n");
                break;

            case 3:
                printf("Enter part of the title, artist or album to search: ");
                char search[MAX_SONG_LENGTH];
                scanf(" %[^\n]s", search);
                int found = 0;
                for (int i = 0; i < library.size; i++) {
                    if (strstr(library.songs[i].title, search) != NULL ||
                            strstr(library.songs[i].artist, search) != NULL ||
                            strstr(library.songs[i].album, search) != NULL) {
                        printf("%d. %s - %s (%s, %d)\n", i+1, library.songs[i].title, library.songs[i].artist,
                                library.songs[i].album, library.songs[i].year);
                        found = 1;
                    }
                }
                if (!found) {
                    printf("No songs matching that search term were found.\n");
                }
                printf("\n");
                break;

            case 4:
                printf("Enter the number of the song to remove: ");
                int num;
                scanf("%d", &num);
                if (num < 1 || num > library.size) {
                    printf("Invalid song number.\n\n");
                    break;
                }
                printf("Removing song: %s - %s (%s, %d)\n", library.songs[num-1].title, library.songs[num-1].artist,
                        library.songs[num-1].album, library.songs[num-1].year);
                for (int i = num-1; i < library.size-1; i++) {
                    library.songs[i] = library.songs[i+1];
                }
                library.size--;
                printf("Song removed successfully!\n\n");
                break;

            case 5:
                printf("Exiting the Music Library Management System. Thank you for using!\n");
                break;

            default:
                printf("Invalid choice. Please choose a valid option.\n\n");
                break;
        }
    } while (choice != 5);

    return 0;
}