//FormAI DATASET v1.0 Category: Music Library Management System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Song
{
    char title[50];
    char artist[30];
    char album[30];
    int year;
} Song;

Song musicLibrary[100];
int songCount = 0;

int main()
{
    int choice = 0;
    do
    {
        printf("Welcome to the C Music Library Management System\n");
        printf("1. Add Song\n");
        printf("2. View Song\n");
        printf("3. Search Song\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addSong();
                break;
            case 2:
                viewLibrary();
                break;
            case 3:
                searchSong();
                break;
            case 4:
                printf("Thank you for using the C Music Library Management System\n");
                break;
            default:
                printf("Invalid choice, please try again\n");
                break;
        }
    } while (choice != 4);
    return 0;
}

void addSong()
{
    Song s;
    printf("Enter song title: ");
    scanf("%s", s.title);
    printf("Enter song artist: ");
    scanf("%s", s.artist);
    printf("Enter song album: ");
    scanf("%s", s.album);
    printf("Enter song year: ");
    scanf("%d", &s.year);
    musicLibrary[songCount] = s;
    songCount++;
    printf("Song added successfully!\n");
}

void viewLibrary()
{
    if (songCount > 0)
    {
        printf("Music Library:\n");
        printf("Title\tArtist\tAlbum\tYear\n");
        for (int i = 0; i < songCount; i++)
        {
            printf("%s\t%s\t%s\t%d\n", musicLibrary[i].title, musicLibrary[i].artist, musicLibrary[i].album, musicLibrary[i].year);
        }
    }
    else
    {
        printf("No songs found in the music library, please add some songs\n");
    }
}

void searchSong()
{
    char searchTitle[50];
    printf("Enter song title to search: ");
    scanf("%s", searchTitle);
    int found = 0;
    for (int i = 0; i < songCount; i++)
    {
        if (strcmp(musicLibrary[i].title, searchTitle) == 0)
        {
            printf("Song found:\n");
            printf("Title\tArtist\tAlbum\tYear\n");
            printf("%s\t%s\t%s\t%d\n", musicLibrary[i].title, musicLibrary[i].artist, musicLibrary[i].album, musicLibrary[i].year);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Song not found in the music library\n");
    }
}