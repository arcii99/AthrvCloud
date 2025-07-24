//FormAI DATASET v1.0 Category: Music Library Management System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 50
#define MAX_ARTIST_LENGTH 50
#define MAX_SONGS 100

struct Song {
    char title[MAX_TITLE_LENGTH + 1];
    char artist[MAX_ARTIST_LENGTH + 1];
    float duration;
    int year;
};

typedef struct Song Song;

struct Library {
    Song songs[MAX_SONGS];
    int num_songs;
    float total_duration;
    int years[MAX_SONGS];
    int num_years;
};

typedef struct Library Library;

void add_song(Library *lib, char *title, char *artist, float duration, int year) {
    if (lib->num_songs == MAX_SONGS) {
        printf("Library is full!\n");
        return;
    }
    strcpy(lib->songs[lib->num_songs].title, title);
    strcpy(lib->songs[lib->num_songs].artist, artist);
    lib->songs[lib->num_songs].duration = duration;
    lib->songs[lib->num_songs].year = year;
    lib->total_duration += duration;
    lib->num_songs++;
    lib->years[lib->num_years++] = year;
}

void print_lib(Library *lib) {
    printf("Library contents:\n");
    for (int i = 0; i < lib->num_songs; i++) {
        printf("Title: %s\nArtist: %s\nDuration: %.2f minutes\nYear: %d\n", lib->songs[i].title, lib->songs[i].artist, lib->songs[i].duration, lib->songs[i].year);
    }
    printf("Total duration: %.2f minutes\n", lib->total_duration);
    printf("Years present in library:\n");
    for (int i = 0; i < lib->num_years; i++) {
        printf("%d\n", lib->years[i]);
    }
}

int main() {
    Library lib;
    lib.num_songs = 0;
    lib.total_duration = 0;
    lib.num_years = 0;
    
    add_song(&lib, "Bittersweet Symphony", "The Verve", 4.35, 1997);
    add_song(&lib, "Lose Yourself", "Eminem", 5.20, 2002);
    add_song(&lib, "Bohemian Rhapsody", "Queen", 5.55, 1975);
    
    print_lib(&lib);
    
    return 0;
}