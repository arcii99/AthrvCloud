//FormAI DATASET v1.0 Category: Music Library Management System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

// Define constants
#define MAX_SONGS 100
#define MAX_TITLE 100
#define MAX_ARTIST 50
#define MAX_GENRE 20

// Song struct
typedef struct Song {
    char title[MAX_TITLE];
    char artist[MAX_ARTIST];
    char genre[MAX_GENRE];
} Song;

// Global variables
Song* songList[MAX_SONGS];
int numSongs = 0;
sem_t sem;

// Function prototypes
void* printLibrary(void*);

int main() {
    pthread_t thread;

    // Initialize semaphore with value 1
    sem_init(&sem, 0, 1);

    // Add initial songs to the library
    Song s1 = { "Bohemian Rhapsody", "Queen", "Rock" };
    Song s2 = { "Billie Jean", "Michael Jackson", "Pop" };
    Song s3 = { "Stairway to Heaven", "Led Zeppelin", "Rock" };
    addSong(&s1);
    addSong(&s2);
    addSong(&s3);

    // Start the print library thread
    int res = pthread_create(&thread, NULL, printLibrary, NULL);
    if (res != 0) {
        perror("Thread create error!");
        exit(EXIT_FAILURE);
    }

    // Add new songs to the library
    char input[MAX_TITLE + MAX_ARTIST + MAX_GENRE + 3];
    while (1) {
        printf("\nEnter a song (title, artist, genre), or enter 'quit' to exit: ");
        fgets(input, sizeof(input), stdin);
        if (strncmp(input, "quit", 4) == 0) {
            break;
        }
        Song* newSong = (Song*)malloc(sizeof(Song));
        sscanf(input, "%[^,],%[^,],%[^\n]", newSong->title, newSong->artist, newSong->genre);
        addSong(newSong);
    }

    // Wait for the print library thread to exit
    res = pthread_join(thread, NULL);
    if (res != 0) {
        perror("Thread join error!");
        exit(EXIT_FAILURE);
    }

    // Destroy the semaphore
    sem_destroy(&sem);

    return 0;
}

// Function to add a song to the library
void addSong(Song* song) {
    sem_wait(&sem);  // Wait for access to critical section
    if (numSongs >= MAX_SONGS) {
        printf("Error: Library is full! Cannot add song.\n");
        sem_post(&sem);
        return;
    }
    songList[numSongs++] = song;
    sem_post(&sem);  // Release access to critical section
}

// Function to print the entire library
void* printLibrary(void* arg) {
    sem_wait(&sem);  // Wait for access to critical section
    printf("\nLibrary Contents:\n");
    for (int i = 0; i < numSongs; i++) {
        printf("%s by %s (%s)\n", songList[i]->title, songList[i]->artist, songList[i]->genre);
    }
    sem_post(&sem);  // Release access to critical section
    pthread_exit(NULL);
}