//FormAI DATASET v1.0 Category: Music Library Management System ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Song {
    char title[30];
    char artist[30];
    int year;
    char genre[30];
};

int main() {
    int choice;
    int num_songs = 0;
    struct Song *library = NULL;

    while (1) {
        printf("C Music Library Management System\n");
        printf("---------------------------\n");
        printf("1. Add a new song to the library\n");
        printf("2. View all the songs in the library\n");
        printf("3. Search for a song in the library\n");
        printf("4. Delete a song from the library\n");
        printf("5. Exit the program\n");
        printf("---------------------------\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                num_songs++;
                library = realloc(library, sizeof(struct Song) * num_songs);
                printf("Enter song title: ");
                scanf("%s", library[num_songs-1].title);
                printf("Enter artist name: ");
                scanf("%s", library[num_songs-1].artist);
                printf("Enter year released: ");
                scanf("%d", &library[num_songs-1].year);
                printf("Enter genre: ");
                scanf("%s", library[num_songs-1].genre);
                printf("Song added to library!\n\n");
                break;

            case 2:
                printf("All songs in the library:\n");
                for (int i = 0; i < num_songs; i++) {
                    printf("%d. %s\n", i+1, library[i].title);
                }
                printf("\n");
                break;

            case 3:
                char search_title[30];
                printf("Enter song title to search for: ");
                scanf("%s", search_title);
                for (int i = 0; i < num_songs; i++) {
                    if (strcmp(library[i].title, search_title) == 0) {
                        printf("Song found in library:\n");
                        printf("Title: %s\n", library[i].title);
                        printf("Artist: %s\n", library[i].artist);
                        printf("Year released: %d\n", library[i].year);
                        printf("Genre: %s\n\n", library[i].genre);
                        break;
                    }
                    if (i == num_songs - 1) {
                        printf("Song not found in library.\n\n");
                    }
                }
                break;

            case 4:
                char delete_title[30];
                printf("Enter song title to delete from library: ");
                scanf("%s", delete_title);
                for (int i = 0; i < num_songs; i++) {
                    if (strcmp(library[i].title, delete_title) == 0) {
                        // Shift all songs after deleted song back by one position
                        for (int j = i; j < num_songs - 1; j++) {
                            library[j] = library[j+1];
                        }
                        num_songs--;
                        // Resize memory allocation for library array
                        library = realloc(library, sizeof(struct Song) * num_songs);
                        printf("Song deleted from library.\n\n");
                        break;
                    }
                    if (i == num_songs - 1) {
                        printf("Song not found in library.\n\n");
                    }
                }
                break;

            case 5:
                printf("Exiting program.");
                free(library);
                exit(0);
                break;

            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    }
    return 0;
}