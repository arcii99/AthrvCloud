//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Size of Airport Baggage Handling System
#define ROW_SIZE 5
#define COLUMN_SIZE 5

//Function to display the current status of the airport baggage handling system
void display(char airport_system[][COLUMN_SIZE])
{
    printf("Current Airport Baggage Handling System Status:\n");
    for (int i = 0; i < ROW_SIZE; i++)
    {
        for (int j = 0; j < COLUMN_SIZE; j++)
        {
            printf("%c ", airport_system[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

//Function to check if the given row and column indices are within the bounds
bool is_within_bounds(int row, int column)
{
    return row >= 0 && row < ROW_SIZE && column >= 0 && column < COLUMN_SIZE;
}

//Function to move a baggage from one point to another in the airport system
void move_baggage(char airport_system[][COLUMN_SIZE], int source_row, int source_column, int destination_row, int destination_column)
{
    char baggage = airport_system[source_row][source_column];
    airport_system[source_row][source_column] = '-';
    airport_system[destination_row][destination_column] = baggage;
    printf("Moved baggage from (%d,%d) to (%d,%d)\n", source_row, source_column, destination_row, destination_column);
    display(airport_system);
}

int main()
{
    //Initializing the Airport Baggage Handling System
    char airport_system[ROW_SIZE][COLUMN_SIZE] = {
        {'B', '-', '-', '-', 'A'},
        {'-', '-', '-', '-', '-'},
        {'-', 'C', '-', 'D', '-'},
        {'-', '-', 'E', '-', '-'},
        {'F', '-', '-', '-', 'G'},
    };

    //Displaying the initial status of the system
    printf("Airport Baggage Handling System Initialized:\n");
    display(airport_system);

    //Moving a baggage from point A to point E
    int source_row = 0, source_column = 4, destination_row = 3, destination_column = 2;
    if (is_within_bounds(source_row, source_column) && is_within_bounds(destination_row, destination_column))
    {
        move_baggage(airport_system, source_row, source_column, destination_row, destination_column);
    }
    else
    {
        printf("Invalid source or destination point. Please try again.\n");
    }

    //Moving a baggage from point C to point B
    source_row = 2, source_column = 1, destination_row = 0, destination_column = 1;
    if (is_within_bounds(source_row, source_column) && is_within_bounds(destination_row, destination_column))
    {
        move_baggage(airport_system, source_row, source_column, destination_row, destination_column);
    }
    else
    {
        printf("Invalid source or destination point. Please try again.\n");
    }

    //Moving a baggage from point F to point D
    source_row = 4, source_column = 0, destination_row = 2, destination_column = 3;
    if (is_within_bounds(source_row, source_column) && is_within_bounds(destination_row, destination_column))
    {
        move_baggage(airport_system, source_row, source_column, destination_row, destination_column);
    }
    else
    {
        printf("Invalid source or destination point. Please try again.\n");
    }

    return 0;
}