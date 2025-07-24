//FormAI DATASET v1.0 Category: Table Game ; Style: Sherlock Holmes
/*
A Sherlock Holmes themed C Table Game
The objective of the game is to solve a murder mystery by finding the suspect, weapon and location of the crime
Players roll a dice and move through rooms, where they can gather clues and suspects.

Each room has a chance to either give a clue, or a suspect, or nothing at all.

The first player to gather all three pieces of information and make a correct accusation wins.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//Function prototypes
void printBoard(char board[][3], int row, int col);
int rollDice();
void movePlayer(char board[][3], int *rowPos, int *colPos, int roll, int *suspectFound, int *weaponFound, int *locationFound, char *suspect, char *weapon, char *location);
int searchRoom(char room[]);
void printClue(char room[]);
int accuse(char suspect[], char weapon[], char location[], char *guiltySuspect, char *guiltyWeapon, char *guiltyLocation);

int main()
{
    //Initialize board
    char board[3][3] = {{'H', 'G', 'F'},
                        {'E', 'D', 'C'},
                        {'B', 'A', ' '}};
    int rowPos = 2, colPos = 2;
    int suspectFound = 0, weaponFound = 0, locationFound = 0;
    char suspect[20], weapon[20], location[20];
    char guiltySuspect[] = "Colonel Moran";
    char guiltyWeapon[] = "Revolver";
    char guiltyLocation[] = "Baker Street";

    //Welcome message
    printf("Welcome to Sherlock Holmes Murder Mystery Game!\n");
    printf("The game begins with a murder mystery. Your task is to solve the case by finding the suspect, weapon and location of the murder.\n");
    printf("You are going to roll a dice and move through rooms to gather clues and find suspects.\n");
    printf("Be careful, there are some traps on the board, if you land on them you will miss your turn.\n");
    printf("The first player who finds all three pieces of the puzzle and makes a correct accusation wins the game. Let's start!\n");

    //Game loop
    int currentPlayer = 1;
    while (1)
    {
        //Roll the dice and move player
        printf("\n\nPlayer %d's turn.\n", currentPlayer);
        int roll = rollDice();
        printf("You rolled a %d.\n", roll);
        movePlayer(board, &rowPos, &colPos, roll, &suspectFound, &weaponFound, &locationFound, suspect, weapon, location);

        //Check if player found all clues
        if (suspectFound && weaponFound && locationFound)
        {
            //Accusation phase
            printf("You have found all three clues. Time to make an accusation!\n");
            int result = accuse(suspect, weapon, location, guiltySuspect, guiltyWeapon, guiltyLocation);
            if (result)
            {
                printf("Congratulations! You have solved the murder mystery and won the game!\n");
                return 0;
            }
            else
            {
                printf("Your accusation is incorrect! You are out of the game.\n");
            }
        }

        //Switch player
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }

    return 0;
}

/**
 * Function to print the game board
 * @param board The 2D array representing the board
 * @param row The number of rows
 * @param col The number of columns
 */
void printBoard(char board[][3], int row, int col)
{
    printf("\n -------------------------------------\n");
    for (int i = 0; i < row; i++)
    {
        printf("|");
        for (int j = 0; j < col; j++)
        {
            printf("\t%c\t|", board[i][j]);
        }
        printf("\n -------------------------------------\n");
    }
}

/**
 * Function to roll a dice and generate a random number between 1 and 6
 * @return The number rolled on the dice
 */
int rollDice()
{
    srand(time(NULL));
    return (rand() % 6) + 1;
}

/**
 * Function to move the player through the board and check if clues or suspects were found
 * @param board The 2D array representing the board
 * @param rowPos The current row position of the player
 * @param colPos The current column position of the player
 * @param roll The number rolled on the dice
 * @param suspectFound Pointer to variable that tracks if suspect was found
 * @param weaponFound Pointer to variable that tracks if weapon was found
 * @param locationFound Pointer to variable that tracks if location was found
 * @param suspect Pointer to variable that will store the name of the found suspect
 * @param weapon Pointer to variable that will store the name of the found weapon
 * @param location Pointer to variable that will store the name of the found location
 */
void movePlayer(char board[][3], int *rowPos, int *colPos, int roll, int *suspectFound, int *weaponFound, int *locationFound, char *suspect, char *weapon, char *location)
{
    int currentRow = *rowPos;
    int currentCol = *colPos;

    //Check if player is on a trap
    if (board[currentRow][currentCol] == 'G')
    {
        printf("Oh no! You landed on a trap. Miss a turn.\n");
        return;
    }

    //Move player
    while (roll > 0)
    {
        if (currentRow == 0 && currentCol == 0)
        {
            printf("You have reached the end of the board. Go back.\n");
            currentCol++;
        }
        else if (currentRow == 0 && currentCol == 2)
        {
            printf("You have reached the end of the board. Go back.\n");
            currentCol--;
        }
        else if (currentRow == 1 && currentCol == 2)
        {
            printf("You have reached the end of the board. Go back.\n");
            currentRow--;
        }
        else if (currentRow == 1 && currentCol == 0)
        {
            printf("You have reached the end of the board. Go back.\n");
            currentRow++;
        }
        else
        {
            currentCol = (currentRow % 2 == 0) ? currentCol - 1 : currentCol + 1;
            currentRow = (currentRow % 2 == 0) ? currentRow - 1 : currentRow + 1;
        }
        roll--;
    }

    *rowPos = currentRow;
    *colPos = currentCol;

    //Check if player landed on a room
    if (board[currentRow][currentCol] != ' ')
    {
        printf("You have landed on room %c!\n", board[currentRow][currentCol]);

        //Determine if player found a clue or a suspect
        int result = searchRoom(&board[currentRow][currentCol]);
        if (result == 1) //Found a clue
        {
            printClue(&board[currentRow][currentCol]);
            if (strcmp(&board[currentRow][currentCol], "H") == 0)
            {
                *locationFound = 1;
                strcpy(location, "Baker Street");
            }
            else if (strcmp(&board[currentRow][currentCol], "E") == 0)
            {
                *weaponFound = 1;
                strcpy(weapon, "Revolver");
            }
            else if (strcmp(&board[currentRow][currentCol], "A") == 0)
            {
                *suspectFound = 1;
                strcpy(suspect, "Colonel Moran");
            }
        }
        else if (result == 2) //Found a suspect
        {
            printf("You have found a suspect! It's Colonel Moran!\n");
            *suspectFound = 1;
            strcpy(suspect, "Colonel Moran");
        }
    }
}

/**
 * Function to search the room for a clue or a suspect
 * @param room The character representing the room on the board
 * @return 1 if a clue was found, 2 if a suspect was found, 0 otherwise
 */
int searchRoom(char *room)
{
    srand(time(NULL));
    int chance = rand() % 3;
    if (chance == 0)
    {
        printf("You didn't find anything in the room.\n");
        return 0;
    }
    else if (chance == 1)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

/**
 * Function to print the clue found in a room
 * @param room The character representing the room on the board
 */
void printClue(char *room)
{
    if (strcmp(room, "B") == 0)
    {
        printf("You found a picture of Colonel Moran.\n");
    }
    else if (strcmp(room, "C") == 0)
    {
        printf("You found a letter from Moriarty talking about Baker Street.\n");
    }
    else if (strcmp(room, "D") == 0)
    {
        printf("You found a bullet casing from a revolver.\n");
    }
    else if (strcmp(room, "F") == 0)
    {
        printf("You found a note with 'Revolver' written on it.\n");
    }
    else if (strcmp(room, "G") == 0)
    {
        printf("You found a picture of Baker Street.\n");
    }
    else if (strcmp(room, "H") == 0)
    {
        printf("You found a map of the city with Baker Street circled.\n");
    }
}

/**
 * Function to make an accusation and determine if it is correct or not
 * @param suspect The name of the accused suspect
 * @param weapon The name of the accused weapon
 * @param location The name of the accused location
 * @param guiltySuspect The name of the guilty suspect
 * @param guiltyWeapon The name of the guilty weapon
 * @param guiltyLocation The name of the guilty location
 * @return 1 if accusation is correct, 0 if incorrect
 */
int accuse(char suspect[], char weapon[], char location[], char *guiltySuspect, char *guiltyWeapon, char *guiltyLocation)
{
    if (strcmp(suspect, guiltySuspect) == 0 && strcmp(weapon, guiltyWeapon) == 0 && strcmp(location, guiltyLocation) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}