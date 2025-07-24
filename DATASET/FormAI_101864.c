//FormAI DATASET v1.0 Category: Music Library Management System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_TITLE_LEN 50
#define MAX_ARTIST_LEN 50

typedef struct {
    char title[MAX_TITLE_LEN];
    char artist[MAX_ARTIST_LEN];
    int year;
} Song;

typedef struct {
    Song songs[MAX_SONGS];
    int num_songs;
} Library;

void add_song(Library *library, char *title, char *artist, int year);
void print_library(Library *library);
void search_library(Library *library, char *search);

int main() {
    Library my_library = { .num_songs = 0 };
    
    add_song(&my_library, "Bohemian Rhapsody", "Queen", 1975);
    add_song(&my_library, "Stairway to Heaven", "Led Zeppelin", 1971);
    add_song(&my_library, "Hey Jude", "The Beatles", 1968);

    printf("=== Library ===\n");
    print_library(&my_library);

    char search_title[MAX_TITLE_LEN];
    printf("\nEnter the title of a song to search: ");
    fgets(search_title, MAX_TITLE_LEN, stdin);
    search_title[strcspn(search_title, "\n")] = 0;
    search_library(&my_library, search_title);

    return 0;
}

void add_song(Library *library, char *title, char *artist, int year) {
    if (library->num_songs >= MAX_SONGS) {
        printf("Library is full\n");
        return;
    }
    Song new_song = { .year = year };
    strncpy(new_song.title, title, MAX_TITLE_LEN);
    strncpy(new_song.artist, artist, MAX_ARTIST_LEN);
    library->songs[library->num_songs++] = new_song;
    printf("Added %s by %s to the library.\n", title, artist);
}

void print_library(Library *library) {
    for (int i = 0; i < library->num_songs; i++) {
        printf("%s by %s (%d)\n", library->songs[i].title, 
               library->songs[i].artist, library->songs[i].year);
    }
}

void search_library(Library *library, char *search) {
    for (int i = 0; i < library->num_songs; i++) {
        if (strcmp(library->songs[i].title, search) == 0) {
            printf("%s by %s (%d)\n", library->songs[i].title, 
               library->songs[i].artist, library->songs[i].year);
            return;
        }
    }
    printf("No %s found in the library.\n", search);
}