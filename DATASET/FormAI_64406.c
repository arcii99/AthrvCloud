//FormAI DATASET v1.0 Category: Music Library Management System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare a struct for songs
struct Song {
    char title[100];
    char artist[100];
    char album[100];
    int year;
};

// Declare function prototypes
void addSong(struct Song*);
void removeSong(struct Song*);
void searchSong(struct Song*);
void displaySongs(struct Song*);

// Global variables Declaration
int totalSongs = 0;
struct Song library[100];

int main() {
    int choice;

    while(1) {
        printf("\nMedieval Music Library Management System\n");
        printf("1. Add a song\n");
        printf("2. Remove a song\n");
        printf("3. Search for a song\n");
        printf("4. Display all songs\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addSong(&library[totalSongs]);
                totalSongs++;
                break;
            case 2:
                removeSong(library);
                break;
            case 3:
                searchSong(library);
                break;
            case 4:
                displaySongs(library);
                break;
            case 5:
                printf("Exiting Medieval Music Library. Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid Choice. Try again.\n");
                break;
        }
    }

    return 0;
}

void addSong(struct Song* song) {
    printf("Enter song title: ");
    fflush(stdout);
    scanf(" %[^\n]s", song->title);
    printf("Enter song artist: ");
    fflush(stdout);
    scanf(" %[^\n]s", song->artist);
    printf("Enter album name: ");
    fflush(stdout);
    scanf(" %[^\n]s", song->album);
    printf("Enter year of release: ");
    fflush(stdout);
    scanf("%d", &song->year);
    printf("\nSong added successfully!\n");
}

void removeSong(struct Song* songs) {
    char searchTitle[100];
    printf("Enter the title of the song to be removed: ");
    fflush(stdout);
    scanf(" %[^\n]s", searchTitle);

    int i, j, found = 0;
    for(i = 0; i < totalSongs; i++) {
        if(strcmp(songs[i].title, searchTitle) == 0) {
            found = 1;
            for(j = i; j < totalSongs - 1; j++) {
                songs[j] = songs[j+1];
            }
            totalSongs--;
            printf("\nSong removed successfully!\n");
            break;
        }
    }

    if(found == 0) {
        printf("\nSong not found. Try again.\n");
    }
}

void searchSong(struct Song* songs) {
    char searchTitle[100];
    printf("Enter the title of the song to be searched: ");
    fflush(stdout);
    scanf(" %[^\n]s", searchTitle);

    int i, found = 0;
    for(i = 0; i < totalSongs; i++) {
        if(strcmp(songs[i].title, searchTitle) == 0) {
            found = 1;
            printf("\nSong Found!\n");
            printf("Title: %s\n", songs[i].title);
            printf("Artist: %s\n", songs[i].artist);
            printf("Album: %s\n", songs[i].album);
            printf("Year: %d\n", songs[i].year);
            break;
        }
    }

    if(found == 0) {
        printf("\nSong not found. Try again.\n");
    }
}

void displaySongs(struct Song* songs) {
    int i;

    printf("\nTotal Songs in Library: %d\n", totalSongs);

    if(totalSongs == 0) {
        printf("No songs in Library. Add some songs!\n");
    } else {
        printf("Title\t\tArtist\t\tAlbum\t\tYear\n");
        for(i = 0; i < totalSongs; i++) {
            printf("%-15s%-15s%-15s%d\n", songs[i].title, songs[i].artist, songs[i].album, songs[i].year);
        }
    }
}