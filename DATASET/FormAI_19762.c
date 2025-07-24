//FormAI DATASET v1.0 Category: Music Library Management System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALBUMS 50
#define MAX_NAME_LEN 50
#define MAX_SONGS 200

typedef struct song {
    char name[MAX_NAME_LEN];
    int length;
} Song;

typedef struct album {
    char name[MAX_NAME_LEN];
    int year;
    Song songs[MAX_SONGS];
    int num_songs;
} Album;

Album albums[MAX_ALBUMS];
int num_albums = 0;

void add_album(char* name, int year) {
    Album new_album;
    strcpy(new_album.name, name);
    new_album.year = year;
    new_album.num_songs = 0;
    albums[num_albums] = new_album;
    num_albums++;
}

void add_song(char* name, int length, int album_index) {
    Song new_song;
    strcpy(new_song.name, name);
    new_song.length = length;
    albums[album_index].songs[albums[album_index].num_songs] = new_song;
    albums[album_index].num_songs++;
}

void print_album(int index) {
    printf("Album Name: %s\n", albums[index].name);
    printf("Year: %d\n", albums[index].year);
    printf("Songs:\n");
    for(int i = 0; i < albums[index].num_songs; i++) {
        printf("%s - %d seconds\n", albums[index].songs[i].name, albums[index].songs[i].length);
    }
}

int main() {

    // Add some albums and songs
    add_album("Thriller", 1982);
    add_song("Wanna Be Startin' Somethin'", 383, 0);
    add_song("Baby Be Mine", 254, 0);
    add_song("The Girl Is Mine", 224, 0);
    add_song("Thriller", 357, 0);
    add_album("1989", 2014);
    add_song("Welcome To New York", 217, 1);
    add_song("Blank Space", 231, 1);
    add_song("Shake It Off", 219, 1);
    add_song("Bad Blood", 229, 1);
    add_song("Wildest Dreams", 235, 1);

    // Print out albums and songs
    print_album(0);
    printf("\n");
    print_album(1);

    return 0;
}