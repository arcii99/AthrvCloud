//FormAI DATASET v1.0 Category: Music Library Management System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct music_library{
    char song_name[100];
    char artist[50];
    char album_name[50];
    int release_year;
};

int main(){
    int choice, num_songs;
  
    printf("Welcome to the Music Library Management System!\n");
    printf("How many songs do you want to manage?\n");
    scanf("%d", &num_songs);
  
    struct music_library songs[num_songs];
  
    while(1){
        printf("\nPlease make a choice:\n");
        printf("1. Add a song\n");
        printf("2. Display all songs\n");
        printf("3. Search for a song\n");
        printf("4. Exit the program\n");
        scanf("%d", &choice);
      
        switch(choice){
            case 1: // Add a song
                if(sizeof(songs)/sizeof(songs[0]) == num_songs){
                    printf("\nSorry, the library is full!\n");
                    break;
                }
                else{
                    printf("\nEnter the song name: ");
                    scanf("%s", songs[num_songs].song_name);
                    printf("Enter the artist name: ");
                    scanf("%s", songs[num_songs].artist);
                    printf("Enter the album name: ");
                    scanf("%s", songs[num_songs].album_name);
                    printf("Enter the release year: ");
                    scanf("%d", &songs[num_songs].release_year);
                    num_songs++;
                    printf("\nSong added successfully!\n");
                    break;
                }
            case 2: // Display all songs
                printf("\nSong Name\tArtist\tAlbum\tRelease Year\n");
                for(int i=0; i<num_songs; i++){
                    printf("%s\t%s\t%s\t%d\n", songs[i].song_name, songs[i].artist, songs[i].album_name, songs[i].release_year);
                }
                break;
            case 3: // Search for a song
                char search_song[100];
                printf("\nEnter the name of the song you want to search: ");
                scanf("%s", search_song);
                int found = 0;
                for(int i=0; i<num_songs; i++){
                    if(strcmp(search_song, songs[i].song_name) == 0){
                        printf("\nSong found!\n");
                        printf("%s\t%s\t%s\t%d\n", songs[i].song_name, songs[i].artist, songs[i].album_name, songs[i].release_year);
                        found = 1;
                        break;
                    }
                }
                if(found == 0)
                    printf("\nSong not found!\n");
                break;
            case 4: // Exit the program
                printf("\nThank you for using the Music Library Management System!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again!\n");
                break;
        }
    }
    return 0;
}