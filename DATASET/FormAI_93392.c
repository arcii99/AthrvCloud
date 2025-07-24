//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct song {
    char name[100];
    char artist[100];
    char album[100];
    int year;
    int duration;
};

int num_songs = 0;

void add_song(struct song* library, char* name, char* artist, char* album, int year, int duration) {
    strcpy(library[num_songs].name, name);
    strcpy(library[num_songs].artist, artist);
    strcpy(library[num_songs].album, album);
    library[num_songs].year = year;
    library[num_songs].duration = duration;
    num_songs++;
}

void display_song(struct song song) {
    printf("Name: %s\n", song.name);
    printf("Artist: %s\n", song.artist);
    printf("Album: %s\n", song.album);
    printf("Year: %d\n", song.year);
    printf("Duration: %d seconds\n\n", song.duration);
}

void display_library(struct song* library) {
    printf("-----CURRENT LIBRARY-----\n\n");
    for (int i = 0; i < num_songs; i++) {
        display_song(library[i]);
    }
}

void search_songs(struct song* library, char* search_term) {
    printf("-----SEARCH RESULTS-----\n\n");
    for (int i = 0; i < num_songs; i++) {
        if (strstr(library[i].name, search_term) != NULL || strstr(library[i].artist, search_term) != NULL || strstr(library[i].album, search_term) != NULL) {
            display_song(library[i]);
        }
    }
}

void remove_song(struct song* library, char* name) {
    for (int i = 0; i < num_songs; i++) {
        if (strcmp(library[i].name, name) == 0) {
            for (int j = i; j < num_songs - 1; j++) {
                library[j] = library[j + 1];
            }
            num_songs--;
            printf("%s has been removed from the library.\n\n", name);
            return;
        }
    }
    printf("%s was not found in the library.\n\n", name);
}

int main() {
    struct song library[100];
    add_song(library, "Moonlight Sonata", "Ludwig van Beethoven", "The Best of Beethoven", 1801, 346);
    add_song(library, "Eine kleine Nachtmusik", "Wolfgang Amadeus Mozart", "The Best of Mozart", 1787, 354);
    add_song(library, "Claire de Lune", "Claude Debussy", "Essential Debussy", 1890, 258);
    add_song(library, "The Four Seasons", "Antonio Vivaldi", "Vivaldi: The Complete Works", 1725, 526);
    add_song(library, "Brandenburg Concertos", "Johann Sebastian Bach", "Bach: Complete Works", 1721, 1573);

    int choice;
    char name[100], artist[100], album[100], search_term[100];
    int year, duration;
    while (1) {
        printf("Enter 1 to add a song to the library.\n");
        printf("Enter 2 to display the current library.\n");
        printf("Enter 3 to search for a song.\n");
        printf("Enter 4 to remove a song.\n");
        printf("Enter 5 to exit.\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\nEnter song name: ");
            scanf(" %[^\n]s", name);
            printf("Enter artist name: ");
            scanf(" %[^\n]s", artist);
            printf("Enter album name: ");
            scanf(" %[^\n]s", album);
            printf("Enter year: ");
            scanf("%d", &year);
            printf("Enter duration in seconds: ");
            scanf("%d", &duration);
            add_song(library, name, artist, album, year, duration);
            printf("%s by %s has been added to the library.\n\n", name, artist);
            break;
        case 2:
            display_library(library);
            break;
        case 3:
            printf("\nEnter search term: ");
            scanf(" %[^\n]s", search_term);
            search_songs(library, search_term);
            break;
        case 4:
            printf("\nEnter song name to remove: ");
            scanf(" %[^\n]s", name);
            remove_song(library, name);
            break;
        case 5:
            exit(0);
        default:
            printf("\nInvalid choice. Please try again.\n\n");
            break;
        }
    }

    return 0;
}