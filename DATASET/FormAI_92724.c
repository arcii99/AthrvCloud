//FormAI DATASET v1.0 Category: Music Library Management System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct song{
    char songTitle[100];
    char artist[100];
    int year;
    int duration;
    char genre[100];
}Song;

typedef struct node{
    Song *data;
    struct node *next;
}Node;

typedef struct library{
    int numOfSongs;
    Node *head;
}Library;

Library *libraryInit(){
    Library *newLibrary = (Library*)malloc(sizeof(Library));
    newLibrary->numOfSongs = 0;
    newLibrary->head = NULL;
    return newLibrary;
}

Song *songInit(char *title, char *artist, int year, int duration, char *genre){
    Song *newSong = (Song*)malloc(sizeof(Song));
    strcpy(newSong->songTitle, title);
    strcpy(newSong->artist, artist);
    newSong->year = year;
    newSong->duration = duration;
    strcpy(newSong->genre, genre);
    return newSong;
}

void addSong(Library *library, Song *newSong){
    Node *newNode;
    newNode = (Node*)malloc(sizeof(Node));
    newNode->data = newSong;
    newNode->next = NULL;
    if(library->head == NULL){
        library->head = newNode;
    }else{
        Node *temp = library->head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    library->numOfSongs++;
}

void searchByTitle(Library *library, char *title){
    Node *temp = library->head;
    int found = 0;
    while(temp != NULL){
        if(strcmp(temp->data->songTitle, title) == 0){
            printf("Title: %s\nArtist: %s\nYear: %d\nDuration: %d\nGenre: %s\n", temp->data->songTitle, temp->data->artist, temp->data->year, temp->data->duration, temp->data->genre);
            found = 1;
            break;
        }
        temp = temp->next;
    }
    if(found == 0){
        printf("Song not found.\n");
    }
}

void deleteSong(Library *library, char *title){
    Node *temp = library->head;
    Node *prev;
    int found = 0;
    while(temp != NULL){
        if(strcmp(temp->data->songTitle, title) == 0){
            if(temp == library->head){
                library->head = library->head->next;
                free(temp);
            }else{
                prev->next = temp->next;
                free(temp);
            }
            found = 1;
            library->numOfSongs--;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    if(found == 0){
        printf("Song not found.\n");
    }else{
        printf("Song deleted.\n");
    }
}

void displayAll(Library *library){
    Node *temp = library->head;
    if(temp == NULL){
        printf("Library is empty.\n");
    }else{
        while(temp != NULL){
            printf("Title: %s\nArtist: %s\nYear: %d\nDuration: %d\nGenre: %s\n", temp->data->songTitle, temp->data->artist, temp->data->year, temp->data->duration, temp->data->genre);
            temp = temp->next;
        }
    }
}

int main(){
    Library *myLibrary = libraryInit();
    Song *song1 = songInit("Blank Space", "Taylor Swift", 2014, 231, "Pop");
    Song *song2 = songInit("Despacito", "Luis Fonsi", 2017, 228, "Reggaeton");
    Song *song3 = songInit("Stressed Out", "Twenty One Pilots", 2015, 202, "Alternative");
    Song *song4 = songInit("Baby Shark", "Pinkfong", 2015, 136, "Children's Music");
    addSong(myLibrary, song1);
    addSong(myLibrary, song2);
    addSong(myLibrary, song3);
    addSong(myLibrary, song4);
    printf("Welcome to the C Music Library Management System!\n");
    int option;
    char title[100], artist[100], genre[100];
    int year, duration;
    while(1){
        printf("\n1. Add a song\n2. Search for a song\n3. Delete a song\n4. Display all songs\n5. Exit\n");
        scanf("%d", &option);
        getchar();
        switch(option){
            case 1:
                printf("Enter the details of the song:\n");
                printf("Title: ");
                fgets(title, 100, stdin);
                title[strlen(title)-1] = '\0';
                printf("Artist: ");
                fgets(artist, 100, stdin);
                artist[strlen(artist)-1] = '\0';
                printf("Year: ");
                scanf("%d", &year);
                getchar();
                printf("Duration(in seconds): ");
                scanf("%d", &duration);
                getchar();
                printf("Genre: ");
                fgets(genre, 100, stdin);
                genre[strlen(genre)-1] = '\0';
                Song *newSong = songInit(title, artist, year, duration, genre);
                addSong(myLibrary, newSong);
                printf("Song added successfully.\n");
                break;
            case 2:
                printf("Enter the title of the song to be searched: ");
                fgets(title, 100, stdin);
                title[strlen(title)-1] = '\0';
                searchByTitle(myLibrary, title);
                break;
            case 3:
                printf("Enter the title of the song to be deleted: ");
                fgets(title, 100, stdin);
                title[strlen(title)-1] = '\0';
                deleteSong(myLibrary, title);
                break;
            case 4:
                displayAll(myLibrary);
                break;
            case 5:
                printf("Thank you for using the C Music Library Management System.\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}