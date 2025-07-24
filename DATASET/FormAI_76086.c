//FormAI DATASET v1.0 Category: Music Library Management System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIB_SIZE 100
#define MAX_SONG_NAME 50

typedef struct {
    char song_name[MAX_SONG_NAME];
    char artist_name[MAX_SONG_NAME];
    int year;
    float duration;
} Song;

typedef struct {
    int num_songs;
    Song songs[MAX_LIB_SIZE];
} Library;

void print_library(Library *lib) {
    printf("Library contains %d songs:\n", lib->num_songs);
    for (int i = 0; i < lib->num_songs; i++) {
        Song *sng = &lib->songs[i];
        printf("%d. %s by %s (%d) [%.2f]\n",
            i+1, sng->song_name, sng->artist_name, sng->year, sng->duration);
    }
}

int main() {
    // create library
    Library my_library = {0};

    // add some songs
    Song song1 = {"The End is Nigh", "Apocalyptic Symphony", 2025, 7.10};
    my_library.songs[my_library.num_songs++] = song1;

    Song song2 = {"Radiation Blues", "Wastelanders", 2030, 4.50};
    my_library.songs[my_library.num_songs++] = song2;

    Song song3 = {"Desert Heat", "The Last Nomads", 2028, 5.15};
    my_library.songs[my_library.num_songs++] = song3;

    // print library
    print_library(&my_library);

    // remove song
    printf("\nRemoving song 'Radiation Blues'...\n");
    for (int i = 0; i < my_library.num_songs; i++) {
        Song *sng = &my_library.songs[i];
        if (strcmp(sng->song_name, "Radiation Blues") == 0) {
            for (int j = i; j < my_library.num_songs - 1; j++) {
                my_library.songs[j] = my_library.songs[j + 1];
            }
            my_library.num_songs--;
            break;
        }
    }

    // print library again
    print_library(&my_library);

    return 0;
}