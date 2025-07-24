//FormAI DATASET v1.0 Category: Music Library Management System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for songs
typedef struct {
    char title[50];
    char artist[50];
    char album[50];
    int year;
    float length;
} Song;

// Declare the function for adding a song to the library
void add_song(Song *songs, int *num_songs);

int main() {
    // Allocate memory for the song library
    Song *library = malloc(sizeof(Song) * 100);
    int num_songs = 0;

    // Loop through menu options until the user chooses to exit
    int choice;
    while(1) {
        printf("1. Add a song\n2. View all songs\n3. Search for a song\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_song(library, &num_songs);
                break;
            case 2:
                // Loop through all songs in the library and print their information
                printf("Title\tArtist\tAlbum\tYear\tLength\n");
                for(int i = 0; i < num_songs; i++) {
                    printf("%s\t%s\t%s\t%d\t%.2f\n", library[i].title, library[i].artist, library[i].album, library[i].year, library[i].length);
                }
                break;
            case 3:
                // Search for a song by title or artist
                char search[50];
                printf("Enter a song title or artist to search for: ");
                scanf("%s", search);
                printf("Results:\nTitle\tArtist\tAlbum\tYear\tLength\n");
                for(int i = 0; i < num_songs; i++) {
                    if(strcmp(search, library[i].title) == 0 || strcmp(search, library[i].artist) == 0) {
                        printf("%s\t%s\t%s\t%d\t%.2f\n", library[i].title, library[i].artist, library[i].album, library[i].year, library[i].length);
                    }
                }
                break;
            case 4:
                // Exit the program
                free(library);
                printf("Goodbye\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

void add_song(Song *songs, int *num_songs) {
    // Prompt the user for the song information
    printf("Enter the song title: ");
    scanf("%s", songs[*num_songs].title);
    printf("Enter the song artist: ");
    scanf("%s", songs[*num_songs].artist);
    printf("Enter the song album: ");
    scanf("%s", songs[*num_songs].album);
    printf("Enter the song year: ");
    scanf("%d", &songs[*num_songs].year);
    printf("Enter the song length in minutes: ");
    scanf("%f", &songs[*num_songs].length);

    // Increment the number of songs in the library
    (*num_songs)++;

    printf("Song added successfully\n");
}