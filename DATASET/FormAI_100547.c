//FormAI DATASET v1.0 Category: Music Library Management System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 100

typedef struct Song {
    char title[MAX_LENGTH];
    char artist[MAX_LENGTH];
    char album[MAX_LENGTH];
    int year;
    double duration;
    char file_path[MAX_LENGTH];
} Song;

typedef struct Playlist {
    char name[MAX_LENGTH];
    Song songs[MAX_LENGTH];
    int num_songs;
} Playlist;

typedef struct Library {
    Playlist playlists[MAX_LENGTH];
    int num_playlists;
} Library;

void clear_input_buffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void print_menu() {
    printf("1. Add Song\n");
    printf("2. Search Song\n");
    printf("3. Delete Song\n");
    printf("4. Create Playlist\n");
    printf("5. Add Song to Playlist\n");
    printf("6. Delete Song from Playlist\n");
    printf("7. Print All Songs\n");
    printf("8. Print All Playlists\n");
    printf("9. Exit\n");
}

void add_song(Library* library) {
    Song new_song;
    
    printf("Enter song title: ");
    fgets(new_song.title, MAX_LENGTH, stdin);
    if (new_song.title[strlen(new_song.title) - 1] == '\n') {
        new_song.title[strlen(new_song.title) - 1] = '\0';
    }
    
    printf("Enter artist: ");
    fgets(new_song.artist, MAX_LENGTH, stdin);
    if (new_song.artist[strlen(new_song.artist) - 1] == '\n') {
        new_song.artist[strlen(new_song.artist) - 1] = '\0';
    }
    
    printf("Enter album: ");
    fgets(new_song.album, MAX_LENGTH, stdin);
    if (new_song.album[strlen(new_song.album) - 1] == '\n') {
        new_song.album[strlen(new_song.album) - 1] = '\0';
    }
    
    printf("Enter year: ");
    scanf("%d", &new_song.year);
    clear_input_buffer();
    
    printf("Enter duration: ");
    scanf("%lf", &new_song.duration);
    clear_input_buffer();
    
    printf("Enter file path: ");
    fgets(new_song.file_path, MAX_LENGTH, stdin);
    if (new_song.file_path[strlen(new_song.file_path) - 1] == '\n') {
        new_song.file_path[strlen(new_song.file_path) - 1] = '\0';
    }
    
    printf("Song added to library.\n");
    
    // Add song to library
    for (int i = 0; i < library->num_playlists; i++) {
        library->playlists[i].songs[library->playlists[i].num_songs] = new_song;
        library->playlists[i].num_songs++;
    }
}

bool search_song(Library* library, char* query) {
    bool found_song = false;
    
    for (int i = 0; i < library->num_playlists; i++) {
        for (int j = 0; j < library->playlists[i].num_songs; j++) {
            if (strstr(library->playlists[i].songs[j].title, query) != NULL || strstr(library->playlists[i].songs[j].artist, query) != NULL) {
                printf("Found match in playlist %s:\n", library->playlists[i].name);
                printf("Title: %s\n", library->playlists[i].songs[j].title);
                printf("Artist: %s\n", library->playlists[i].songs[j].artist);
                printf("Album: %s\n", library->playlists[i].songs[j].album);
                printf("Year: %d\n", library->playlists[i].songs[j].year);
                printf("Duration: %.2f minutes\n", library->playlists[i].songs[j].duration);
                printf("File Path: %s\n", library->playlists[i].songs[j].file_path);
                printf("\n");
                found_song = true;
            }
        }
    }
    
    return found_song;
}

void delete_song(Library* library, char* query) {
    for (int i = 0; i < library->num_playlists; i++) {
        for (int j = 0; j < library->playlists[i].num_songs; j++) {
            if (strstr(library->playlists[i].songs[j].title, query) != NULL || strstr(library->playlists[i].songs[j].artist, query) != NULL) {
                printf("Song deleted from playlist %s:\n", library->playlists[i].name);
                printf("Title: %s\n", library->playlists[i].songs[j].title);
                printf("Artist: %s\n", library->playlists[i].songs[j].artist);
                printf("\n");
                
                // Shift all songs after the deleted song one index to the left
                for (int k = j + 1; k < library->playlists[i].num_songs; k++) {
                    library->playlists[i].songs[k - 1] = library->playlists[i].songs[k];
                }
                
                library->playlists[i].num_songs--;
            }
        }
    }
}

void create_playlist(Library* library) {
    Playlist new_playlist;
    
    printf("Enter playlist name: ");
    fgets(new_playlist.name, MAX_LENGTH, stdin);
    if (new_playlist.name[strlen(new_playlist.name) - 1] == '\n') {
        new_playlist.name[strlen(new_playlist.name) - 1] = '\0';
    }
    
    new_playlist.num_songs = 0;
    
    library->playlists[library->num_playlists] = new_playlist;
    library->num_playlists++;
    
    printf("Playlist created.\n");
}

void add_song_to_playlist(Library* library, char* song_title, char* playlist_name) {
    bool song_found = false;
    
    for (int i = 0; i < library->num_playlists; i++) {
        if (strcmp(library->playlists[i].name, playlist_name) == 0) {
            for (int j = 0; j < library->playlists[i].num_songs; j++) {
                if (strcmp(library->playlists[i].songs[j].title, song_title) == 0) {
                    printf("Song already in playlist %s.\n", playlist_name);
                    song_found = true;
                    break;
                }
            }
            
            if (!song_found) {
                for (int k = 0; k < library->num_playlists; k++) {
                    for (int l = 0; l < library->playlists[k].num_songs; l++) {
                        if (strcmp(library->playlists[k].songs[l].title, song_title) == 0) {
                            library->playlists[i].songs[library->playlists[i].num_songs] = library->playlists[k].songs[l];
                            library->playlists[i].num_songs++;
                            printf("Song added to playlist %s.\n", playlist_name);
                            return;
                        }
                    }
                }
                
                printf("Could not find song in library.\n");
            }
            
            break;
        }
    }
    
    if (!song_found) {
        printf("Could not find playlist.\n");
    }
}

void delete_song_from_playlist(Library* library, char* song_title, char* playlist_name) {
    bool song_found = false;
    
    for (int i = 0; i < library->num_playlists; i++) {
        if (strcmp(library->playlists[i].name, playlist_name) == 0) {
            for (int j = 0; j < library->playlists[i].num_songs; j++) {
                if (strcmp(library->playlists[i].songs[j].title, song_title) == 0) {
                    printf("Song deleted from playlist %s:\n", playlist_name);
                    printf("Title: %s\n", library->playlists[i].songs[j].title);
                    printf("Artist: %s\n", library->playlists[i].songs[j].artist);
                    printf("\n");
                    
                    // Shift all songs after the deleted song one index to the left
                    for (int k = j + 1; k < library->playlists[i].num_songs; k++) {
                        library->playlists[i].songs[k - 1] = library->playlists[i].songs[k];
                    }
                    
                    library->playlists[i].num_songs--;
                    
                    song_found = true;
                    break;
                }
            }
            
            if (!song_found) {
                printf("Could not find song in playlist %s.\n", playlist_name);
            }
            
            break;
        }
    }
    
    if (!song_found) {
        printf("Could not find playlist.\n");
    }
}

void print_all_songs(Library* library) {
    for (int i = 0; i < library->num_playlists; i++) {
        for (int j = 0; j < library->playlists[i].num_songs; j++) {
            printf("Title: %s\n", library->playlists[i].songs[j].title);
            printf("Artist: %s\n", library->playlists[i].songs[j].artist);
            printf("Album: %s\n", library->playlists[i].songs[j].album);
            printf("Year: %d\n", library->playlists[i].songs[j].year);
            printf("Duration: %.2f minutes\n", library->playlists[i].songs[j].duration);
            printf("File Path: %s\n", library->playlists[i].songs[j].file_path);
            printf("\n");
        }
    }
}

void print_all_playlists(Library* library) {
    for (int i = 0; i < library->num_playlists; i++) {
        printf("Playlist: %s\n", library->playlists[i].name);
        printf("Number of songs: %d\n", library->playlists[i].num_songs);
        for (int j = 0; j < library->playlists[i].num_songs; j++) {
            printf("Title: %s\n", library->playlists[i].songs[j].title);
        }
        printf("\n");
    }
}

int main() {
    Library library;
    library.num_playlists = 0;
    
    int choice = 0;
    
    while (choice != 9) {
        printf("=== Music Library Management System ===\n");
        print_menu();
        printf("Enter choice (1-9): ");
        
        scanf("%d", &choice);
        clear_input_buffer();
        
        switch (choice) {
            case 1:
                add_song(&library);
                break;
            case 2:
                printf("Enter search query: ");
                char query[MAX_LENGTH];
                fgets(query, MAX_LENGTH, stdin);
                if (query[strlen(query) - 1] == '\n') {
                    query[strlen(query) - 1] = '\0';
                }
                
                if (!search_song(&library, query)) {
                    printf("No matches found.\n");
                }
                break;
            case 3:
                printf("Enter song title or artist: ");
                char delete_query[MAX_LENGTH];
                fgets(delete_query, MAX_LENGTH, stdin);
                if (delete_query[strlen(delete_query) - 1] == '\n') {
                    delete_query[strlen(delete_query) - 1] = '\0';
                }
                
                delete_song(&library, delete_query);
                break;
            case 4:
                create_playlist(&library);
                break;
            case 5:
                printf("Enter song title: ");
                char song_title[MAX_LENGTH];
                fgets(song_title, MAX_LENGTH, stdin);
                if (song_title[strlen(song_title) - 1] == '\n') {
                    song_title[strlen(song_title) - 1] = '\0';
                }
                
                printf("Enter playlist name: ");
                char playlist_name[MAX_LENGTH];
                fgets(playlist_name, MAX_LENGTH, stdin);
                if (playlist_name[strlen(playlist_name) - 1] == '\n') {
                    playlist_name[strlen(playlist_name) - 1] = '\0';
                }
                
                add_song_to_playlist(&library, song_title, playlist_name);
                break;
            case 6:
                printf("Enter song title: ");
                char delete_song_title[MAX_LENGTH];
                fgets(delete_song_title, MAX_LENGTH, stdin);
                if (delete_song_title[strlen(delete_song_title) - 1] == '\n') {
                    delete_song_title[strlen(delete_song_title) - 1] = '\0';
                }
                
                printf("Enter playlist name: ");
                char delete_playlist_name[MAX_LENGTH];
                fgets(delete_playlist_name, MAX_LENGTH, stdin);
                if (delete_playlist_name[strlen(delete_playlist_name) - 1] == '\n') {
                    delete_playlist_name[strlen(delete_playlist_name) - 1] = '\0';
                }
                
                delete_song_from_playlist(&library, delete_song_title, delete_playlist_name);
                break;
            case 7:
                print_all_songs(&library);
                break;
            case 8:
                print_all_playlists(&library);
                break;
            case 9:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    
    return 0;
}