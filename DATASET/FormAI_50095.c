//FormAI DATASET v1.0 Category: Music Library Management System ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SONGS 100

struct song {
    char* title;
    char* artist;
    int duration;
};

void addSong(struct song* newSong, struct song** library, int* numSongs) {
    if(*numSongs >= MAX_SONGS) {
        printf("The library is full and cannot take any more songs.\n");
        return;
    }
    library[*numSongs] = newSong;
    *numSongs += 1;
}

void printLibrary(struct song** library, int numSongs) {
    printf("------------------------------\n");
    printf("Current Library of Songs\n");
    printf("------------------------------\n");

    for(int i=0; i<numSongs; i++) {
        printf("Title: %s\n", library[i]->title);
        printf("Artist: %s\n", library[i]->artist);
        printf("Duration: %d minutes\n", library[i]->duration);
        printf("------------------------------\n");
    }
}

int main() {
    struct song* library[MAX_SONGS];
    int numSongs = 0;

    printf("Welcome to the C Music Library Management System!\n");
    printf("You currently have %d songs in your library.\n", numSongs);
    printf("What would you like to do?\n");

    while(1) {
        char input[50];
        printf("Enter 'add' to add a new song,\n'print' to print the current library,\nor 'exit' to leave the program: ");
        fgets(input, 50, stdin);

        if(strcmp(input, "add\n") == 0) {
            printf("You have chosen to add a new song to the library.\n");
            struct song* newSong = malloc(sizeof(struct song));
            char title[50], artist[50];
            int duration;

            printf("Enter the title of the song: ");
            fgets(title, 50, stdin);
            title[strlen(title)-1] = '\0';
            newSong->title = malloc(strlen(title)+1);
            strcpy(newSong->title, title);

            printf("Enter the artist of the song: ");
            fgets(artist, 50, stdin);
            artist[strlen(artist)-1] = '\0';
            newSong->artist = malloc(strlen(artist)+1);
            strcpy(newSong->artist, artist);

            printf("Enter the duration of the song (in minutes): ");
            scanf("%d", &duration);
            getchar();
            while(duration <= 0) {
                printf("Invalid duration, please enter a positive number: ");
                scanf("%d", &duration);
                getchar();
            }
            newSong->duration = duration;

            addSong(newSong, library, &numSongs);
            printf("The song '%s' by '%s' has been added to the library.\n", newSong->title, newSong->artist);
        }
        else if(strcmp(input, "print\n") == 0) {
            printf("You have chosen to see the current library of songs.\n");
            printLibrary(library, numSongs);
        }
        else if(strcmp(input, "exit\n") == 0) {
            printf("Thank you for using the C Music Library Management System!\n");
            break;
        }
        else {
            printf("Invalid input, please try again.\n");
        }
    }

    for(int i=0; i<numSongs; i++) {
        free(library[i]->title);
        free(library[i]->artist);
        free(library[i]);
    }
    return 0;
}