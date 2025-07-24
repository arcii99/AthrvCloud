//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALBUMS 1000
#define MAX_SONGS 2000

typedef struct {
    char name[50];
    int year;
    char artist[50];
} Album;

typedef struct {
    char name[50];
    int length;
    char album[50];
} Song;

Album albums[MAX_ALBUMS];
Song songs[MAX_SONGS];
int numAlbums = 0, numSongs = 0;

void addAlbum()
{
    Album newAlbum;
    printf("Name: ");
    fgets(newAlbum.name, 50, stdin);
    printf("Year: ");
    scanf("%d", &newAlbum.year);
    getchar();
    printf("Artist: ");
    fgets(newAlbum.artist, 50, stdin);
    albums[numAlbums++] = newAlbum;
}

void addSong()
{
    Song newSong;
    printf("Name: ");
    fgets(newSong.name, 50, stdin);
    printf("Length (in seconds): ");
    scanf("%d", &newSong.length);
    getchar();
    printf("Album: ");
    fgets(newSong.album, 50, stdin);
    songs[numSongs++] = newSong;
}

void listAlbums()
{
    printf("Albums:\n");
    for (int i = 0; i < numAlbums; i++) {
        printf("%d. %s, %s (%d)\n", i+1, albums[i].name, albums[i].artist, albums[i].year);
    }
}

void listSongs()
{
    printf("Songs:\n");
    for (int i = 0; i < numSongs; i++) {
        printf("%d. %s, %s (%d seconds)\n", i+1, songs[i].name, songs[i].album, songs[i].length);
    }
}

void saveData()
{
    FILE *albumFile = fopen("albums.dat", "w");
    for (int i = 0; i < numAlbums; i++) {
        fprintf(albumFile, "%s,%d,%s\n", albums[i].name, albums[i].year, albums[i].artist);
    }
    fclose(albumFile);

    FILE *songFile = fopen("songs.dat", "w");
    for (int i = 0; i < numSongs; i++) {
        fprintf(songFile, "%s,%d,%s\n", songs[i].name, songs[i].length, songs[i].album);
    }
    fclose(songFile);
}

int main()
{
    printf("C Music Library Management System\n");
    printf("Commands:\n");
    printf(" add album - Add a new album to the library\n");
    printf(" add song - Add a new song to the library\n");
    printf(" list albums - List all albums in the library\n");
    printf(" list songs - List all songs in the library\n");
    printf(" save - Save data to files\n");
    printf(" quit - Quit the program\n");

    while (1) {
        printf("> ");
        char input[10];
        fgets(input, 10, stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "add album") == 0) {
            addAlbum();
        } else if (strcmp(input, "add song") == 0) {
            addSong();
        } else if (strcmp(input, "list albums") == 0) {
            listAlbums();
        } else if (strcmp(input, "list songs") == 0) {
            listSongs();
        } else if (strcmp(input, "save") == 0) {
            saveData();
        } else if (strcmp(input, "quit") == 0) {
            exit(0);
        } else {
            printf("Invalid command\n");
        }
    }

    return 0;
}