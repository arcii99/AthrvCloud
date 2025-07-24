//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 50
#define MAX_ARTIST_LENGTH 50
#define MAX_ALBUM_LENGTH 50
#define MAX_TRACKS 100

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    char album[MAX_ALBUM_LENGTH];
    int duration; // in seconds
} Song;

typedef struct {
    int trackNum;
    Song song;
} Track;

typedef struct {
    char name[MAX_ARTIST_LENGTH];
    Track tracks[MAX_TRACKS];
    int numTracks;
} Album;

typedef struct {
    Album albums[MAX_ALBUM_LENGTH];
    int numAlbums;
} Library;

// function prototypes
void printMenu();
void addAlbum(Library *library);
void addSong(Album *album);
void removeAlbum(Library *library);
void removeSong(Album *album);
void playAlbum(Album album);
void searchAlbum(Library library);
void searchSong(Library library);

int main() {
    Library library;
    library.numAlbums = 0;

    int choice;
    char buffer[20];

    printf("Welcome to the Music Library Management System!\n");

    do {
        printMenu();

        printf("Enter your choice: ");
        fgets(buffer, 20, stdin);
        choice = atoi(buffer);

        switch (choice) {
            case 1:
                addAlbum(&library);
                break;
            case 2:
                removeAlbum(&library);
                break;
            case 3:
                searchAlbum(library);
                break;
            case 4:
                searchSong(library);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (1);

    return 0;
}

void printMenu() {
    printf("\n-- Menu --\n");
    printf("1. Add an album\n");
    printf("2. Remove an album\n");
    printf("3. Search for an album\n");
    printf("4. Search for a song\n");
    printf("5. Quit\n");
}

void addAlbum(Library *library) {
    Album album;
    Track track;
    char buffer[MAX_ARTIST_LENGTH];

    printf("Enter album name: ");
    fgets(album.name, MAX_ARTIST_LENGTH, stdin);
    album.name[strcspn(album.name, "\n")] = '\0';

    printf("Enter number of tracks: ");
    fgets(buffer, MAX_ARTIST_LENGTH, stdin);
    album.numTracks = atoi(buffer);

    for (int i = 0; i < album.numTracks; i++) {
        track.trackNum = i;

        printf("\nTrack %d:\n", i);
        printf("Enter title: ");
        fgets(track.song.title, MAX_TITLE_LENGTH, stdin);
        track.song.title[strcspn(track.song.title, "\n")] = '\0';

        printf("Enter artist: ");
        fgets(track.song.artist, MAX_ARTIST_LENGTH, stdin);
        track.song.artist[strcspn(track.song.artist, "\n")] = '\0';

        printf("Enter album: ");
        fgets(track.song.album, MAX_ALBUM_LENGTH, stdin);
        track.song.album[strcspn(track.song.album, "\n")] = '\0';

        printf("Enter duration (in seconds): ");
        fgets(buffer, MAX_ARTIST_LENGTH, stdin);
        track.song.duration = atoi(buffer);

        album.tracks[i] = track;
    }

    library->albums[library->numAlbums] = album;
    library->numAlbums++;

    printf("Album added successfully.\n");
}

void removeAlbum(Library *library) {
    char buffer[MAX_ARTIST_LENGTH];
    char name[MAX_ARTIST_LENGTH];

    printf("Enter album name: ");
    fgets(name, MAX_ARTIST_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0';

    for (int i = 0; i < library->numAlbums; i++) {
        if (strcmp(library->albums[i].name, name) == 0) {
            for (int j = i; j < library->numAlbums - 1; j++) {
                library->albums[j] = library->albums[j+1];
            }
            library->numAlbums--;
            printf("Album removed successfully.\n");
            return;
        }
    }

    printf("Album not found.\n");
}

void searchAlbum(Library library) {
    char buffer[MAX_ARTIST_LENGTH];
    char name[MAX_ARTIST_LENGTH];

    printf("Enter album name: ");
    fgets(name, MAX_ARTIST_LENGTH, stdin);
    name[strcspn(name, "\n")] = '\0';

    for (int i = 0; i < library.numAlbums; i++) {
        if (strcmp(library.albums[i].name, name) == 0) {
            printf("\nAlbum %d:\n", i+1);
            printf("Name: %s\n", library.albums[i].name);
            printf("Tracks:\n");

            for (int j = 0; j < library.albums[i].numTracks; j++) {
                printf("%d. %s - %s (%d seconds)\n", library.albums[i].tracks[j].trackNum+1,
                                                    library.albums[i].tracks[j].song.title,
                                                    library.albums[i].tracks[j].song.artist,
                                                    library.albums[i].tracks[j].song.duration);
            }
            return;
        }
    }

    printf("Album not found.\n");
}

void searchSong(Library library) {
    char buffer[MAX_ARTIST_LENGTH];
    char title[MAX_TITLE_LENGTH];

    printf("Enter song title: ");
    fgets(title, MAX_TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = '\0';

    for (int i = 0; i < library.numAlbums; i++) {
        for (int j = 0; j < library.albums[i].numTracks; j++) {
            if (strcmp(library.albums[i].tracks[j].song.title, title) == 0) {
                printf("%s - %s (%d seconds)\n", library.albums[i].tracks[j].song.artist,
                                                 library.albums[i].tracks[j].song.album,
                                                 library.albums[i].tracks[j].song.duration);
                return;
            }
        }
    }

    printf("Song not found.\n");
}