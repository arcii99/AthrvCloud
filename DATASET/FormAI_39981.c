//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Linus Torvalds
/*
    Author: Linus Torvalds (inspired by Avidemux)
    Program: C Music Library Management System

    Description:
    This program is designed to manage large music libraries by allowing users to easily add, delete,
    and search for music files from their collection. The program initializes by reading a pre-existing
    music library file and populating a hash table with the data. Users can then perform various operations
    on the library, such as adding new files, deleting existing files, searching for files by title or artist,
    and writing the modified library back to a file. The program also includes basic error checking and
    validation to ensure the user inputs correct data.

    Disclaimer: This code is for educational purposes only. Use at your own risk.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_TABLE_SIZE 100 // adjust this value as needed

typedef struct
{
    char title[100];
    char artist[100];
    char album[100];
    int year;
} MusicFile;

typedef struct Node
{
    MusicFile musicFile;
    struct Node* next;
} Node;

Node* hashTable[HASH_TABLE_SIZE];

// Helper function to calculate hash value
int hash(char* key)
{
    int hashValue = 0;
    for(int i = 0; i < strlen(key); i++)
    {
        hashValue += key[i];
    }

    return hashValue % HASH_TABLE_SIZE;
}

// Helper function to print all music files in a linked list
void printList(Node* head)
{
    printf("\nTitle                Artist             Album                Year\n");
    while(head != NULL)
    {
        printf("%-20s %-20s %-20s %-4d\n", head->musicFile.title, 
                                            head->musicFile.artist, 
                                            head->musicFile.album, 
                                            head->musicFile.year);
        head = head->next;
    }
}

// Helper function to search for a particular music file in a linked list
Node* searchList(Node* head, char* title)
{
    while(head != NULL)
    {
        if(strcmp(head->musicFile.title, title) == 0)
        {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

// Helper function to add a node to the beginning of a linked list
Node* push(Node* head, MusicFile musicFile)
{
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->musicFile = musicFile;
    newNode->next = head;
    return newNode;
}

// Helper function to delete a node from a linked list
Node* deleteNode(Node* head, char* title)
{
    if(head == NULL)
    {
        return NULL;
    }
    else if(strcmp(head->musicFile.title, title) == 0)
    {
        Node* temp = head->next;
        free(head);
        return temp;
    }
    else
    {
        Node* temp = head;
        while(temp->next != NULL && strcmp(temp->next->musicFile.title, title) != 0)
        {
            temp = temp->next;
        }

        if(temp->next != NULL)
        {
            Node* target = temp->next;
            temp->next = target->next;
            free(target);
        }

        return head;
    }
}

// Helper function to free all the memory allocated to linked list nodes
void clearList(Node* head)
{
    Node* temp;
    while(head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Helper function to read a music library file and store it in the hash table
void readLibrary(char* fileName)
{
    FILE* fp = fopen(fileName, "r");
    if(fp == NULL)
    {
        printf("Could not open file %s\n", fileName);
        exit(1);
    }

    char buffer[500];
    while(fgets(buffer, 500, fp) != NULL)
    {
        MusicFile musicFile;
        sscanf(buffer, "%[^,],%[^,],%[^,],%d\n", musicFile.title, musicFile.artist, musicFile.album, &musicFile.year);
        int hashValue = hash(musicFile.title);
        hashTable[hashValue] = push(hashTable[hashValue], musicFile);
    }

    fclose(fp);
}

// Helper function to write the modified hash table back to the music library file
void writeLibrary(char* fileName)
{
    FILE* fp = fopen(fileName, "w");
    if(fp == NULL)
    {
        printf("Could not open file %s\n", fileName);
        exit(1);
    }

    for(int i = 0; i < HASH_TABLE_SIZE; i++)
    {
        Node* temp = hashTable[i];
        while(temp != NULL)
        {
            fprintf(fp, "%s,%s,%s,%d\n", temp->musicFile.title, temp->musicFile.artist, temp->musicFile.album, temp->musicFile.year);
            temp = temp->next;
        }
    }

    fclose(fp);
}

int main()
{
    // Initialize hash table to NULL
    for(int i = 0; i < HASH_TABLE_SIZE; i++)
    {
        hashTable[i] = NULL;
    }

    // Read pre-existing library file
    readLibrary("music_library.csv");

    // User menu
    int choice = 0;
    do
    {
        printf("\n==========================================\n");
        printf("       C Music Library Management         \n");
        printf("==========================================\n");
        printf("1. Add music file\n");
        printf("2. Delete music file\n");
        printf("3. Search by title\n");
        printf("4. Search by artist\n");
        printf("5. Print all music files\n");
        printf("6. Save and exit\n");
        printf("==========================================\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                MusicFile musicFile;
                printf("\nTitle: ");
                scanf("%s", musicFile.title);
                printf("Artist: ");
                scanf("%s", musicFile.artist);
                printf("Album: ");
                scanf("%s", musicFile.album);
                printf("Year: ");
                scanf("%d", &musicFile.year);

                int hashValue = hash(musicFile.title);
                hashTable[hashValue] = push(hashTable[hashValue], musicFile);

                printf("\nMusic file added successfully.\n");
                break;
            }

            case 2:
            {
                char title[100];
                printf("\nTitle to delete: ");
                scanf("%s", title);

                int hashValue = hash(title);
                hashTable[hashValue] = deleteNode(hashTable[hashValue], title);

                printf("\nMusic file deleted successfully.\n");
                break;
            }

            case 3:
            {
                char title[100];
                printf("\nTitle to search: ");
                scanf("%s", title);

                int hashValue = hash(title);
                Node* result = searchList(hashTable[hashValue], title);
                if(result != NULL)
                {
                    printf("\nTitle                Artist             Album                Year\n");
                    printf("%-20s %-20s %-20s %-4d\n", result->musicFile.title, 
                                                        result->musicFile.artist, 
                                                        result->musicFile.album, 
                                                        result->musicFile.year);
                }
                else
                {
                    printf("\nNo matching music file found.\n");
                }
                break;
            }

            case 4:
            {
                char artist[100];
                printf("\nArtist to search: ");
                scanf("%s", artist);

                printf("\nTitle                Artist             Album                Year\n");
                for(int i = 0; i < HASH_TABLE_SIZE; i++)
                {
                    Node* temp = hashTable[i];
                    while(temp != NULL)
                    {
                        if(strcmp(temp->musicFile.artist, artist) == 0)
                        {
                            printf("%-20s %-20s %-20s %-4d\n", temp->musicFile.title, 
                                                                temp->musicFile.artist, 
                                                                temp->musicFile.album, 
                                                                temp->musicFile.year);
                        }
                        temp = temp->next;
                    }
                }
                break;
            }

            case 5:
            {
                for(int i = 0; i < HASH_TABLE_SIZE; i++)
                {
                    printList(hashTable[i]);
                }
                break;
            }

            case 6:
            {
                printf("\nSaving changes to music_library.csv...\n");
                writeLibrary("music_library.csv");
                clearList(hashTable[HASH_TABLE_SIZE]);
                printf("\nGoodbye!\n");
                break;
            }

            default:
            {
                printf("\nInvalid choice. Please try again.\n");
                break;
            }
        }
    }
    while(choice != 6);

    return 0;
}