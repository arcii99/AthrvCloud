//FormAI DATASET v1.0 Category: Music Library Management System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defining a struct for the music library that can hold up to 100 songs
struct music_library {
    char song_name[50];
    char artist[50];
    char album[50];
    int year;
};

int main() {
    int choice, i, j, year;
    char song_name[50], artist[50], album[50];

    // creating an array of type struct music_library that can hold up to 100 songs
    struct music_library library[100];

   // initialize the music library with default values
    for (i = 0; i < 100; i++) {
        strcpy(library[i].song_name, "Unknown");
        strcpy(library[i].artist, "Unknown");
        strcpy(library[i].album, "Unknown");
        library[i].year = 0;
    }

    // program menu
    do {
        printf("\n Music Library Management System\n");
        printf("\n 1. Add a new song to the library");
        printf("\n 2. View the music library");
        printf("\n 3. Update a song information");
        printf("\n 4. Delete a song from the library");
        printf("\n 5. Search for a song in the library");
        printf("\n 6. Exit");
        printf("\n\n Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // adding a new song to the music library
                printf("\n Enter the song name: ");
                scanf("%s", &song_name);
                printf("\n Enter the artist name: ");
                scanf("%s", &artist);
                printf("\n Enter the album name: ");
                scanf("%s", &album);
                printf("\n Enter the year: ");
                scanf("%d", &year);

                for (i = 0; i < 100; i++) {
                    if (strcmp(library[i].song_name, "Unknown") == 0) {
                        strcpy(library[i].song_name, song_name);
                        strcpy(library[i].artist, artist);
                        strcpy(library[i].album, album);
                        library[i].year = year;
                        break;
                    }
                }

                if (i == 100)
                    printf("\n Music library is full! Please delete a song before adding a new one.\n");

                break;

            case 2:
                // viewing the music library
                printf("\n Music Library:\n");
                printf("\n %-30s %-20s %-20s %s\n", "Song Name", "Artist", "Album", "Year");

                for (i = 0; i < 100; i++) {
                    if (strcmp(library[i].song_name, "Unknown") != 0) {
                        printf("\n %-30s %-20s %-20s %d\n", library[i].song_name, library[i].artist,
                            library[i].album, library[i].year);
                    }
                }

                break;

            case 3:
                // updating a song information
                printf("\n Enter the song name to update: ");
                scanf("%s", &song_name);

                for (i = 0; i < 100; i++) {
                    if (strcmp(library[i].song_name, song_name) == 0) {
                        printf("\n Enter the new song name: ");
                        scanf("%s", &song_name);
                        printf("\n Enter the new artist name: ");
                        scanf("%s", &artist);
                        printf("\n Enter the new album name: ");
                        scanf("%s", &album);
                        printf("\n Enter the new year: ");
                        scanf("%d", &year);

                        strcpy(library[i].song_name, song_name);
                        strcpy(library[i].artist, artist);
                        strcpy(library[i].album, album);
                        library[i].year = year;

                        printf("\n Song information updated!\n");
                        break;
                    }
                }

                if (i == 100)
                    printf("\n Song not found!\n");

                break;

            case 4:
                // deleting a song from the music library
                printf("\n Enter the song name to delete: ");
                scanf("%s", &song_name);

                for (i = 0; i < 100; i++) {
                    if (strcmp(library[i].song_name, song_name) == 0) {
                        strcpy(library[i].song_name, "Unknown");
                        strcpy(library[i].artist, "Unknown");
                        strcpy(library[i].album, "Unknown");
                        library[i].year = 0;

                        printf("\n Song deleted from the library!\n");
                        break;
                    }
                }

                if (i == 100)
                    printf("\n Song not found!\n");

                break;

            case 5:
                // searching for a song in the music library
                printf("\n Enter the song name to search: ");
                scanf("%s", &song_name);

                for (i = 0; i < 100; i++) {
                    if (strcmp(library[i].song_name, song_name) == 0) {
                        printf("\n Song found at index %d:\n", i);
                        printf("\n %-30s %-20s %-20s %s\n", "Song Name", "Artist", "Album", "Year");
                        printf("\n %-30s %-20s %-20s %d\n", library[i].song_name, library[i].artist,
                            library[i].album, library[i].year);
                        break;
                    }
                }

                if (i == 100)
                    printf("\n Song not found!\n");

                break;

            case 6:
                // exit the program
                printf("\n Goodbye!\n");
                break;

            default:
                printf("\n Invalid choice! Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}