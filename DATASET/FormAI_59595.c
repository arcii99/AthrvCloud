//FormAI DATASET v1.0 Category: Music Library Management System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 1000

struct Song {
    char title[100];
    char artist[100];
    char album[100];
    int year;
    char genre[50];
};

struct Song s[MAX_SONGS];
int num_songs = 0;

int main() {
    int choice = 0;
    do {
        printf("\n***** C Music Library Management System *****\n");
        printf("1. Add Song\n");
        printf("2. Display all Songs\n");
        printf("3. Search for a Song\n");
        printf("4. Delete a Song\n");
        printf("5. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSong();
                break;
            case 2:
                displayAllSongs();
                break;
            case 3:
                searchSong();
                break;
            case 4:
                deleteSong();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 5);

    return 0;
}

void addSong() {
    if (num_songs == MAX_SONGS) {
        printf("Library full.\n");
        return;
    }

    printf("\nEnter song title: ");
    scanf(" %[^\n]%*c", s[num_songs].title);

    printf("Enter artist name: ");
    scanf(" %[^\n]%*c", s[num_songs].artist);

    printf("Enter album name: ");
    scanf(" %[^\n]%*c", s[num_songs].album);

    printf("Enter year of release: ");
    scanf("%d", &s[num_songs].year);

    printf("Enter genre: ");
    scanf(" %[^\n]%*c", s[num_songs].genre);

    num_songs++;
    printf("Song added to library!\n");
}

void displayAllSongs() {
    if (num_songs == 0) {
        printf("Library is empty.\n");
        return;
    }

    printf("\n***** All Songs in Library *****\n\n");
    for (int i = 0; i < num_songs; i++) {
        printf("Title:\t\t%s\n", s[i].title);
        printf("Artist:\t\t%s\n", s[i].artist);
        printf("Album:\t\t%s\n", s[i].album);
        printf("Year:\t\t%d\n", s[i].year);
        printf("Genre:\t\t%s\n", s[i].genre);
        printf("---------------------------------\n");
    }
}

void searchSong() {
    if (num_songs == 0) {
        printf("Library is empty.\n");
        return;
    }

    char search[100];
    printf("\nEnter title or artist of song to search: ");
    scanf(" %[^\n]%*c", search);

    int found = 0;

    for (int i = 0; i < num_songs; i++) {
        if (strstr(s[i].title, search) != NULL || strstr(s[i].artist, search) != NULL) {
            printf("\n***** Search Results *****\n\n");
            printf("Title:\t\t%s\n", s[i].title);
            printf("Artist:\t\t%s\n", s[i].artist);
            printf("Album:\t\t%s\n", s[i].album);
            printf("Year:\t\t%d\n", s[i].year);
            printf("Genre:\t\t%s\n", s[i].genre);
            printf("---------------------------\n");

            found = 1;
        }
    }

    if (!found) {
        printf("No matching songs found.\n");
    }
}

void deleteSong() {
    if (num_songs == 0) {
        printf("Library is empty.\n");
        return;
    }

    char search[100];
    printf("\nEnter title or artist of song to delete: ");
    scanf(" %[^\n]%*c", search);

    int found = 0;

    for (int i = 0; i < num_songs; i++) {
        if (strstr(s[i].title, search) != NULL || strstr(s[i].artist, search) != NULL) {
            printf("\n***** Song Deleted *****\n\n");
            printf("Title:\t\t%s\n", s[i].title);
            printf("Artist:\t\t%s\n", s[i].artist);
            printf("Album:\t\t%s\n", s[i].album);
            printf("Year:\t\t%d\n", s[i].year);
            printf("Genre:\t\t%s\n", s[i].genre);
            printf("---------------------------\n");

            for (int j = i; j < num_songs - 1; j++) {
                s[j] = s[j+1];
            }
            num_songs--;
            found = 1;
        }
    }

    if (!found) {
        printf("No matching songs found.\n");
    }
}