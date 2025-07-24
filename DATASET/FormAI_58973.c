//FormAI DATASET v1.0 Category: Music Library Management System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum size of name and song title
#define MAX_NAME_SIZE 20
#define MAX_SONG_SIZE 30

// Maximum number of songs and playlists
#define MAX_SONGS 100
#define MAX_PLAYLISTS 10

// Song structure
struct Song {
    char name[MAX_NAME_SIZE];
    char artist[MAX_NAME_SIZE];
    char title[MAX_SONG_SIZE];
    int duration;
};

// Playlist structure
struct Playlist {
    char name[MAX_NAME_SIZE];
    struct Song songs[MAX_SONGS];
    int num_songs;
};

// Music Library structure
struct MusicLibrary {
    struct Song songs[MAX_SONGS];
    int num_songs;
    struct Playlist playlists[MAX_PLAYLISTS];
    int num_playlists;
};

// Function prototypes
void print_menu();
void add_song(struct MusicLibrary *library);
void add_playlist(struct MusicLibrary *library);
void del_song(struct MusicLibrary *library);
void del_playlist(struct MusicLibrary *library);
void print_songs(struct MusicLibrary *library);
void print_playlists(struct MusicLibrary *library);
void print_playlist(struct Playlist *playlist);
void play_song(struct MusicLibrary *library);

int main() {
    struct MusicLibrary library;
    library.num_songs = 0;
    library.num_playlists = 0;
    int choice, song_index, playlist_index;
    
    do {
        print_menu();
        scanf("%d", &choice);
        getchar(); // consume newline character
        
        switch(choice) {
            case 1:
                add_song(&library);
                break;
            case 2:
                del_song(&library);
                break;
            case 3:
                print_songs(&library);
                break;
            case 4:
                add_playlist(&library);
                break;
            case 5:
                del_playlist(&library);
                break;
            case 6:
                print_playlists(&library);
                printf("Enter playlist number to play: ");
                scanf("%d", &playlist_index);
                getchar(); // consume newline character
                if (playlist_index >= 1 && playlist_index <= library.num_playlists) {
                    print_playlist(&library.playlists[playlist_index-1]);
                    play_song(&library);
                } else {
                    printf("Invalid playlist number!\n");
                }
                break;
            case 7:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice, try again.\n");
                break;
        }
    } while(choice != 7);
    
    return 0;
}

// Function to print the menu
void print_menu() {
    printf("========================\n");
    printf("   Music Library Menu   \n");
    printf("========================\n");
    printf(" 1. Add song\n");
    printf(" 2. Delete song\n");
    printf(" 3. Print all songs\n");
    printf(" 4. Add playlist\n");
    printf(" 5. Delete playlist\n");
    printf(" 6. Play playlist\n");
    printf(" 7. Quit\n");
    printf("Enter your choice: ");
}

// Function to add a song to the library
void add_song(struct MusicLibrary *library) {
    struct Song new_song;
    printf("Enter artist name: ");
    fgets(new_song.artist, MAX_NAME_SIZE, stdin);
    strtok(new_song.artist, "\n"); // remove newline character
    printf("Enter song title: ");
    fgets(new_song.title, MAX_SONG_SIZE, stdin);
    strtok(new_song.title, "\n"); // remove newline character
    printf("Enter song duration in seconds: ");
    scanf("%d", &new_song.duration);
    getchar(); // consume newline character
    
    // Check if song already exists in the library
    int i;
    for (i=0; i<library->num_songs; i++) {
        if (strcmp(library->songs[i].artist, new_song.artist) == 0 && strcmp(library->songs[i].title, new_song.title) == 0) {
            printf("Song already exists in the library!\n");
            return;
        }
    }
    
    // Add song to the library
    if (library->num_songs < MAX_SONGS) {
        strcpy(new_song.name, "Song");
        char num_str[4];
        sprintf(num_str, "%d", library->num_songs+1); // convert number to string
        strcat(new_song.name, num_str); // add number to song name
        library->songs[library->num_songs++] = new_song;
        printf("Song added to the library!\n");
    } else {
        printf("Maximum number of songs reached!\n");
    }
}

// Function to add a playlist to the library
void add_playlist(struct MusicLibrary *library) {
    struct Playlist new_playlist;
    
    if (library->num_playlists < MAX_PLAYLISTS) {
        printf("Enter playlist name: ");
        fgets(new_playlist.name, MAX_NAME_SIZE, stdin);
        strtok(new_playlist.name, "\n"); // remove newline character
        
        int choice;
        do {
            print_songs(library); // print all songs in the library
            printf("Select song to add to playlist (enter 0 to finish): ");
            scanf("%d", &choice);
            getchar(); // consume newline character
            
            if (choice >= 1 && choice <= library->num_songs) {
                new_playlist.songs[new_playlist.num_songs++] = library->songs[choice-1];
                printf("Song added to playlist!\n");
            } else if (choice != 0) {
                printf("Invalid song choice, try again.\n");
            }
        } while(choice != 0);
        
        if (new_playlist.num_songs == 0) {
            printf("Playlist must contain at least one song!\n");
        } else {
            library->playlists[library->num_playlists++] = new_playlist;
            printf("Playlist added to the library!\n");
        }
    } else {
        printf("Maximum number of playlists reached!\n");
    }
}

// Function to delete a song from the library
void del_song(struct MusicLibrary *library) {
    int i, j, found=0;
    char artist[MAX_NAME_SIZE], title[MAX_SONG_SIZE];
    
    printf("Enter artist name: ");
    fgets(artist, MAX_NAME_SIZE, stdin);
    strtok(artist, "\n"); // remove newline character
    printf("Enter song title: ");
    fgets(title, MAX_SONG_SIZE, stdin);
    strtok(title, "\n"); // remove newline character
    
    // Find song in the library
    for (i=0; i<library->num_songs; i++) {
        if (strcmp(library->songs[i].artist, artist) == 0 && strcmp(library->songs[i].title, title) == 0) {
            found = 1;
            break;
        }
    }
    
    if (found) {
        // Delete song from library
        for (j=i; j<library->num_songs-1; j++) {
            library->songs[j] = library->songs[j+1];
        }
        library->num_songs--;
        printf("Song deleted from the library!\n");
    } else {
        printf("Song not found in the library!\n");
    }
}

// Function to delete a playlist from the library
void del_playlist(struct MusicLibrary *library) {
    int i, j, found=0, index;
    char name[MAX_NAME_SIZE];
    
    printf("Enter playlist name: ");
    fgets(name, MAX_NAME_SIZE, stdin);
    strtok(name, "\n"); // remove newline character
    
    // Find playlist in the library
    for (i=0; i<library->num_playlists; i++) {
        if (strcmp(library->playlists[i].name, name) == 0) {
            found = 1;
            index = i;
            break;
        }
    }
    
    if (found) {
        // Delete playlist from library
        for (j=index; j<library->num_playlists-1; j++) {
            library->playlists[j] = library->playlists[j+1];
        }
        library->num_playlists--;
        printf("Playlist deleted from the library!\n");
    } else {
        printf("Playlist not found in the library!\n");
    }
}

// Function to print all songs in the library
void print_songs(struct MusicLibrary *library) {
    int i;
    printf("========================\n");
    printf("      All Songs (%d)      \n", library->num_songs);
    printf("========================\n");
    printf("No.  %-20s %-30s Duration\n", "Artist", "Title");
    for (i=0; i<library->num_songs; i++) {
        printf("%-3d  %-20s %-30s %d seconds\n", i+1, library->songs[i].artist, library->songs[i].title, library->songs[i].duration);
    }
}

// Function to print all playlists in the library
void print_playlists(struct MusicLibrary *library) {
    int i, j;
    printf("========================\n");
    printf("   All Playlists (%d)   \n", library->num_playlists);
    printf("========================\n");
    for (i=0; i<library->num_playlists; i++) {
        printf("%d. %s (%d songs)\n", i+1, library->playlists[i].name, library->playlists[i].num_songs);
        printf("No.  %-20s %-30s Duration\n", "Artist", "Title");
        for (j=0; j<library->playlists[i].num_songs; j++) {
            printf("%-3d  %-20s %-30s %d seconds\n", j+1, library->playlists[i].songs[j].artist, library->playlists[i].songs[j].title, library->playlists[i].songs[j].duration);
        }
    }
}

// Function to print a playlist
void print_playlist(struct Playlist *playlist) {
    int i;
    printf("========================\n");
    printf("   %s Playlist (%d songs)    \n", playlist->name, playlist->num_songs);
    printf("========================\n");
    printf("No.  %-20s %-30s Duration\n", "Artist", "Title");
    for (i=0; i<playlist->num_songs; i++) {
        printf("%-3d  %-20s %-30s %d seconds\n", i+1, playlist->songs[i].artist, playlist->songs[i].title, playlist->songs[i].duration);
    }
}

// Function to play a song
void play_song(struct MusicLibrary *library) {
    int choice;
    printf("Enter song number to play (enter 0 to stop): ");
    scanf("%d", &choice);
    getchar(); // consume newline character
    
    if (choice >= 1 && choice <= library->songs[choice-1].duration) {
        printf("Now playing \"%s - %s\" (%d seconds)...\n", library->songs[choice-1].artist, library->songs[choice-1].title, library->songs[choice-1].duration);
        // Code to play song here
        play_song(library);
    } else if (choice != 0) {
        printf("Invalid song choice, try again.\n");
        play_song(library);
    }
}