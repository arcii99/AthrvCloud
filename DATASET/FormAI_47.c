//FormAI DATASET v1.0 Category: Music Library Management System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100

typedef struct Node {
    char *artist;
    char *title;
    struct Node *next;
} Node;

void print_menu() {
    printf("\n********** C MUSIC LIBRARY MANAGEMENT SYSTEM **********\n");
    printf("1. Add Song\n");
    printf("2. View All Songs\n");
    printf("3. Search Song\n");
    printf("4. Remove Song\n");
    printf("5. Exit\n\n");
}

void add_song(Node *songs[], char *artist, char *title) {
    int index = 0;
    while (songs[index] != NULL && index < MAX_SONGS) {
        index++;
    }
    if (index >= MAX_SONGS) {
        printf("Error: Music library is full. Could not add song.\n");
        return;
    }
    Node *new_song = malloc(sizeof(Node));
    new_song->artist = malloc(sizeof(char) * (strlen(artist) + 1));
    new_song->title = malloc(sizeof(char) * (strlen(title) + 1));
    strcpy(new_song->artist, artist);
    strcpy(new_song->title, title);
    new_song->next = NULL;
    songs[index] = new_song;
    printf("Song added successfully.\n");
}

void view_all_songs(Node *songs[]) {
    printf("\n********** VIEW ALL SONGS **********\n");
    int count = 0;
    for (int i = 0; i < MAX_SONGS; i++) {
        if (songs[i] != NULL) {
            printf("%d. %s - %s\n", i+1, songs[i]->artist, songs[i]->title);
            count++;
        }
    }
    if (count == 0) {
        printf("No songs found.\n");
    }
}

void search_song(Node *songs[], char *search_term) {
    printf("\n********** SEARCH SONG **********\n");
    int count = 0;
    for (int i = 0; i < MAX_SONGS; i++) {
        if (songs[i] != NULL && (strstr(songs[i]->artist, search_term) || strstr(songs[i]->title, search_term))) {
            printf("%d. %s - %s\n", i+1, songs[i]->artist, songs[i]->title);
            count++;
        }
    }
    if (count == 0) {
        printf("No songs found.\n");
    }
}

void remove_song(Node *songs[], int index) {
    if (songs[index-1] == NULL) {
        printf("Error: Song does not exist.\n");
        return;
    }
    printf("Are you sure you want to remove the following song?\n");
    printf("%d. %s - %s\n", index, songs[index-1]->artist, songs[index-1]->title);
    printf("1. Yes\n");
    printf("2. No\n");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        free(songs[index-1]->artist);
        free(songs[index-1]->title);
        free(songs[index-1]);
        songs[index-1] = NULL;
        printf("Song removed successfully.\n");
    }
    else {
        printf("Song removal cancelled.\n");
    }
}

int main() {
    Node *songs[MAX_SONGS];
    for (int i = 0; i < MAX_SONGS; i++) {
        songs[i] = NULL;
    }
    int choice;
    char artist[100];
    char title[100];
    char search_term[100];
    int index;

    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\nEnter artist name: ");
                scanf("%s", artist);
                printf("Enter song title: ");
                scanf("%s", title);
                add_song(songs, artist, title);
                break;
            case 2:
                view_all_songs(songs);
                break;
            case 3:
                printf("\nEnter search term: ");
                scanf("%s", search_term);
                search_song(songs, search_term);
                break;
            case 4:
                printf("\nEnter song number to remove: ");
                scanf("%d", &index);
                remove_song(songs, index);
                break;
            case 5:
                printf("\nThank you for using C Music Library Management System.\n");
                break;
            default:
                printf("\nInvalid choice. Please enter a valid choice.\n");
        }
    } while (choice != 5);

    return 0;
}