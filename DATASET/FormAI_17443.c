//FormAI DATASET v1.0 Category: Music Library Management System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

/* Define a struct to hold information about an album */
struct Album {
    char title[MAX_SIZE];
    char artist[MAX_SIZE];
    char genre[MAX_SIZE];
    int year;
};

/* Define a function to create a new album */
struct Album create_album(char* title, char* artist, char* genre, int year) {
    struct Album new_album;
    strcpy(new_album.title, title);
    strcpy(new_album.artist, artist);
    strcpy(new_album.genre, genre);
    new_album.year = year;
    return new_album;
}

/* Define a function to add an album to the library */
void add_album(struct Album* library, struct Album album, int* num_albums) {
    if (*num_albums >= MAX_SIZE) {
        printf("Library is full!\n");
        return;
    }
    library[*num_albums] = album;
    *num_albums += 1;
    printf("Album added to library.\n");
}

/* Define a function to print all albums in the library */
void print_library(struct Album* library, int num_albums) {
    for (int i = 0; i < num_albums; i++) {
        printf("%d. %s - %s (%s) - %d\n",
            i + 1,
            library[i].artist,
            library[i].title,
            library[i].genre,
            library[i].year);
    }
}

/* Define a function to search for an album by title */
void search_by_title(struct Album* library, int num_albums, char* title) {
    for (int i = 0; i < num_albums; i++) {
        if (strcmp(library[i].title, title) == 0) {
            printf("%s - %s (%s) - %d\n",
                library[i].artist,
                library[i].title,
                library[i].genre,
                library[i].year);
            return;
        }
    }
    printf("Album not found.\n");
}

/* Define a function to search for an album by artist */
void search_by_artist(struct Album* library, int num_albums, char* artist) {
    for (int i = 0; i < num_albums; i++) {
        if (strcmp(library[i].artist, artist) == 0) {
            printf("%s - %s (%s) - %d\n",
                library[i].artist,
                library[i].title,
                library[i].genre,
                library[i].year);
        }
    }
}

/* Define a function to search for an album by year */
void search_by_year(struct Album* library, int num_albums, int year) {
    for (int i = 0; i < num_albums; i++) {
        if (library[i].year == year) {
            printf("%s - %s (%s) - %d\n",
                library[i].artist,
                library[i].title,
                library[i].genre,
                library[i].year);
        }
    }
}

int main() {
    /* Initialize an empty library */
    struct Album library[MAX_SIZE];
    int num_albums = 0;

    /* Add some example albums */
    add_album(&library, create_album("Thriller", "Michael Jackson", "Pop", 1982), &num_albums);
    add_album(&library, create_album("Abbey Road", "The Beatles", "Rock", 1969), &num_albums);
    add_album(&library, create_album("Kind of Blue", "Miles Davis", "Jazz", 1959), &num_albums);

    /* Print the library */
    printf("Library Contents:\n");
    print_library(library, num_albums);

    /* Search for an album by title */
    printf("\nSearch for an album by title:\n");
    search_by_title(library, num_albums, "Thriller");

    /* Search for albums by artist */
    printf("\nSearch for albums by artist:\n");
    search_by_artist(library, num_albums, "The Beatles");

    /* Search for albums by year */
    printf("\nSearch for albums by year:\n");
    search_by_year(library, num_albums, 1982);

    return 0;
}