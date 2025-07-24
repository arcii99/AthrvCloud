//FormAI DATASET v1.0 Category: Music Library Management System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

// Struct for song
struct song {
    char title[MAX_SIZE];
    char artist[MAX_SIZE];
    char genre[MAX_SIZE];
    int rating;
};

// Function prototypes
void addSong(struct song *library, int *size);
void deleteSong(struct song *library, int *size);
void searchSong(struct song *library, int size);
void showLibrary(struct song *library, int size);

int main() {
    struct song library[MAX_SIZE];
    int size = 0;
    int choice;

    printf("Welcome to the C Music Library Management System!\n");

    do {
        printf("\nMenu:\n");
        printf("1. Add Song\n");
        printf("2. Delete Song\n");
        printf("3. Search Song\n");
        printf("4. Show Library\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addSong(library, &size);
                break;
            case 2:
                deleteSong(library, &size);
                break;
            case 3:
                searchSong(library, size);
                break;
            case 4:
                showLibrary(library, size);
                break;
            case 5:
                printf("Exiting program...");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != 5);

    return 0;
}

void addSong(struct song *library, int *size) {
    if(*size == MAX_SIZE) {
        printf("Library is full. Cannot add song.\n");
        return;
    }

    struct song newSong;

    printf("Enter the song title: ");
    scanf("%s", newSong.title);
    printf("Enter the artist: ");
    scanf("%s", newSong.artist);
    printf("Enter the genre: ");
    scanf("%s", newSong.genre);
    printf("Enter the rating (1-5): ");
    scanf("%d", &newSong.rating);

    library[*size] = newSong;
    (*size)++;

    printf("Song has been added to the library.\n");
}

void deleteSong(struct song *library, int *size) {
    if(*size == 0) {
        printf("Library is empty. Cannot delete song.\n");
        return;
    }

    char title[MAX_SIZE];
    int index = -1;

    printf("Enter the title of the song to delete: ");
    scanf("%s", title);

    for(int i = 0; i < *size; i++) {
        if(strcmp(library[i].title, title) == 0) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        printf("Song not found in library.\n");
        return;
    }

    for(int i = index; i < *size - 1; i++) {
        library[i] = library[i+1];
    }

    (*size)--;

    printf("Song has been deleted from the library.\n");
}

void searchSong(struct song *library, int size) {
    if(size == 0) {
        printf("Library is empty. Cannot search for song.\n");
        return;
    }

    char title[MAX_SIZE];
    int index = -1;

    printf("Enter the title of the song to search for: ");
    scanf("%s", title);

    for(int i = 0; i < size; i++) {
        if(strcmp(library[i].title, title) == 0) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        printf("Song not found in library.\n");
        return;
    }

    printf("Title: %s\n", library[index].title);
    printf("Artist: %s\n", library[index].artist);
    printf("Genre: %s\n", library[index].genre);
    printf("Rating: %d\n", library[index].rating);
}

void showLibrary(struct song *library, int size) {
    if(size == 0) {
        printf("Library is empty. Nothing to show.\n");
        return;
    }

    printf("Library:\n");

    for(int i = 0; i < size; i++) {
        printf("Song %d:\n", i+1);
        printf("Title: %s\n", library[i].title);
        printf("Artist: %s\n", library[i].artist);
        printf("Genre: %s\n", library[i].genre);
        printf("Rating: %d\n", library[i].rating);
        printf("\n");
    }
}