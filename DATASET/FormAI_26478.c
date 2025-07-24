//FormAI DATASET v1.0 Category: Music Library Management System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 100

typedef struct{
    char title[50];
    char artist[50];
    float duration;
    int year;
} Song;

typedef struct{
    Song songs[MAX_SONGS];
    int num_songs;
} MusicLibrary;

int main(){

    MusicLibrary my_library;
    my_library.num_songs = 0;
    
    // Add song function
    void add_song(MusicLibrary* library){
        if (library->num_songs < MAX_SONGS){
            Song new_song;
            printf("Enter the song title: ");
            fgets(new_song.title, 50, stdin);
            printf("Enter the artist: ");
            fgets(new_song.artist, 50, stdin);
            printf("Enter the duration (in minutes): ");
            scanf("%f", &new_song.duration);
            printf("Enter the year: ");
            scanf("%d", &new_song.year);
            getchar(); // consume leftover newline character
            library->songs[library->num_songs++] = new_song;
            printf("Song added successfully!\n");
        }
        else{
            printf("Sorry, the library has reached its maximum capacity for songs.\n");
        }
    }

    // Modify song function
    void modify_song(MusicLibrary* library){
        int song_index;
        printf("Enter the index of the song you want to modify (from 1 to %d): ", library->num_songs);
        scanf("%d", &song_index);
        getchar(); // consume leftover newline character
        song_index -= 1; // adjust for 0-indexing
        if (song_index < 0 || song_index >= library->num_songs){
            printf("Invalid index.\n");
        }
        else{
            Song modified_song;
            printf("Enter the new song title: ");
            fgets(modified_song.title, 50, stdin);
            printf("Enter the new artist: ");
            fgets(modified_song.artist, 50, stdin);
            printf("Enter the new duration (in minutes): ");
            scanf("%f", &modified_song.duration);
            printf("Enter the new year: ");
            scanf("%d", &modified_song.year);
            getchar(); // consume leftover newline character
            library->songs[song_index] = modified_song;
            printf("Song modified successfully!\n");
        }
    }

    // Remove song function
    void remove_song(MusicLibrary* library){
        int song_index;
        printf("Enter the index of the song you want to remove (from 1 to %d): ", library->num_songs);
        scanf("%d", &song_index);
        getchar(); // consume leftover newline character
        song_index -= 1; // adjust for 0-indexing
        if (song_index < 0 || song_index >= library->num_songs){
            printf("Invalid index.\n");
        }
        else{
            for (int i = song_index; i < library->num_songs - 1; i++){
                library->songs[i] = library->songs[i+1];
            }
            library->num_songs--;
            printf("Song removed successfully!\n");
        }
    }

    // Print song function
    void print_song(Song song){
        printf("%s by %s | %0.2f minutes | released in %d\n", song.title, song.artist, song.duration, song.year);
    }

    // Print all songs function
    void print_all_songs(MusicLibrary* library){
        if (library->num_songs == 0){
            printf("The library is empty.\n");
        }
        else{
            for (int i = 0; i < library->num_songs; i++){
                printf("%d. ", i+1);
                print_song(library->songs[i]);
            }
        }
    }

    // Main menu loop
    int choice = -1;
    while (choice != 0){
        printf("\n\nMusic Library Management System:\n");
        printf("=================================\n");
        printf("1. Add song\n");
        printf("2. Modify song\n");
        printf("3. Remove song\n");
        printf("4. Print all songs\n");
        printf("0. Exit program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume leftover newline character
        switch(choice){
            case 1:
                add_song(&my_library);
                break;
            case 2:
                modify_song(&my_library);
                break;
            case 3:
                remove_song(&my_library);
                break;
            case 4:
                print_all_songs(&my_library);
                break;
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }

    return 0;
}