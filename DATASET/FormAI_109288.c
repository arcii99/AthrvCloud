//FormAI DATASET v1.0 Category: Music Library Management System ; Style: mathematical
#include <stdio.h>
#include <string.h>

struct music {
    char title[50];
    char artist[50];
    char album[50];
    int year;
};

void addMusic(struct music[], int);
void displayMusic(struct music[], int);
void searchMusic(struct music[], int, char[]);
void sortMusic(struct music[], int);

int main() {
    printf("Library Management System\n\n");

    int option, size = 0;
    struct music musicList[100];

    do {
        printf("1. Add Music\n");
        printf("2. Display Music\n");
        printf("3. Search Music\n");
        printf("4. Sort Music\n");
        printf("0. Exit Program\n");
        printf("\nEnter option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                addMusic(musicList, size);
                size++;
                break;
            case 2:
                displayMusic(musicList, size);
                break;
            case 3:
                char searchQuery[50];
                printf("Enter title/artist/album to search: ");
                scanf("%s", searchQuery);
                searchMusic(musicList, size, searchQuery);
                break;
            case 4:
                sortMusic(musicList, size);
                break;
            case 0:
                printf("\nProgram exited.\n");
                break;
            default:
                printf("\nInvalid option selected.\n");
                break;
        }
    } while(option != 0);

    return 0;
}

void addMusic(struct music musicList[], int size) {
    printf("\nAdd Music\n");
    printf("---------\n");

    printf("Enter title: ");
    scanf("%s", musicList[size].title);

    printf("Enter artist: ");
    scanf("%s", musicList[size].artist);

    printf("Enter album: ");
    scanf("%s", musicList[size].album);

    printf("Enter year: ");
    scanf("%d", &musicList[size].year);

    printf("\nMusic added successfully.\n");
}

void displayMusic(struct music musicList[], int size) {
    if(size == 0) {
        printf("\nNo music added yet.\n");
        return;
    }

    printf("\nMusic Library\n");
    printf("--------------\n");

    printf("%-30s%-20s%-20s%-10s\n", "Title", "Artist", "Album", "Year");
    printf("--------------------------------------------------------\n");

    for(int i=0; i<size; i++) {
        printf("%-30s%-20s%-20s%-10d\n", musicList[i].title, musicList[i].artist, musicList[i].album, musicList[i].year);
    }

    printf("--------------------------------------------------------\n\n");
}

void searchMusic(struct music musicList[], int size, char searchQuery[]) {
    printf("\nSearch Result\n");
    printf("--------------\n");

    printf("%-30s%-20s%-20s%-10s\n", "Title", "Artist", "Album", "Year");
    printf("--------------------------------------------------------\n");

    for(int i=0; i<size; i++) {
        if(strstr(musicList[i].title, searchQuery) != NULL || strstr(musicList[i].artist, searchQuery) != NULL || strstr(musicList[i].album, searchQuery) != NULL) {
            printf("%-30s%-20s%-20s%-10d\n", musicList[i].title, musicList[i].artist, musicList[i].album, musicList[i].year);
        }
    }

    printf("--------------------------------------------------------\n\n");
}

void sortMusic(struct music musicList[], int size) {
    for(int i=0; i<size-1; i++) {
        for(int j=i+1; j<size; j++) {
            if(strcmp(musicList[i].title, musicList[j].title) > 0) {
                struct music temp = musicList[i];
                musicList[i] = musicList[j];
                musicList[j] = temp;
            }
        }
    }

    printf("\nMusic sorted successfully.\n");
}