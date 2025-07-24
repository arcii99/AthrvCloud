//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define ROOMS 10    // Number of rooms in the house

// Function prototypes
bool isEmpty(int []);
int Random(int, int);
void DisplayWelcomeMessage();
void DisplayExitMessage();
void GenerateRooms(int []);
void SearchRoom(int []);

// Main Function
int main()
{
    int rooms[ROOMS];   // Array to hold the status of rooms in the house (1 for occupied, 0 for unoccupied)
    int playerChoice;   // Variable to hold option chosen by player
    bool gameOver = false;  // Flag to signal end of game

    srand(time(NULL));  // Initialize random number generator

    GenerateRooms(rooms);   // Set initial status of rooms in the house

    DisplayWelcomeMessage();    // Display welcome message

    while (!gameOver)
    {
        // Ask player for their choice
        printf("\nEnter your choice:\n");
        printf("1. Search a room\n");
        printf("2. Quit game\n");
        scanf("%d", &playerChoice);

        switch (playerChoice)
        {
            case 1:
                SearchRoom(rooms);  // Search a room
                break;

            case 2:
                gameOver = true;    // End the game
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }

        if (isEmpty(rooms)) // If all rooms are empty game over
        {
            DisplayExitMessage();
            gameOver = true;
        }
    }

    return 0;
}

// Function to check if all rooms are empty
bool isEmpty(int rooms[])
{
    for (int i = 0; i < ROOMS; i++)
    {
        if (rooms[i])
            return false;
    }

    return true;
}

// Function to generate a random number within a range
int Random(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

// Function to display welcome message to player
void DisplayWelcomeMessage()
{
    printf("Welcome to the Haunted House simulator!\n");
    printf("You have entered a house with %d rooms. Some rooms are haunted and some are not.\n", ROOMS);
    printf("Your goal is to search all the unoccupied rooms in the house and find all the haunted rooms.\n");
    printf("Be careful not to enter any haunted rooms or you will be trapped forever!\n");
}

// Function to display exit message to player
void DisplayExitMessage()
{
    printf("\nCongratulations! You have found all the unoccupied rooms and have avoided all the haunted rooms.\n");
    printf("You have successfully escaped from the haunted house. Thank you for playing!\n");
}

// Function to randomly occupy some of the rooms in the house
void GenerateRooms(int rooms[])
{
    int occupiedRooms = ROOMS / 2;  // Make half of the rooms occupied

    for (int i = 0; i < ROOMS; i++)
        rooms[i] = 0;   // Set all rooms as unoccupied initially

    for (int i = 0; i < occupiedRooms; i++)
    {
        int roomNumber;

        do
        {
            roomNumber = Random(1, ROOMS);  // Generate a random room number
        }
        while (rooms[roomNumber]);  // Continue until an unoccupied room is found

        rooms[roomNumber] = 1;  // Occupy the room
    }
}

// Function to search a room and check if it is haunted or not
void SearchRoom(int rooms[])
{
    int roomNumber;

    do
    {
        printf("\nEnter the room number you wish to search: ");
        scanf("%d", &roomNumber);

        if (roomNumber < 1 || roomNumber > ROOMS)
            printf("Invalid room number. Please enter a room number between 1 and %d.\n", ROOMS);
        else if (!rooms[roomNumber])
            printf("Room %d is unoccupied. Please enter a room number that is occupied.\n", roomNumber);
    }
    while (roomNumber < 1 || roomNumber > ROOMS || !rooms[roomNumber]);

    if (Random(0, 1))   // 50% chance of the room being haunted
    {
        printf("Room %d is haunted! You are trapped forever!\n", roomNumber);
        rooms[roomNumber] = 0;
    }
    else
    {
        printf("Room %d is safe.\n", roomNumber);
        rooms[roomNumber] = 0;  // Mark the room as searched
    }
}