//FormAI DATASET v1.0 Category: Music Library Management System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to store music library data
typedef struct {
    char title[50];
    char artist[50];
    int year;
} Music;

int main() {
    int num_songs;
    printf("Enter the number of songs in your music library: ");
    scanf("%d", &num_songs);
    getchar(); // Consume the newline character

    // Allocate memory for the music library array
    Music* music_library = (Music*) malloc(num_songs * sizeof(Music));

    // Get user input for each song in the library
    for (int i = 0; i < num_songs; i++) {
        printf("Enter the title of song %d: ", i + 1);
        fgets(music_library[i].title, 50, stdin);
        music_library[i].title[strcspn(music_library[i].title, "\n")] = '\0'; // Remove the newline character
        printf("Enter the artist of song %d: ", i + 1);
        fgets(music_library[i].artist, 50, stdin);
        music_library[i].artist[strcspn(music_library[i].artist, "\n")] = '\0'; // Remove the newline character
        printf("Enter the year of song %d: ", i + 1);
        scanf("%d", &music_library[i].year);
        getchar(); // Consume the newline character
    }

    // Print out the music library
    printf("\n--- Music Library ---\n\n");
    for (int i = 0; i < num_songs; i++) {
        printf("Song %d:\n", i + 1);
        printf("Title: %s\n", music_library[i].title);
        printf("Artist: %s\n", music_library[i].artist);
        printf("Year: %d\n\n", music_library[i].year);
    }

    // Free the allocated memory
    free(music_library);

    return 0;
}