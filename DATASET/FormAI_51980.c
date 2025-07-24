//FormAI DATASET v1.0 Category: Music Library Management System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Song {
    char name[50];
    char artist[50];
    int duration;
    struct Song *next;
};

struct Playlist {
    char name[50];
    int num_songs;
    struct Song *head_song;
    struct Song *tail_song;
    struct Playlist *next;
};

struct Artist {
    char name[50];
    struct Song *head_song;
    int num_songs;
    struct Artist *next;
};

struct All {
    struct Song *head_song;
    struct Playlist *head_playlist;
    struct Artist *head_artist;
};

struct All all_data;

void add_song(char name[], char artist[], int duration) {
    struct Song *new_song = (struct Song*) malloc(sizeof(struct Song));
    strcpy(new_song->name, name);
    strcpy(new_song->artist, artist);
    new_song->duration = duration;
    new_song->next = NULL;
    
    if (all_data.head_song == NULL) {
        all_data.head_song = new_song;
    }
    else {
        struct Song *temp = all_data.head_song;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_song;
    }
    
    add_artist(new_song->artist);
}

void add_playlist(char name[]) {
    struct Playlist *new_playlist = (struct Playlist*) malloc(sizeof(struct Playlist));
    strcpy(new_playlist->name, name);
    new_playlist->num_songs = 0;
    new_playlist->head_song = NULL;
    new_playlist->tail_song = NULL;
    new_playlist->next = NULL;
    
    if (all_data.head_playlist == NULL) {
        all_data.head_playlist = new_playlist;
    }
    else {
        struct Playlist *temp = all_data.head_playlist;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_playlist;
    }
}

void add_artist(char name[]) {
    struct Artist *new_artist = (struct Artist*) malloc(sizeof(struct Artist));
    strcpy(new_artist->name, name);
    new_artist->num_songs = 1;
    new_artist->head_song = all_data.head_song;
    new_artist->next = NULL;
    
    if (all_data.head_artist == NULL) {
        all_data.head_artist = new_artist;
    }
    else {
        struct Artist *temp = all_data.head_artist;
        while (temp != NULL) {
            if (strcmp(temp->name, name) == 0) {
                temp->num_songs++;
                return;
            }
            else if (temp->next == NULL) {
                temp->next = new_artist;
                return;
            }
            temp = temp->next;
        }
    }
}

void add_song_to_playlist(char song_name[], char playlist_name[]) {
    struct Song *temp_song = all_data.head_song;
    while (temp_song != NULL) {
        if (strcmp(temp_song->name, song_name) == 0) {
            break;
        }
        temp_song = temp_song->next;
    }
    
    struct Playlist *temp_playlist = all_data.head_playlist;
    while (temp_playlist != NULL) {
        if (strcmp(temp_playlist->name, playlist_name) == 0) {
            break;
        }
        temp_playlist = temp_playlist->next;
    }
    
    if (temp_song != NULL && temp_playlist != NULL) {
        struct Song *new_song = (struct Song*) malloc(sizeof(struct Song));
        strcpy(new_song->name, temp_song->name);
        strcpy(new_song->artist, temp_song->artist);
        new_song->duration = temp_song->duration;
        new_song->next = NULL;
        
        if (temp_playlist->head_song == NULL) {
            temp_playlist->head_song = new_song;
            temp_playlist->tail_song = new_song;
        }
        else {
            temp_playlist->tail_song->next = new_song;
            temp_playlist->tail_song = new_song;
        }
        
        temp_playlist->num_songs++;
    }
}

void display_songs() {
    struct Song *temp = all_data.head_song;
    printf("Name \t Artist \t Duration\n");
    while (temp != NULL) {
        printf("%s \t %s \t %d\n", temp->name, temp->artist, temp->duration);
        temp = temp->next;
    }
}

void display_playlists() {
    struct Playlist *temp_playlist = all_data.head_playlist;
    while (temp_playlist != NULL) {
        printf("%s: ", temp_playlist->name);
        struct Song *temp_song = temp_playlist->head_song;
        while (temp_song != NULL) {
            printf("%s - %s, ", temp_song->name, temp_song->artist);
            temp_song = temp_song->next;
        }
        printf("\n");
        temp_playlist = temp_playlist->next;
    }
}

void display_artists() {
    struct Artist *temp_artist = all_data.head_artist;
    while (temp_artist != NULL) {
        printf("%s: ", temp_artist->name);
        struct Song *temp_song = temp_artist->head_song;
        while (temp_song != NULL) {
            printf("%s, ", temp_song->name);
            temp_song = temp_song->next;
        }
        printf("\n");
        temp_artist = temp_artist->next;
    }
}

int main() {
    printf("Welcome to the Music Library Management System!\n");
    printf("What would you like to do? (Enter the number of the option)\n");
    printf("1. Add a song\n");
    printf("2. Add a playlist\n");
    printf("3. Add a song to a playlist\n");
    printf("4. Display all songs\n");
    printf("5. Display all playlists\n");
    printf("6. Display all artists\n");
    printf("7. Exit\n");
    
    int choice = 0;
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            printf("\nEnter the name of the song: ");
            char name[50];
            scanf("%s", name);
            
            printf("\nEnter the name of the artist: ");
            char artist[50];
            scanf("%s", artist);
            
            printf("\nEnter the duration of the song (in seconds): ");
            int duration = 0;
            scanf("%d", &duration);
            
            add_song(name, artist, duration);
            printf("\n%s by %s with a duration of %d seconds has been added to the library.", name, artist, duration);
        }
        else if (choice == 2) {
            printf("\nEnter the name of the playlist: ");
            char name[50];
            scanf("%s", name);
            
            add_playlist(name);
            printf("\n%s playlist has been added to the library.", name);
        }
        else if (choice == 3) {
            printf("\nEnter the name of the song: ");
            char name[50];
            scanf("%s", name);
            
            printf("\nEnter the name of the playlist: ");
            char playlist_name[50];
            scanf("%s", playlist_name);
            
            add_song_to_playlist(name, playlist_name);
            printf("\n%s has been added to the %s playlist.", name, playlist_name);
        }
        else if (choice == 4) {
            printf("\nAll songs in the library:\n");
            display_songs();
        }
        else if (choice == 5) {
            printf("\nAll playlists in the library:\n");
            display_playlists();
        }
        else if (choice == 6) {
            printf("\nAll artists in the library:\n");
            display_artists();
        }
        else if (choice == 7) {
            printf("\nThank you for using the Music Library Management System!\n");
            return 0;
        }
        else {
            printf("\nInvalid choice. Please enter a number between 1 and 7.");
        }
    }
    
    return 0;
}