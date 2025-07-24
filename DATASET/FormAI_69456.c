//FormAI DATASET v1.0 Category: Music Library Management System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song {
    char title[100];
    char artist[100];
    int duration;
    int rating;
};

struct node {
    struct song *data;
    struct node *next;
};

struct playlist {
    char name[100];
    struct node *head;
    int length;
};

struct library {
    struct playlist *playlists;
    int num_playlists;
};

void add_song(struct library *lib);
struct song *create_song(char title[100], char artist[100], int duration, int rating);
void print_playlists(struct library *lib);
void print_songs(struct playlist *playlist);
void add_playlist(struct library *lib);
void remove_song(struct library *lib);
void remove_playlist(struct library *lib);
void show_menu();

int main() {
    struct library my_library;
    my_library.playlists = NULL;
    my_library.num_playlists = 0;

    int choice;
    int i;
    int playlist_index;
    struct playlist *selected_playlist;
    char title[100];
    char artist[100];
    int duration;
    int rating;
    char playlist_name[100];

    printf("*** C Music Library Management System ***\n");

    while (1) {
        show_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_song(&my_library);
                break;
            case 2:
                print_playlists(&my_library);
                printf("Enter the index of the playlist to add the song to: ");
                scanf("%d", &playlist_index);
                if (playlist_index < 0 || playlist_index >= my_library.num_playlists) {
                    printf("Invalid playlist index.\n");
                } else {
                    selected_playlist = &(my_library.playlists[playlist_index]);
                    print_songs(selected_playlist);
                    printf("Enter the title of the song to add: ");
                    scanf("%s", title);
                    printf("Enter the artist of the song to add: ");
                    scanf("%s", artist);
                    printf("Enter the duration of the song to add: ");
                    scanf("%d", &duration);
                    printf("Enter the rating of the song to add: ");
                    scanf("%d", &rating);
                    struct song *new_song = create_song(title, artist, duration, rating);
                    struct node *new_node = malloc(sizeof(struct node));
                    new_node->data = new_song;
                    new_node->next = NULL;
                    if (selected_playlist->head == NULL) {
                        selected_playlist->head = new_node;
                    } else {
                        struct node *current = selected_playlist->head;
                        while (current->next != NULL) {
                            current = current->next;
                        }
                        current->next = new_node;
                    }
                    selected_playlist->length++;
                    printf("Song added successfully.\n");
                }
                break;
            case 3:
                print_playlists(&my_library);
                break;
            case 4:
                add_playlist(&my_library);
                break;
            case 5:
                remove_song(&my_library);
                break;
            case 6:
                remove_playlist(&my_library);
                break;
            case 7:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

void add_song(struct library *lib) {
    char title[100];
    char artist[100];
    int duration;
    int rating;

    printf("Enter the title of the song to add: ");
    scanf("%s", title);
    printf("Enter the artist of the song to add: ");
    scanf("%s", artist);
    printf("Enter the duration of the song to add: ");
    scanf("%d", &duration);
    printf("Enter the rating of the song to add: ");
    scanf("%d", &rating);

    struct song *new_song = create_song(title, artist, duration, rating);

    struct playlist new_playlist;
    strcpy(new_playlist.name, "Untitled");
    new_playlist.head = malloc(sizeof(struct node));
    new_playlist.head->data = new_song;
    new_playlist.head->next = NULL;
    new_playlist.length = 1;

    if (lib->playlists == NULL) {
        lib->playlists = malloc(sizeof(struct playlist));
        lib->num_playlists = 1;
    } else {
        lib->num_playlists++;
        lib->playlists = realloc(lib->playlists, sizeof(struct playlist) * lib->num_playlists);
    }

    lib->playlists[lib->num_playlists - 1] = new_playlist;

    printf("Song added successfully.\n");
}

struct song *create_song(char title[100], char artist[100], int duration, int rating) {
    struct song *new_song = malloc(sizeof(struct song));
    strcpy(new_song->title, title);
    strcpy(new_song->artist, artist);
    new_song->duration = duration;
    new_song->rating = rating;
    return new_song;
}

void print_playlists(struct library *lib) {
    printf("Playlists:\n");
    int i;
    for (i = 0; i < lib->num_playlists; i++) {
        printf("%d. %s (%d songs)\n", i, lib->playlists[i].name, lib->playlists[i].length);
    }
}

void print_songs(struct playlist *playlist) {
    printf("Songs in playlist \"%s\":\n", playlist->name);
    struct node *current = playlist->head;
    int count = 1;
    while (current != NULL) {
        printf("%d. %s - %s (%d:%d)\n", count, current->data->title, current->data->artist, current->data->duration/60, current->data->duration%60);
        current = current->next;
        count++;
    }
}

void add_playlist(struct library *lib) {
    char playlist_name[100];
    printf("Enter the name of the new playlist: ");
    scanf("%s", playlist_name);

    struct playlist new_playlist;
    strcpy(new_playlist.name, playlist_name);
    new_playlist.head = NULL;
    new_playlist.length = 0;

    if (lib->playlists == NULL) {
        lib->playlists = malloc(sizeof(struct playlist));
        lib->num_playlists = 1;
    } else {
        lib->num_playlists++;
        lib->playlists = realloc(lib->playlists, sizeof(struct playlist) * lib->num_playlists);
    }

    lib->playlists[lib->num_playlists - 1] = new_playlist;

    printf("Playlist added successfully.\n");
}

void remove_song(struct library *lib) {
    print_playlists(lib);
    int playlist_index;
    printf("Enter the index of the playlist to remove the song from: ");
    scanf("%d", &playlist_index);

    if (playlist_index < 0 || playlist_index >= lib->num_playlists) {
        printf("Invalid playlist index.\n");
        return;
    }

    struct playlist *selected_playlist = &(lib->playlists[playlist_index]);
    if (selected_playlist->length == 0) {
        printf("There are no songs in this playlist.\n");
        return;
    }

    print_songs(selected_playlist);
    int song_index;
    printf("Enter the index of the song to remove: ");
    scanf("%d", &song_index);

    if (song_index < 1 || song_index > selected_playlist->length) {
        printf("Invalid song index.\n");
        return;
    }

    struct node *prev = NULL;
    struct node *current = selected_playlist->head;
    int count = 1;
    while (count < song_index) {
        prev = current;
        current = current->next;
        count++;
    }

    if (prev == NULL) {
        selected_playlist->head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current->data);
    free(current);

    selected_playlist->length--;
    printf("Song removed successfully.\n");
}

void remove_playlist(struct library *lib) {
    print_playlists(lib);
    int playlist_index;
    printf("Enter the index of the playlist to remove: ");
    scanf("%d", &playlist_index);

    if (playlist_index < 0 || playlist_index >= lib->num_playlists) {
        printf("Invalid playlist index.\n");
        return;
    }

    struct playlist *selected_playlist = &(lib->playlists[playlist_index]);
    struct node *current = selected_playlist->head;
    while (current != NULL) {
        struct node *next = current->next;
        free(current->data);
        free(current);
        current = next;
    }

    int i;
    for (i = playlist_index; i < lib->num_playlists - 1; i++) {
        lib->playlists[i] = lib->playlists[i + 1];
    }

    lib->num_playlists--;
    lib->playlists = realloc(lib->playlists, sizeof(struct playlist) * lib->num_playlists);

    printf("Playlist removed successfully.\n");
}

void show_menu() {
    printf("Menu:\n");
    printf("1. Add song\n");
    printf("2. Add song to playlist\n");
    printf("3. View playlists\n");
    printf("4. Add playlist\n");
    printf("5. Remove song from playlist\n");
    printf("6. Remove playlist\n");
    printf("7. Exit\n");
}