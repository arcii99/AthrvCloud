//FormAI DATASET v1.0 Category: Music Library Management System ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SONGS 50
#define MAX_LENGTH 25

struct song {
    char title[MAX_LENGTH];
    char artist[MAX_LENGTH];
    char album[MAX_LENGTH];
    int year;
    int duration;
};

struct music_library {
    struct song song_list[MAX_SONGS];
    int total_songs;
    double total_duration;
};

void add_song(struct music_library *library, struct song new_song) {
    if (library->total_songs >= MAX_SONGS) {
        printf("Music library is full. Cannot add song.\n");
        return;
    }
    library->song_list[library->total_songs] = new_song;
    library->total_songs++;
    library->total_duration += new_song.duration;
    printf("Song added successfully.\n");
}

void delete_song(struct music_library *library, char *song_title) {
    int i;
    int song_index = -1;
    for (i = 0; i < library->total_songs; i++) {
        if (strcmp(library->song_list[i].title, song_title) == 0) {
            song_index = i;
            break;
        }
    }
    if (song_index == -1) {
        printf("Song not found in the music library.\n");
        return;
    }
    library->total_songs--;
    library->total_duration -= library->song_list[song_index].duration;
    for (i = song_index; i < library->total_songs; i++) {
        library->song_list[i] = library->song_list[i+1];
    }
    printf("Song deleted successfully.\n");
}

void print_library(struct music_library *library) {
    int i;
    printf("Total songs in the library: %d\n", library->total_songs);
    printf("Total duration of all songs: %f\n", library->total_duration);
    printf("   %-20s%-20s%-20s%-10s%-10s\n", "Title", "Artist", "Album", "Year", "Duration");
    for (i = 0; i < library->total_songs; i++) {
        printf("%d. %-20s%-20s%-20s%-10d%-10d\n", i+1, library->song_list[i].title,
               library->song_list[i].artist, library->song_list[i].album,
               library->song_list[i].year, library->song_list[i].duration);
    }
}

int main() {
    struct music_library my_library = {0};
    struct song new_song = {0};

    // Adding songs to the library
    printf("Adding songs to the music library...\n");
    strcpy(new_song.title, "Shape of You");
    strcpy(new_song.artist, "Ed Sheeran");
    strcpy(new_song.album, "÷");
    new_song.year = 2017;
    new_song.duration = 233;
    add_song(&my_library, new_song);

    strcpy(new_song.title, "Uptown Funk");
    strcpy(new_song.artist, "Mark Ronson ft. Bruno Mars");
    strcpy(new_song.album, "Uptown Special");
    new_song.year = 2014;
    new_song.duration = 270;
    add_song(&my_library, new_song);

    strcpy(new_song.title, "I Will Always Love You");
    strcpy(new_song.artist, "Whitney Houston");
    strcpy(new_song.album, "The Bodyguard");
    new_song.year = 1992;
    new_song.duration = 273;
    add_song(&my_library, new_song);

    strcpy(new_song.title, "Billie Jean");
    strcpy(new_song.artist, "Michael Jackson");
    strcpy(new_song.album, "Thriller");
    new_song.year = 1983;
    new_song.duration = 293;
    add_song(&my_library, new_song);

    // Displaying the music library
    printf("Displaying the music library...\n");
    print_library(&my_library);

    // Deleting a song from the library
    printf("Deleting a song from the music library...\n");
    delete_song(&my_library, "Uptown Funk");

    // Displaying the music library again
    printf("Displaying the music library after deleting a song...\n");
    print_library(&my_library);

    return 0;
}