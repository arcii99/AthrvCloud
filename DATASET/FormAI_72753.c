//FormAI DATASET v1.0 Category: Music Library Management System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_ARTIST_LENGTH 50
#define MAX_ALBUM_LENGTH 50
#define MAX_TRACKS 100

// Define a structure for a music album
struct album {
    char title[MAX_TITLE_LENGTH];
    char artist[MAX_ARTIST_LENGTH];
    char album[MAX_ALBUM_LENGTH];
    int year;
    int num_tracks;
    char tracks[MAX_TRACKS][MAX_TITLE_LENGTH];
};

// Define function prototypes
void add_album(struct album *lib, int *num_albums);
void remove_album(struct album *lib, int *num_albums);
void display_library(struct album *lib, int num_albums);
void search_library(struct album *lib, int num_albums);

int main() {
    struct album library[MAX_TRACKS];
    int num_albums = 0;
    char command[10];
    
    printf("Welcome to the C Music Library Management System!\n");
    
    // Loop until the user enters "quit"
    while(1) {
        printf("Enter a command ('add', 'remove', 'display', 'search', 'quit'):");
        scanf("%s", command);
        
        if(strcmp(command, "add") == 0) {
            add_album(library, &num_albums);
        }
        else if(strcmp(command, "remove") == 0) {
            remove_album(library, &num_albums);
        }
        else if(strcmp(command, "display") == 0) {
            display_library(library, num_albums);
        }
        else if(strcmp(command, "search") == 0) {
            search_library(library, num_albums);
        }
        else if(strcmp(command, "quit") == 0) {
            printf("Exiting from the system. Goodbye!\n");
            break;
        }
        else {
            printf("Invalid command. Please try again.\n");
        }
    }
    
    return 0;
}

void add_album(struct album *lib, int *num_albums) {
    char temp_tracks[MAX_TRACKS][MAX_TITLE_LENGTH];
    struct album new_album;
    
    printf("Enter the title of the album: ");
    scanf("%s", new_album.title);
    
    printf("Enter the name of the artist: ");
    scanf("%s", new_album.artist);
    
    printf("Enter the name of the album: ");
    scanf("%s", new_album.album);
    
    printf("Enter the year of release: ");
    scanf("%d", &new_album.year);
    
    printf("Enter the number of tracks: ");
    scanf("%d", &new_album.num_tracks);
    
    for(int i = 0; i < new_album.num_tracks; i++) {
        printf("Enter the name of track %d: ", i+1);
        scanf("%s", temp_tracks[i]);
    }
    
    for(int i = 0; i < new_album.num_tracks; i++) {
        strcpy(new_album.tracks[i], temp_tracks[i]);
    }
    
    lib[*num_albums] = new_album;
    (*num_albums)++;
    
    printf("Album added successfully!\n");
}

void remove_album(struct album *lib, int *num_albums) {
    char album_title[MAX_TITLE_LENGTH];
    int index_to_remove = -1;
    
    printf("Enter the title of the album to remove: ");
    scanf("%s", album_title);
    
    // Search for the album in the library
    for(int i = 0; i < *num_albums; i++) {
        if(strcmp(lib[i].title, album_title) == 0) {
            index_to_remove = i;
            break;
        }
    }
    
    if(index_to_remove == -1) {
        printf("Album not found.\n");
    }
    else {
        // Shift all albums after the one to be removed back by one index
        for(int i = index_to_remove; i < *num_albums-1; i++) {
            lib[i] = lib[i+1];
        }
        
        (*num_albums)--;
        
        printf("Album removed successfully!\n");
    }
}

void display_library(struct album *lib, int num_albums) {
    if(num_albums == 0) {
        printf("The library is empty.\n");
    }
    else {
        printf("Title\t\tArtist\t\tAlbum\t\tYear\t#Tracks\tTracks\n");
        printf("--------------------------------------------------------------------------------\n");
        for(int i = 0; i < num_albums; i++) {
            printf("%s\t\t%s\t\t%s\t\t%d\t%d\t", lib[i].title, lib[i].artist, lib[i].album, lib[i].year, lib[i].num_tracks);
            for(int j = 0; j < lib[i].num_tracks; j++) {
                printf("%s ", lib[i].tracks[j]);
            }
            printf("\n");
        }
    }
}

void search_library(struct album *lib, int num_albums) {
    char search_term[MAX_TITLE_LENGTH];
    int num_matches = 0;
    
    printf("Enter a search term: ");
    scanf("%s", search_term);
    
    printf("Title\t\tArtist\t\tAlbum\t\tYear\t#Tracks\tTracks\n");
    printf("--------------------------------------------------------------------------------\n");
    
    for(int i = 0; i < num_albums; i++) {
        if(strstr(lib[i].title, search_term) != NULL || strstr(lib[i].artist, search_term) != NULL || strstr(lib[i].album, search_term) != NULL) {
            printf("%s\t\t%s\t\t%s\t\t%d\t%d\t", lib[i].title, lib[i].artist, lib[i].album, lib[i].year, lib[i].num_tracks);
            for(int j = 0; j < lib[i].num_tracks; j++) {
                printf("%s ", lib[i].tracks[j]);
            }
            printf("\n");
            num_matches++;
        }
    }
    
    if(num_matches == 0) {
        printf("No matches found.\n");
    }
    else {
        printf("%d matches found.\n", num_matches);
    }
}