//FormAI DATASET v1.0 Category: Music Library Management System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define MAX_SIZE to be the maximum number of songs that can be stored in our library
#define MAX_SIZE 100

// Define the struct Song to represent a single song in our library
typedef struct Song
{
    char title[50];
    char artist[50];
    int year;
    char genre[20];
} Song;

// Define the struct Library to represent our entire music library
typedef struct Library
{
    Song songs[MAX_SIZE];
    int num_songs;
} Library;

// Function prototypes
void initialize_library(Library *lib);
void add_song(Library *lib, Song new_song);
void remove_song(Library *lib, char *title);
void search_library(Library *lib, char *query);
void display_library(Library *lib);

int main()
{
    // Declare our library and initialize it
    Library my_library;
    initialize_library(&my_library);

    // Add some test songs to our library
    Song test_song1 = {"Bohemian Rhapsody", "Queen", 1975, "Rock"};
    add_song(&my_library, test_song1);
    Song test_song2 = {"Smooth", "Santana ft. Rob Thomas", 1999, "Latin Rock"};
    add_song(&my_library, test_song2);
    Song test_song3 = {"Lose Yourself", "Eminem", 2002, "Hip Hop"};
    add_song(&my_library, test_song3);

    // Display our library as it currently stands
    display_library(&my_library);

    // Let's search for songs that were released in the 90s
    printf("\nSearching for songs released in the 90s:\n");
    search_library(&my_library, "90s");

    // Now we'll remove "Smooth" from our library
    printf("\nRemoving 'Smooth' from the library...\n");
    remove_song(&my_library, "Smooth");

    // Display our library again to confirm that "Smooth" was removed
    display_library(&my_library);

    return 0;
}

// Initializes a new Library struct, setting num_songs to 0
void initialize_library(Library *lib)
{
    lib->num_songs = 0;
}

// Adds a new song to the Library
void add_song(Library *lib, Song new_song)
{
    if (lib->num_songs >= MAX_SIZE)
    {
        printf("Error: library is full\n");
        return;
    }
    lib->songs[lib->num_songs] = new_song;
    lib->num_songs++;
}

// Removes a song from the Library by title
void remove_song(Library *lib, char *title)
{
    int found_song_index = -1;
    for (int i = 0; i < lib->num_songs; i++)
    {
        if (strcmp(lib->songs[i].title, title) == 0)
        {
            found_song_index = i;
            break;
        }
    }
    if (found_song_index == -1)
    {
        printf("Error: song not found in library\n");
    }
    else
    {
        for (int i = found_song_index; i < lib->num_songs - 1; i++)
        {
            lib->songs[i] = lib->songs[i+1];
        }
        lib->num_songs--;
        printf("Song '%s' removed successfully\n", title);
    }
}

// Searches the library for songs that match a given query string
void search_library(Library *lib, char *query)
{
    printf("Search results:\n");
    for (int i = 0; i < lib->num_songs; i++)
    {
        if (strstr(lib->songs[i].title, query) != NULL ||
            strstr(lib->songs[i].artist, query) != NULL ||
            strstr(lib->songs[i].genre, query) != NULL)
        {
            printf("%s by %s (%d, %s)\n", lib->songs[i].title, lib->songs[i].artist, lib->songs[i].year, lib->songs[i].genre);
        }
    }
}

// Displays all the songs in the Library
void display_library(Library *lib)
{
    printf("Current library contents:\n");
    for (int i = 0; i < lib->num_songs; i++)
    {
        printf("%s by %s (%d, %s)\n", lib->songs[i].title, lib->songs[i].artist, lib->songs[i].year, lib->songs[i].genre);
    }
}