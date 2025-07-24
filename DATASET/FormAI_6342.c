//FormAI DATASET v1.0 Category: Music Library Management System ; Style: secure
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100
#define MAX_TITLE_LENGTH 50
#define MAX_ARTIST_LENGTH 30
#define MAX_GENRE_LENGTH 20
#define MAX_INVENTORY 9999

typedef struct song {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    int inventory;
} Song;

Song music_library[MAX_SONGS];
int num_songs = 0;

bool add_song(char title[], char artist[], char genre[], int inventory) {
    if (num_songs == MAX_SONGS || inventory > MAX_INVENTORY) {
        printf("Error: Could not add song to library.\n");
        return false;
    }

    Song new_song;
    strcpy(new_song.title, title);
    strcpy(new_song.artist, artist);
    strcpy(new_song.genre, genre);
    new_song.inventory = inventory;

    music_library[num_songs] = new_song;
    num_songs++;

    printf("Song added successfully!\n");
    return true;
}

void remove_song(int index) {
    if (index < 0 || index >= num_songs) {
        printf("Error: Invalid index.\n");
        return;
    }

    for (int i = index; i < num_songs - 1; i++) {
        music_library[i] = music_library[i + 1];
    }

    num_songs--;
    printf("Song removed successfully!\n");
}

void search_by_title(char title[]) {
    bool song_found = false;

    for (int i = 0; i < num_songs; i++) {
        if (strcmp(music_library[i].title, title) == 0) {
            printf("Title: %s\n", music_library[i].title);
            printf("Artist: %s\n", music_library[i].artist);
            printf("Genre: %s\n", music_library[i].genre);
            printf("Inventory: %d\n", music_library[i].inventory);
            song_found = true;
        }
    }

    if (!song_found) {
        printf("No matching songs found.\n");
    }
}

void print_all_songs() {
    if (num_songs == 0) {
        printf("No songs in library.\n");
        return;
    }

    printf("%-35s %-25s %-15s %-10s\n", "Title", "Artist", "Genre", "Inventory");
    printf("-----------------------------------------------------------------\n");
    for (int i = 0; i < num_songs; i++) {
        printf("%-35s %-25s %-15s %-10d\n", music_library[i].title, music_library[i].artist, music_library[i].genre, music_library[i].inventory);
    }
}

int main() {
    add_song("Don't Start Now", "Dua Lipa", "Pop", 100);
    add_song("Blinding Lights", "The Weeknd", "R&B", 50);
    add_song("Watermelon Sugar", "Harry Styles", "Pop", 75);
    add_song("Levitating", "Dua Lipa", "Pop", 150);

    print_all_songs();

    remove_song(1);

    printf("After removing a song:\n");

    print_all_songs();

    search_by_title("Watermelon Sugar");

    return 0;
}