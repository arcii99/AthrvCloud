//FormAI DATASET v1.0 Category: Music Library Management System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_LENGTH 50

struct Song {
    char title[MAX_LENGTH];
    char artist[MAX_LENGTH];
    char album[MAX_LENGTH];
    int year;
};

struct Library {
    struct Song songs[MAX_SONGS];
    int count;
};

void addSong(struct Library* lib, char* title, char* artist, char* album, int year) {
    if (lib->count >= MAX_SONGS) {
        printf("Error: library is full.\n");
        return;
    }

    if (strlen(title) > MAX_LENGTH || strlen(artist) > MAX_LENGTH || strlen(album) > MAX_LENGTH) {
        printf("Error: song attribute is too long.\n");
        return;
    }

    struct Song* newSong = &lib->songs[lib->count];
    strncpy(newSong->title, title, MAX_LENGTH);
    strncpy(newSong->artist, artist, MAX_LENGTH);
    strncpy(newSong->album, album, MAX_LENGTH);
    newSong->year = year;

    lib->count++;

    printf("Song added successfully.\n");
}

void editSong(struct Library* lib, char* title, char* fieldToEdit, char* newValue) {
    for (int i = 0; i < lib->count; i++) {
        struct Song* song = &lib->songs[i];
        if (strcmp(song->title, title) == 0) {
            if (strcmp(fieldToEdit, "title") == 0) {
                strncpy(song->title, newValue, MAX_LENGTH);
                printf("Title updated successfully.\n");
            } else if (strcmp(fieldToEdit, "artist") == 0) {
                strncpy(song->artist, newValue, MAX_LENGTH);
                printf("Artist updated successfully.\n");
            } else if (strcmp(fieldToEdit, "album") == 0) {
                strncpy(song->album, newValue, MAX_LENGTH);
                printf("Album updated successfully.\n");
            } else if (strcmp(fieldToEdit, "year") == 0) {
                song->year = atoi(newValue);
                printf("Year updated successfully.\n");
            } else {
                printf("Error: invalid field.\n");
            }
            return;
        }
    }

    printf("Error: song not found.\n");
}

void removeSong(struct Library* lib, char* title) {
    for (int i = 0; i < lib->count; i++) {
        struct Song* song = &lib->songs[i];
        if (strcmp(song->title, title) == 0) {
            memmove(song, song+1, (lib->count - i - 1) * sizeof(struct Song));
            lib->count--;
            printf("Song removed successfully.\n");
            return;
        }
    }

    printf("Error: song not found.\n");
}

void printLibrary(struct Library* lib) {
    printf("| %-20s | %-20s | %-20s | %-5s |\n", "Title", "Artist", "Album", "Year");
    printf("|-------------------------------------------------------|\n");
    for (int i = 0; i < lib->count; i++) {
        struct Song* song = &lib->songs[i];
        printf("| %-20s | %-20s | %-20s | %-5d |\n", song->title, song->artist, song->album, song->year);
    }
    printf("|-------------------------------------------------------|\n");
}

int main() {
    struct Library myLibrary;
    myLibrary.count = 0;

    printf("Welcome to the Paranoid Music Library Management System.\n");
    printf("All input data will be encrypted and stored on a blockchain.\n");
    printf("Please enter your access token for the blockchain server: ");
    char accessToken[MAX_LENGTH];
    fgets(accessToken, MAX_LENGTH, stdin);

    printf("Please authenticate with the facial recognition system.\n");
    printf("Press <Enter> to continue.");
    getchar();

    for(;;) {
        printf("\nPlease select an option:\n");
        printf("1. Add song\n");
        printf("2. Edit song\n");
        printf("3. Remove song\n");
        printf("4. Print library\n");
        printf("5. Exit\n");

        char option[MAX_LENGTH];
        fgets(option, MAX_LENGTH, stdin);
        option[strcspn(option, "\n")] = 0;

        if (strcmp(option, "1") == 0) {
            printf("Enter song title: ");
            char title[MAX_LENGTH], artist[MAX_LENGTH], album[MAX_LENGTH], yearStr[MAX_LENGTH];
            fgets(title, MAX_LENGTH, stdin);
            title[strcspn(title, "\n")] = 0;
            printf("Enter artist name: ");
            fgets(artist, MAX_LENGTH, stdin);
            artist[strcspn(artist, "\n")] = 0;
            printf("Enter album name: ");
            fgets(album, MAX_LENGTH, stdin);
            album[strcspn(album, "\n")] = 0;
            printf("Enter year: ");
            fgets(yearStr, MAX_LENGTH, stdin);
            yearStr[strcspn(yearStr, "\n")] = 0;
            int year = atoi(yearStr);
            addSong(&myLibrary, title, artist, album, year);
        } else if (strcmp(option, "2") == 0) {
            printf("Enter song title: ");
            char title[MAX_LENGTH], fieldToEdit[MAX_LENGTH], newValue[MAX_LENGTH];
            fgets(title, MAX_LENGTH, stdin);
            title[strcspn(title, "\n")] = 0;
            printf("Enter field to edit (title, artist, album, year): ");
            fgets(fieldToEdit, MAX_LENGTH, stdin);
            fieldToEdit[strcspn(fieldToEdit, "\n")] = 0;
            printf("Enter new value: ");
            fgets(newValue, MAX_LENGTH, stdin);
            newValue[strcspn(newValue, "\n")] = 0;
            editSong(&myLibrary, title, fieldToEdit, newValue);
        } else if (strcmp(option, "3") == 0) {
            printf("Enter song title: ");
            char title[MAX_LENGTH];
            fgets(title, MAX_LENGTH, stdin);
            title[strcspn(title, "\n")] = 0;
            removeSong(&myLibrary, title);
        } else if (strcmp(option, "4") == 0) {
            printLibrary(&myLibrary);
        } else if (strcmp(option, "5") == 0) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Error: invalid option.\n");
        }
    }

    return 0;
}