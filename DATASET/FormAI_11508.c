//FormAI DATASET v1.0 Category: Music Library Management System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 1000
#define MAX_TITLE 30
#define MAX_ARTIST 30
#define MAX_GENRE 20

typedef struct song
{
    char title[MAX_TITLE];
    char artist[MAX_ARTIST];
    char genre[MAX_GENRE];
} song_t;

int main()
{
    song_t library[MAX_SONGS];
    int num_songs = 0;
    char input[MAX_TITLE];
    
    printf("Welcome to the Paranoid Music Library Management System!\n");
    
    while (1)
    {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a song\n");
        printf("2. Remove a song\n");
        printf("3. View library\n");
        printf("4. Exit\n");
        
        fgets(input, MAX_TITLE, stdin);
        int choice = atoi(input);
        
        switch (choice)
        {
            case 1: // add song
                if (num_songs == MAX_SONGS)
                {
                    printf("Sorry, the library is full.\n");
                    break;
                }
                printf("Title: ");
                fgets(library[num_songs].title, MAX_TITLE, stdin);
                printf("Artist: ");
                fgets(library[num_songs].artist, MAX_ARTIST, stdin);
                printf("Genre: ");
                fgets(library[num_songs].genre, MAX_GENRE, stdin);
                library[num_songs].title[strcspn(library[num_songs].title, "\n")] = 0;
                library[num_songs].artist[strcspn(library[num_songs].artist, "\n")] = 0;
                library[num_songs].genre[strcspn(library[num_songs].genre, "\n")] = 0;
                num_songs++;
                printf("Song added to library.\n");
                break;
            case 2: // remove song
                printf("Title: ");
                fgets(input, MAX_TITLE, stdin);
                input[strcspn(input, "\n")] = 0;
                for (int i = 0; i < num_songs; i++)
                {
                    if (strcmp(library[i].title, input) == 0)
                    {
                        for (int j = i; j < num_songs - 1; j++)
                        {
                            library[j] = library[j+1];
                        }
                        num_songs--;
                        printf("Song removed from library.\n");
                        break;
                    }
                    if (i == num_songs - 1)
                    {
                        printf("Song not found in library.\n");
                    }
                }
                break;
            case 3: // view library
                if (num_songs == 0)
                {
                    printf("Library is empty.\n");
                    break;
                }
                for (int i = 0; i < num_songs; i++)
                {
                    printf("%s - %s (%s)\n", library[i].title, library[i].artist, library[i].genre);
                }
                break;
            case 4: // exit
                printf("Goodbye.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    
    return 0;
}