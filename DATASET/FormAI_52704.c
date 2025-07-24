//FormAI DATASET v1.0 Category: Music Library Management System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100

typedef struct song {
    char title[50];
    char artist[50];
    int year;
    float duration;
} Song;

typedef struct library {
    Song songs[MAX_SONGS];
    int num_songs;
} Library;

void welcome() {
    printf("Welcome to the Music Library Management System!\n");
}

void display_menu() {
    printf("\nMenu:\n");
    printf("1. Add Song\n");
    printf("2. Remove Song\n");
    printf("3. Display Songs\n");
    printf("4. Search Song\n");
    printf("5. Exit\n");
}

void add_song(Library* lib) {
    if (lib->num_songs >= MAX_SONGS) {
        printf("Library is full!\n");
        return;
    }

    Song new_song;

    printf("Enter song title: ");
    scanf("%s", new_song.title);

    printf("Enter song artist: ");
    scanf("%s", new_song.artist);

    printf("Enter song release year: ");
    scanf("%d", &new_song.year);

    printf("Enter song duration: ");
    scanf("%f", &new_song.duration);

    lib->songs[lib->num_songs++] = new_song;

    printf("Song added successfully!\n");
}

void remove_song(Library* lib) {
    if (lib->num_songs == 0) {
        printf("Library is empty!\n");
        return;
    }

    char title[50];

    printf("Enter song title to remove: ");
    scanf("%s", title);

    for (int i = 0; i < lib->num_songs; i++) {
        if (strcmp(lib->songs[i].title, title) == 0) {
            lib->num_songs--;

            for (int j = i; j < lib->num_songs; j++) {
                lib->songs[j] = lib->songs[j+1];
            }

            printf("Song removed successfully!\n");

            return;
        }
    }

    printf("Song not found!\n");
}

void display_songs(Library* lib) {
    if (lib->num_songs == 0) {
        printf("Library is empty!\n");
        return;
    }

    printf("\nSong Title\t|\tArtist\t\t|\tYear\t|\tDuration\n");

    for (int i = 0; i < lib->num_songs; i++) {
        printf("%s\t|\t%s\t\t|\t%d\t|\t%.2f mins\n", lib->songs[i].title, lib->songs[i].artist, lib->songs[i].year, lib->songs[i].duration);
    }
}

void search_song(Library* lib, char* title) {
    if (lib->num_songs == 0) {
        printf("Library is empty!\n");
        return;
    }

    for (int i = 0; i < lib->num_songs; i++) {
        if (strcmp(lib->songs[i].title, title) == 0) {
            printf("\nSong Title\t|\tArtist\t\t|\tYear\t|\tDuration\n");
            printf("%s\t|\t%s\t\t|\t%d\t|\t%.2f mins\n", lib->songs[i].title, lib->songs[i].artist, lib->songs[i].year, lib->songs[i].duration);
            return;
        }
    }

    printf("Song not found!\n");
}

int main() {
    welcome();

    Library music_lib;
    music_lib.num_songs = 0;

    int choice;

    do {
        display_menu();

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_song(&music_lib);
                break;
            case 2:
                remove_song(&music_lib);
                break;
            case 3:
                display_songs(&music_lib);
                break;
            case 4:
                char title[50];
                printf("Enter song title to search: ");
                scanf("%s", title);
                search_song(&music_lib, title);
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}