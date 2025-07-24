//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* C Music Library Management System */

#define MAX_SONGS 1000
#define MAX_TITLE_LENGTH 50
#define MAX_ARTIST_LENGTH 50

/* Define the Song struct */
typedef struct {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    int year;
    float length;
} Song;

/* Define the MusicLibrary struct */
typedef struct {
    Song songs[MAX_SONGS];
    int num_songs;
} MusicLibrary;

/* Function to add a new song to the library */
void add_song(MusicLibrary* library, char* title, char* artist, int year, float length) {
    if (library->num_songs >= MAX_SONGS) {
        printf("Sorry, the library is already full.\n");
        return;
    }

    strncpy(library->songs[library->num_songs].title, title, MAX_TITLE_LENGTH);
    strncpy(library->songs[library->num_songs].artist, artist, MAX_ARTIST_LENGTH);
    library->songs[library->num_songs].year = year;
    library->songs[library->num_songs].length = length;

    library->num_songs++;

    printf("Song added successfully.\n");
}

/* Function to print all the songs in the library */
void print_songs(MusicLibrary* library) {
    printf("Music Library:\n");

    for (int i = 0; i < library->num_songs; i++) {
        printf("%s - %s (%d) - %.2f minutes\n", library->songs[i].artist, library->songs[i].title,
                library->songs[i].year, library->songs[i].length);
    }
}

/* Function to search for songs by title */
void search_by_title(MusicLibrary* library, char* title) {
    printf("Songs matching title '%s':\n", title);

    for (int i = 0; i < library->num_songs; i++) {
        if (strcmp(library->songs[i].title, title) == 0) {
            printf("%s - %s (%d) - %.2f minutes\n", library->songs[i].artist, library->songs[i].title,
                    library->songs[i].year, library->songs[i].length);
        }
    }
}

/* Function to search for songs by artist */
void search_by_artist(MusicLibrary* library, char* artist) {
    printf("Songs by artist '%s':\n", artist);

    for (int i = 0; i < library->num_songs; i++) {
        if (strcmp(library->songs[i].artist, artist) == 0) {
            printf("%s - %s (%d) - %.2f minutes\n", library->songs[i].artist, library->songs[i].title,
                    library->songs[i].year, library->songs[i].length);
        }
    }
}

int main() {
    MusicLibrary library = { .num_songs = 0 };

    add_song(&library, "Stairway to Heaven", "Led Zeppelin", 1971, 8.02);
    add_song(&library, "Bohemian Rhapsody", "Queen", 1975, 5.55);
    add_song(&library, "Hotel California", "Eagles", 1976, 6.31);

    print_songs(&library);

    search_by_title(&library, "Hotel California");

    search_by_artist(&library, "Queen");

    return 0;
}