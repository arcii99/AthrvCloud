//FormAI DATASET v1.0 Category: Music Library Management System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_SIZE 100

struct song {
    int id;
    char title[50];
    char artist[50];
    char genre[20];
    float duration;
};

struct music_library {
    struct song songs[MAX_SIZE];
    int num_songs;
    pthread_mutex_t mutex;
};

struct music_library my_library;

void add_song(struct song new_song) {
    pthread_mutex_lock(&my_library.mutex);
    if (my_library.num_songs < MAX_SIZE) {
        my_library.songs[my_library.num_songs++] = new_song;
        printf("Added new song with ID %d\n", new_song.id);
    } else {
        printf("Error: Library maximum size reached.\n");
    }
    pthread_mutex_unlock(&my_library.mutex);
}

void remove_song(int song_id) {
    pthread_mutex_lock(&my_library.mutex);
    for (int i = 0; i < my_library.num_songs; i++) {
        if (my_library.songs[i].id == song_id) {
            printf("Removing song with ID %d: %s by %s\n",
                my_library.songs[i].id, my_library.songs[i].title,
                my_library.songs[i].artist);
            for (int j = i; j < my_library.num_songs - 1; j++) {
                my_library.songs[j] = my_library.songs[j+1];
            }
            my_library.num_songs--;
            pthread_mutex_unlock(&my_library.mutex);
            return;
        }
    }
    printf("Error: Song with ID %d not found.\n", song_id);
    pthread_mutex_unlock(&my_library.mutex);
}

void* print_library(void* arg) {
    pthread_mutex_lock(&my_library.mutex);
    printf("Library contents:\n");
    for (int i = 0; i < my_library.num_songs; i++) {
        printf("%d, %s, %s, %s, %.2f\n", my_library.songs[i].id,
            my_library.songs[i].title, my_library.songs[i].artist,
            my_library.songs[i].genre, my_library.songs[i].duration);
    }
    printf("End of library contents.\n");
    pthread_mutex_unlock(&my_library.mutex);
    return NULL;
}

int main() {
    my_library.num_songs = 0;
    pthread_mutex_init(&my_library.mutex, NULL);

    // create some sample songs
    struct song song1 = {1, "Bohemian Rhapsody", "Queen", "Rock", 6.07};
    struct song song2 = {2, "Stairway to Heaven", "Led Zeppelin", "Rock", 8.02};
    struct song song3 = {3, "Hotel California", "Eagles", "Rock", 6.30};

    // add the songs to the library
    add_song(song1);
    add_song(song2);
    add_song(song3);

    // start a new thread to print the library contents
    pthread_t print_thread;
    pthread_create(&print_thread, NULL, print_library, NULL);

    // wait for the print thread to finish before continuing
    pthread_join(print_thread, NULL);

    remove_song(2);

    pthread_exit(NULL);
}