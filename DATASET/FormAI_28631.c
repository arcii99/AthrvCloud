//FormAI DATASET v1.0 Category: Music Library Management System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song {
    char title[50];
    char artist[50];
    char genre[20];
    float duration;
} Song;

typedef struct Album {
    char albumName[50];
    int releaseYear;
    Song* songs;
    int numberOfSongs;
} Album;

typedef struct MusicLibrary {
    Album* albums;
    int numberOfAlbums;
} MusicLibrary;

int main() {
    MusicLibrary* library = (MusicLibrary*) malloc(sizeof(MusicLibrary));
    library->numberOfAlbums = 0;
    library->albums = NULL;

    int menuChoice = 0;

    while (menuChoice != 5) {
        printf("\n");
        printf("1. Add Album to Library\n");
        printf("2. Add Song to Album\n");
        printf("3. Display All Albums\n");
        printf("4. Search for Album by Name\n");
        printf("5. Exit Program\n");
        printf("\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &menuChoice);

        switch (menuChoice) {
            case 1:
                addAlbum(library);
                break;
            case 2:
                addSong(library);
                break;
            case 3:
                displayAllAlbums(library);
                break;
            case 4:
                searchAlbum(library);
                break;
            case 5:
                printf("Exiting Program...\n");
                break;
            default:
                printf("Invalid Choice\n");
        }
    }

    free(library);
    return 0;
}

void addAlbum(MusicLibrary* library) {
    Album album;
    printf("Album Name: ");
    scanf("%s", album.albumName);
    printf("Release Year: ");
    scanf("%d", &album.releaseYear);
    album.numberOfSongs = 0;
    album.songs = NULL;

    library->numberOfAlbums++;
    library->albums = (Album*) realloc(library->albums, sizeof(Album) * library->numberOfAlbums);
    library->albums[library->numberOfAlbums - 1] = album;

    printf("Album added to Library Successfully!\n");
}

void addSong(MusicLibrary* library) {
    char albumName[50];
    printf("Enter Album Name: ");
    scanf("%s", albumName);

    for (int i = 0; i < library->numberOfAlbums; i++) {
        if (strcmp(library->albums[i].albumName, albumName) == 0) {
            Song song;

            printf("Song Title: ");
            scanf("%s", song.title);
            printf("Song Artist: ");
            scanf("%s", song.artist);
            printf("Song Genre: ");
            scanf("%s", song.genre);
            printf("Song Duration (in minutes): ");
            scanf("%f", &song.duration);

            library->albums[i].numberOfSongs++;
            library->albums[i].songs = (Song*) realloc(library->albums[i].songs, sizeof(Song) * library->albums[i].numberOfSongs);
            library->albums[i].songs[library->albums[i].numberOfSongs - 1] = song;

            printf("Song added to Album Successfully!\n");
            return;
        }
    }

    printf("Album not found in Library\n");
}

void displayAllAlbums(MusicLibrary* library) {
    if (library->numberOfAlbums == 0) {
        printf("Library is Empty\n");
        return;
    }

    printf("%-25s%-15s%-25s%-15s\n", "------- Album Name -------", "-- Release Year --", "--------- Artist --------", "--- Genre ---");

    for (int i = 0; i < library->numberOfAlbums; i++) {
        printf("%-25s%-15d\n", library->albums[i].albumName, library->albums[i].releaseYear);

        for (int j = 0; j < library->albums[i].numberOfSongs; j++) {
            printf("%-25s%-15s%-25s%-15s%-3.2f\n", "", "", library->albums[i].songs[j].title,
            library->albums[i].songs[j].artist, library->albums[i].songs[j].genre, library->albums[i].songs[j].duration);
        }
    }
}

void searchAlbum(MusicLibrary* library) {
    char albumName[50];
    printf("Enter Album Name: ");
    scanf("%s", albumName);

    for (int i = 0; i < library->numberOfAlbums; i++) {
        if (strcmp(library->albums[i].albumName, albumName) == 0) {
            printf("%-25s%-15s%-25s%-15s\n", "------- Album Name -------", "-- Release Year --", "--------- Artist --------", "--- Genre ---");
            printf("%-25s%-15d\n", library->albums[i].albumName, library->albums[i].releaseYear);

            for (int j = 0; j < library->albums[i].numberOfSongs; j++) {
                printf("%-25s%-15s%-25s%-15s%-3.2f\n", "", "", library->albums[i].songs[j].title,
                library->albums[i].songs[j].artist, library->albums[i].songs[j].genre, library->albums[i].songs[j].duration);
            }

            return;
        }
    }

    printf("Album not found in Library\n");
}