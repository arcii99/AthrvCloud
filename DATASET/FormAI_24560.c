//FormAI DATASET v1.0 Category: Music Library Management System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_NAME_LENGTH 50
#define MAX_GENRE_LENGTH 20

// This struct represents a single song
typedef struct song {
    char name[MAX_NAME_LENGTH];
    char artist[MAX_NAME_LENGTH];
    char album[MAX_NAME_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    int year;
    float rating;
} song_t;

// This struct represents the entire music library
typedef struct music_library {
    song_t songs[MAX_SONGS];
    int num_songs;
} music_library_t;

// Prints all the songs in the music library
void print_songs(music_library_t* library) {
    printf("\nMusic Library:\n");
    printf("-----------------\n");
    printf("Name\t\tArtist\t\tAlbum\t\tGenre\t\tYear\t\tRating\n");
    printf("-----------------------------------------------------------------\n");
    for (int i = 0; i < library->num_songs; i++) {
        printf("%s\t\t%s\t\t%s\t\t%s\t\t%d\t\t%.1f\n", library->songs[i].name, 
               library->songs[i].artist, library->songs[i].album, library->songs[i].genre, 
               library->songs[i].year, library->songs[i].rating);
    }
}

// Searches the music library for a song with the given name and artist
// Returns -1 if the song is not found
int find_song(music_library_t* library, char* name, char* artist) {
    for (int i = 0; i < library->num_songs; i++) {
        if (strcmp(name, library->songs[i].name) == 0 && 
            strcmp(artist, library->songs[i].artist) == 0) {
            return i;
        }
    }
    return -1;
}

// Adds a new song to the music library
void add_song(music_library_t* library, song_t new_song) {
    library->songs[library->num_songs] = new_song;
    library->num_songs++;
}

// Removes a song from the music library
void remove_song(music_library_t* library, char* name, char* artist) {
    int index = find_song(library, name, artist);
    if (index == -1) {
        printf("Song not found!\n");
    } else {
        for (int i = index; i < library->num_songs - 1; i++) {
            library->songs[i] = library->songs[i+1];
        }
        library->num_songs--;
        printf("Song removed successfully!\n");
    }
}

// Updates the rating of a song
void update_rating(music_library_t* library, char* name, char* artist, float new_rating) {
    int index = find_song(library, name, artist);
    if (index == -1) {
        printf("Song not found!\n");
    } else {
        library->songs[index].rating = new_rating;
        printf("Rating updated successfully!\n");
    }
}

int main() {
    music_library_t my_library;
    memset(&my_library, 0, sizeof(music_library_t)); // Initialize all values to 0
    
    // Add some sample songs
    song_t song1 = {"Thunderstruck", "AC/DC", "The Razors Edge", "Rock", 1990, 4.5};
    add_song(&my_library, song1);
    song_t song2 = {"Sweet Child O' Mine", "Guns N' Roses", "Appetite for Destruction", "Rock", 1987, 4.8};
    add_song(&my_library, song2);
    song_t song3 = {"Billie Jean", "Michael Jackson", "Thriller", "Pop", 1982, 4.6};
    add_song(&my_library, song3);
    
    // Print all the songs in the library
    print_songs(&my_library);
    
    // Remove a song
    remove_song(&my_library, "Thunderstruck", "AC/DC");
    
    // Update the rating of a song
    update_rating(&my_library, "Sweet Child O' Mine", "Guns N' Roses", 4.9);
    
    // Print all the songs in the library again
    print_songs(&my_library);
    
    return 0;
}