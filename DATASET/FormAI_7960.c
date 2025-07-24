//FormAI DATASET v1.0 Category: Music Library Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SONG_LENGTH 20
#define MAX_ARTIST_LENGTH 30
#define MAX_ALBUM_LENGTH 30
#define MAX_LENGTH_ERROR 100

typedef struct Song{
    int id;
    char songName[MAX_SONG_LENGTH];
    char artistName[MAX_ARTIST_LENGTH];
    char albumName[MAX_ALBUM_LENGTH];
    int year;
} Song;

typedef struct Node{
    Song song;
    struct Node* next;
} Node;

typedef struct LinkedList{
    Node* head;
    int size;
} LinkedList;

// Function declarations
Song createSong(int id, char* songName, char* artistName, char* albumName, int year);
LinkedList createLinkedList();
void addSongToEnd(LinkedList* linkedList, Song song);
void addSongToBeginning(LinkedList* linkedList, Song song);
void printLinkedList(LinkedList linkedList);
void deleteSongById(LinkedList* linkedList, int idToDelete);
Node* findSongById(LinkedList linkedList, int idToFind);
void deleteAllSongs(LinkedList* linkedList);

int main(){

    LinkedList myLibrary = createLinkedList(); // Creating an empty library

    // Adding some songs to the library
    Song song1 = createSong(1, "Song1", "Artist1", "Album1", 1990);
    Song song2 = createSong(2, "Song2", "Artist2", "Album2", 1995);
    Song song3 = createSong(3, "Song3", "Artist1", "Album3", 2000);

    addSongToEnd(&myLibrary, song1);
    addSongToBeginning(&myLibrary, song2);
    addSongToEnd(&myLibrary, song3);

    // Printing the library
    printf("My Library:\n");
    printLinkedList(myLibrary);

    // Deleting a song by ID and printing the updated library
    printf("\nDeleting song with ID 2...\n");
    deleteSongById(&myLibrary, 2);

    printf("Updated Library:\n");
    printLinkedList(myLibrary);

    // Finding a song by ID and printing its details
    printf("\nFinding song with ID 1...\n");
    Node* foundNode = findSongById(myLibrary, 1);
    if(foundNode != NULL){
        printf("Song found:\n");
        printf("ID: %d\n", foundNode -> song.id);
        printf("Song Name: %s\n", foundNode -> song.songName);
        printf("Artist Name: %s\n", foundNode -> song.artistName);
        printf("Album Name: %s\n", foundNode -> song.albumName);
        printf("Year: %d\n", foundNode -> song.year);
    }else{
        printf("Song not found.\n");
    }

    // Deleting all songs and printing the updated library
    printf("\nDeleting all songs...\n");
    deleteAllSongs(&myLibrary);

    printf("Updated Library:\n");
    printLinkedList(myLibrary);

    return 0;
}

// Function definitions

// Creates a new song
Song createSong(int id, char* songName, char* artistName, char* albumName, int year){
    Song song;
    song.id = id;
    strncpy(song.songName, songName, MAX_SONG_LENGTH);
    strncpy(song.artistName, artistName, MAX_ARTIST_LENGTH);
    strncpy(song.albumName, albumName, MAX_ALBUM_LENGTH);
    song.year = year;
    return song;
}

// Creates an empty linked list
LinkedList createLinkedList(){
    LinkedList linkedList;
    linkedList.head = NULL;
    linkedList.size = 0;
    return linkedList;
}

// Adds a song to the end of the linked list
void addSongToEnd(LinkedList* linkedList, Song song){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode -> song = song;
    newNode -> next = NULL;

    if(linkedList -> head == NULL){
        linkedList -> head = newNode;
    }else{
        Node* currentNode = linkedList -> head;
        while(currentNode -> next != NULL){
            currentNode = currentNode -> next;
        }
        currentNode -> next = newNode;
    }

    linkedList -> size++;
}

// Adds a song to the beginning of the linked list
void addSongToBeginning(LinkedList* linkedList, Song song){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode -> song = song;
    newNode -> next = linkedList -> head;
    linkedList -> head = newNode;
    linkedList -> size++;
}

// Prints the linked list
void printLinkedList(LinkedList linkedList){
    Node* currentNode = linkedList.head;
    while(currentNode != NULL){
        printf("ID: %d, Song: %s, Artist: %s, Album: %s, Year: %d\n", currentNode -> song.id, currentNode -> song.songName,
                currentNode -> song.artistName, currentNode -> song.albumName, currentNode -> song.year);
        currentNode = currentNode -> next;
    }
    printf("Total Songs: %d\n", linkedList.size);
}

// Deletes a song from the linked list by ID
void deleteSongById(LinkedList* linkedList, int idToDelete){
    Node* currentNode = linkedList -> head;
    Node* previousNode = NULL;

    while(currentNode != NULL){
        if(currentNode -> song.id == idToDelete){
            if(previousNode == NULL){
                linkedList -> head = currentNode -> next;
            }else{
                previousNode -> next = currentNode -> next;
            }
            free(currentNode);
            linkedList -> size--;
            return;
        }
        previousNode = currentNode;
        currentNode = currentNode -> next;
    }

    char lengthError[MAX_LENGTH_ERROR];
    sprintf(lengthError, "Song with ID %d not found.", idToDelete);
    perror(lengthError);
}

// Finds a node in the linked list by ID and returns it
Node* findSongById(LinkedList linkedList, int idToFind){
    Node* currentNode = linkedList.head;
    while(currentNode != NULL){
        if(currentNode -> song.id == idToFind){
            return currentNode;
        }
        currentNode = currentNode -> next;
    }
    return NULL;
}

// Deletes all songs from the linked list
void deleteAllSongs(LinkedList* linkedList){
    Node* currentNode = linkedList -> head;
    while(currentNode != NULL){
        Node* temp = currentNode;
        currentNode = currentNode -> next;
        free(temp);
    }
    linkedList -> head = NULL;
    linkedList -> size = 0;
}