//FormAI DATASET v1.0 Category: Music Library Management System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100 // Maximum number of songs
#define MAX_NAME_LEN 50 // Maximum length of a song name

typedef struct{
    char name[MAX_NAME_LEN];
    char artist[MAX_NAME_LEN];
    int year;
    float duration;
} Song;

typedef struct{
    Song songs[MAX_SONGS];
    int num_songs;
} MusicLibrary;

// Function to add a song to the library
void add_song(MusicLibrary *library, Song song){
    if(library->num_songs >= MAX_SONGS){
        printf("Error: Library is full.\n");
        return;
    }
    library->songs[library->num_songs] = song;
    library->num_songs++;
}

// Function to remove a song from the library
void remove_song(MusicLibrary *library, char *name){
    int i;
    for(i=0; i<library->num_songs; i++){
        if(strcmp(name, library->songs[i].name) == 0){
            int j;
            for(j=i; j<library->num_songs-1; j++){
                library->songs[j] = library->songs[j+1];
            }
            library->num_songs--;
            printf("%s removed successfully.\n", name);
            return;
        }
    }
    printf("%s not found in library.\n", name);
}

// Function to search for a song by name
void search_by_name(MusicLibrary *library, char *name){
    printf("Search results for \"%s\":\n", name);
    int i;
    for(i=0; i<library->num_songs; i++){
        if(strstr(library->songs[i].name, name) != NULL){
            printf("%s by %s (%d) - %.2f minutes\n", library->songs[i].name, library->songs[i].artist, library->songs[i].year, library->songs[i].duration);
        }
    }
}

// Function to search for a song by artist
void search_by_artist(MusicLibrary *library, char *artist){
    printf("Search results for \"%s\":\n", artist);
    int i;
    for(i=0; i<library->num_songs; i++){
        if(strstr(library->songs[i].artist, artist) != NULL){
            printf("%s by %s (%d) - %.2f minutes\n", library->songs[i].name, library->songs[i].artist, library->songs[i].year, library->songs[i].duration);
        }
    }
}

// Function to print all songs in the library
void print_library(MusicLibrary *library){
    printf("Library Contents:\n");
    int i;
    for(i=0; i<library->num_songs; i++){
        printf("%s by %s (%d) - %.2f minutes\n", library->songs[i].name, library->songs[i].artist, library->songs[i].year, library->songs[i].duration);
    }
}

int main(){
    MusicLibrary library;
    library.num_songs = 0;

    // Adding some dummy songs to the library
    Song song1 = {"Victory", "Eben", 2015, 4.15};
    Song song2 = {"Oh My Soul", "Nathaniel Bassey", 2019, 6.30};
    Song song3 = {"Way Maker", "Sinach", 2015, 5.32};
    Song song4 = {"Onise Iyanu", "Nathaniel Bassey", 2016, 4.22};
    Song song5 = {"Alagbada Ina", "Tope Alabi", 2013, 3.57};

    add_song(&library, song1);
    add_song(&library, song2);
    add_song(&library, song3);
    add_song(&library, song4);
    add_song(&library, song5);

    // Printing the library contents
    print_library(&library);

    // Removing a song from the library
    remove_song(&library, "Onise Iyanu");

    // Searching for a song in the library
    search_by_name(&library, "Victory");

    // Searching for songs by an artist in the library
    search_by_artist(&library, "Nathaniel Bassey");

    printf("After all these actions, the library contents are:\n");
    print_library(&library);

    return 0;
}