//FormAI DATASET v1.0 Category: Music Library Management System ; Style: futuristic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LIBRARY_SIZE 1000
#define MAX_ALBUMS_PER_ARTIST 10

typedef struct album {
    char name[50];
    char artist[50];
    int year;
    char genre[50];
    int num_tracks;
    int rating;
} Album;

typedef struct artist {
    char name[50];
    int num_albums;
    Album albums[MAX_ALBUMS_PER_ARTIST];
} Artist;

typedef struct library {
    int num_artists;
    Artist artists[MAX_LIBRARY_SIZE];
} Library;

void clear_screen() {
    printf("\033[2J\033[1;1H"); // ANSI escape code to clear the screen
}

int main() {
    Library library;
    library.num_artists = 0;

    clear_screen();
    printf("Welcome to the Music Library Management System!\n\n");

    while (1) {
        // Show options menu
        printf("[1] Add artist\n");
        printf("[2] Add album\n");
        printf("[3] List artists\n");
        printf("[4] Search library\n");
        printf("[5] Exit\n\n");
        printf("Enter your choice: ");

        // Get user input
        int choice;
        scanf("%d", &choice);
        getchar(); // flush newline from input buffer

        switch (choice) {
            case 1:
                // Add new artist
                clear_screen();
                printf("Add artist\n\n");

                if (library.num_artists >= MAX_LIBRARY_SIZE) {
                    printf("Error: Music library is full.");
                    break;
                }

                printf("Enter artist name: ");
                fgets(library.artists[library.num_artists].name, 50, stdin);
                library.artists[library.num_artists].name[strcspn(library.artists[library.num_artists].name, "\n")] = 0; // remove trailing newline
                library.artists[library.num_artists].num_albums = 0;

                printf("\nArtist added!\n\n");
                library.num_artists++;
                break;

            case 2:
                // Add new album
                clear_screen();
                printf("Add album\n\n");

                if (library.num_artists == 0) {
                    printf("Error: No artists in music library.\n");
                    break;
                }

                printf("Enter album name: ");
                char album_name[50];
                fgets(album_name, 50, stdin);
                album_name[strcspn(album_name, "\n")] = 0;

                printf("Enter artist name: ");
                char artist_name[50];
                fgets(artist_name, 50, stdin);
                artist_name[strcspn(artist_name, "\n")] = 0;

                int artist_index = -1;
                for (int i = 0; i < library.num_artists; i++) {
                    if (strcmp(library.artists[i].name, artist_name) == 0) {
                        artist_index = i;
                        break;
                    }
                }

                if (artist_index == -1) {
                    printf("Error: Artist \"%s\" not found in music library.\n", artist_name);
                    break;
                }

                if (library.artists[artist_index].num_albums >= MAX_ALBUMS_PER_ARTIST) {
                    printf("Error: Artist \"%s\" has reached the maximum number of albums (%d).\n", library.artists[artist_index].name, MAX_ALBUMS_PER_ARTIST);
                    break;
                }

                printf("Enter year: ");
                int year;
                scanf("%d", &year);
                getchar(); // flush newline from input buffer

                printf("Enter genre: ");
                char genre[50];
                fgets(genre, 50, stdin);
                genre[strcspn(genre, "\n")] = 0;

                printf("Enter number of tracks: ");
                int num_tracks;
                scanf("%d", &num_tracks);
                getchar(); // flush newline from input buffer

                printf("Enter rating (out of 10): ");
                int rating;
                scanf("%d", &rating);
                getchar(); // flush newline from input buffer

                // Add album to artist's collection
                strcpy(library.artists[artist_index].albums[library.artists[artist_index].num_albums].name, album_name);
                strcpy(library.artists[artist_index].albums[library.artists[artist_index].num_albums].artist, artist_name);
                library.artists[artist_index].albums[library.artists[artist_index].num_albums].year = year;
                strcpy(library.artists[artist_index].albums[library.artists[artist_index].num_albums].genre, genre);
                library.artists[artist_index].albums[library.artists[artist_index].num_albums].num_tracks = num_tracks;
                library.artists[artist_index].albums[library.artists[artist_index].num_albums].rating = rating;
                library.artists[artist_index].num_albums++;

                printf("\nAlbum added!\n\n");
                break;

            case 3:
                // List artists
                clear_screen();
                printf("List artists\n\n");

                if (library.num_artists == 0) {
                    printf("No artists in music library.\n");
                    break;
                }

                for (int i = 0; i < library.num_artists; i++) {
                    printf("%s\n", library.artists[i].name);
                }
                printf("\n");
                break;

            case 4:
                // Search library
                clear_screen();
                printf("Search library\n\n");

                if (library.num_artists == 0) {
                    printf("No artists in music library.\n");
                    break;
                }

                printf("Enter search query: ");
                char search_query[50];
                fgets(search_query, 50, stdin);
                search_query[strcspn(search_query, "\n")] = 0;

                int results_count = 0;
                for (int i = 0; i < library.num_artists; i++) {
                    for (int j = 0; j < library.artists[i].num_albums; j++) {
                        if (strstr(library.artists[i].name, search_query) != NULL || strstr(library.artists[i].albums[j].name, search_query) != NULL) {
                            printf("%s - %s (%d)\n", library.artists[i].name, library.artists[i].albums[j].name, library.artists[i].albums[j].year);
                            results_count++;
                        }
                    }
                }

                if (results_count == 0) {
                    printf("No results found.\n");
                } else {
                    printf("\n");
                }
                break;

            case 5:
                // Exit
                clear_screen();
                printf("Thanks for using the Music Library Management System!\n");
                return 0;

            default:
                // Invalid input
                clear_screen();
                printf("Invalid input. Please try again.\n\n");
        }
    }
}