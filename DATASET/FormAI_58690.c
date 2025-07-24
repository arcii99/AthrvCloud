//FormAI DATASET v1.0 Category: Music Library Management System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONGS 1000

struct song{
    char title[100];
    char artist[100];
    char album[100];
    int year;
};

struct song_list{
    struct song songs[MAX_SONGS];
    int count;
};

void display_menu(){
    printf("\n");
    printf("Music Library Management System\n");
    printf("1. Add song\n");
    printf("2. Remove song\n");
    printf("3. Display all songs\n");
    printf("4. Search by title\n");
    printf("5. Search by artist\n");
    printf("6. Search by album\n");
    printf("7. Search by year\n");
    printf("8. Quit\n");
    printf("\n");
}

void add_song(struct song_list *list){
    struct song input;
    printf("Enter song title: ");
    fgets(input.title, sizeof(input.title), stdin);
    strtok(input.title, "\n");
    printf("Enter artist name: ");
    fgets(input.artist, sizeof(input.artist), stdin);
    strtok(input.artist, "\n");
    printf("Enter album name: ");
    fgets(input.album, sizeof(input.album), stdin);
    strtok(input.album, "\n");
    printf("Enter the year of release: ");
    scanf("%d", &input.year);
    getchar();

    if(list->count < MAX_SONGS){
        list->songs[list->count] = input;
        list->count++;
        printf("Song added successfully.\n");
    }
    else{
        printf("Maximum song limit reached.\n");
    }
}

void remove_song(struct song_list *list){
    char title[100];
    int i, j;

    printf("Enter the title of the song to remove: ");
    fgets(title, sizeof(title), stdin);
    strtok(title, "\n");

    for(i=0; i<list->count; i++){
        if(strcmp(list->songs[i].title, title) == 0){
            for(j=i; j<list->count-1; j++){
                list->songs[j] = list->songs[j+1];
            }
            list->count--;
            printf("Song removed successfully.\n");
            return;
        }
    }

    printf("Song not found.\n");
}

void display_all_songs(struct song_list *list){
    int i;
    printf("\n%3s | %-40s | %-25s | %-20s | %s\n", "ID", "Title", "Artist", "Album", "Year");
    printf("----|-----------------------------------------|-------------------------|----------------------|------\n");
    for(i=0; i<list->count; i++){
        printf("%3d | %-40s | %-25s | %-20s | %d\n", i+1, list->songs[i].title, list->songs[i].artist, list->songs[i].album, list->songs[i].year);
    }
    printf("\n");
}

void search_by_title(struct song_list *list){
    char title[100];
    int i, found = 0;

    printf("Enter the title to search: ");
    fgets(title, sizeof(title), stdin);
    strtok(title, "\n");

    printf("\n%3s | %-40s | %-25s | %-20s | %s\n", "ID", "Title", "Artist", "Album", "Year");
    printf("----|-----------------------------------------|-------------------------|----------------------|------\n");

    for(i=0; i<list->count; i++){
        if(strstr(list->songs[i].title, title) != NULL){
            printf("%3d | %-40s | %-25s | %-20s | %d\n", i+1, list->songs[i].title, list->songs[i].artist, list->songs[i].album, list->songs[i].year);
            found = 1;
        }
    }

    if(!found){
        printf("No results found.\n");
    }

    printf("\n");
}

void search_by_artist(struct song_list *list){
    char artist[100];
    int i, found = 0;

    printf("Enter the artist to search: ");
    fgets(artist, sizeof(artist), stdin);
    strtok(artist, "\n");

    printf("\n%3s | %-40s | %-25s | %-20s | %s\n", "ID", "Title", "Artist", "Album", "Year");
    printf("----|-----------------------------------------|-------------------------|----------------------|------\n");

    for(i=0; i<list->count; i++){
        if(strstr(list->songs[i].artist, artist) != NULL){
            printf("%3d | %-40s | %-25s | %-20s | %d\n", i+1, list->songs[i].title, list->songs[i].artist, list->songs[i].album, list->songs[i].year);
            found = 1;
        }
    }

    if(!found){
        printf("No results found.\n");
    }

    printf("\n");
}

void search_by_album(struct song_list *list){
    char album[100];
    int i, found = 0;

    printf("Enter the album to search: ");
    fgets(album, sizeof(album), stdin);
    strtok(album, "\n");

    printf("\n%3s | %-40s | %-25s | %-20s | %s\n", "ID", "Title", "Artist", "Album", "Year");
    printf("----|-----------------------------------------|-------------------------|----------------------|------\n");

    for(i=0; i<list->count; i++){
        if(strstr(list->songs[i].album, album) != NULL){
            printf("%3d | %-40s | %-25s | %-20s | %d\n", i+1, list->songs[i].title, list->songs[i].artist, list->songs[i].album, list->songs[i].year);
            found = 1;
        }
    }

    if(!found){
        printf("No results found.\n");
    }

    printf("\n");
}

void search_by_year(struct song_list *list){
    int year, i, found = 0;

    printf("Enter the year to search: ");
    scanf("%d", &year);
    getchar();

    printf("\n%3s | %-40s | %-25s | %-20s | %s\n", "ID", "Title", "Artist", "Album", "Year");
    printf("----|-----------------------------------------|-------------------------|----------------------|------\n");

    for(i=0; i<list->count; i++){
        if(list->songs[i].year == year){
            printf("%3d | %-40s | %-25s | %-20s | %d\n", i+1, list->songs[i].title, list->songs[i].artist, list->songs[i].album, list->songs[i].year);
            found = 1;
        }
    }

    if(!found){
        printf("No results found.\n");
    }

    printf("\n");
}

void clear_input(){
    char c;
    while((c = getchar()) != EOF && c != '\n');
}

int main(){
    struct song_list list;
    int choice;

    list.count = 0;

    printf("Welcome to the Music Library Management System.\n\n");

    do{
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice){
            case 1:
                add_song(&list);
                break;
            case 2:
                remove_song(&list);
                break;
            case 3:
                display_all_songs(&list);
                break;
            case 4:
                search_by_title(&list);
                break;
            case 5:
                search_by_artist(&list);
                break;
            case 6:
                search_by_album(&list);
                break;
            case 7:
                search_by_year(&list);
                break;
            case 8:
                printf("Quitting...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
        clear_input();
    } while(choice != 8);

    return 0;
}